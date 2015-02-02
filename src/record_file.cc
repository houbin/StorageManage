#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "record_file.h"
#include "index_file.h"
#include "../util/clock.h"
#include "../util/coding.h"

using namespace util;

namespace storage
{

RecordFile::RecordFile(Logger *logger, string base_name, uint32_t number)
: logger_(logger), base_name_(base_name), number_(number), fd_(-1), locked_(false),
state_(kCleared), record_fragment_count_(0), start_time_(0), end_time_(0), record_offset_(0)
{

}

int32_t RecordFile::Clear()
{
    Log(logger_, "clear index");

    /* 清零内存中的数据 */
    this->fd_ = -1;
    this->stream_info_.clear();
    this->locked_ = false;
    this->state_= kCleared;
    this->record_fragment_count_ = 0;
    UTime temp(0, 0);
    this->start_time_ = temp;
    this->end_time_ = temp;
    this->i_frame_start_time_ = temp;
    this->i_frame_end_time_ = temp;
    this->record_offset_ = 0;

    return 0;
}

bool RecordFile::CheckRecycle()
{
    Log(logger_, "check recycle");

    if (state_ != kIdle && locked_ == true)
    {
        return false;
    }

    return true;
}

int32_t RecordFile::EncodeRecordFileInfoIndex(char *record_file_info_buffer, uint32_t record_file_info_length)
{
    Log(logger_, "encode record file info index");

    struct RecordFileInfo record_file_info;
    char *temp = record_file_info_buffer;

    uint32_t length = record_file_info_length - sizeof(record_file_info.length) - sizeof(record_file_info.crc);
    EncodeFixed32(temp, length);
    temp += sizeof(record_file_info.length);
    temp += sizeof(record_file_info.crc);

    char *crc_start = temp;

    memcpy(temp, stream_info_.c_str(), stream_info_.length());
    temp += sizeof(record_file_info.stream_info);

    *temp = locked_;
    temp += sizeof(record_file_info.locked);

    *temp = state_;
    temp += sizeof(record_file_info.state);

    *temp = record_fragment_count_ & 0xff;
    *(temp+1) = record_fragment_count_ >> 8
    temp += sizeof(record_file_info.record_fragment_counts);

    EncodeFixed32(temp, start_time_.tv_sec);
    temp += 4;
    EncodeFixed32(temp, start_time_.tv_nsec);
    temp += 4;

    EncodeFixed32(temp, end_time_.tv_sec);
    temp += 4;
    EncodeFixed32(temp, end_time_.tv_nsec);
    temp += 4;

    EncodeFixed32(temp, i_frame_start_time_.tv_sec);
    temp += 4;
    EncodeFixed32(temp, i_frame_start_time_.tv_nsec);
    temp += 4;

    EncodeFixed32(temp, i_frame_end_time_.tv_sec);
    temp += 4;
    EncodeFixed32(temp, i_frame_end_time_.tv_nsec);
    temp += 4;

    EncodeFixed32(temp, record_offset_);
    temp += 4;

    uint32_t crc = crc32c::Value(crc_start, length);
    EncodeFixed32(crc_start - 4, crc);

    return 0;
}

int32_t RecordFile::EncodeRecordFragInfoIndex(char *record_frag_info_buffer, uint32_t record_frag_info_length)
{
    Log(logger_, "encode record frag info index");

    struct RecordFragmentInfo record_frag_info;
    char *temp = record_frag_info_buffer;
    
    uint32_t length = record_frag_info_length - sizeof(record_frag_info.length) - sizeof(record_frag_info.crc);
    temp += sizeof(record_frag_info.length);
    temp += sizeof(record_frag_info.crc);

    char *crc_start = temp;

    EncodeFixed32(temp, start_time_.tv_sec);
    temp += 4;
    EncodeFixed32(temp, start_time_.tv_nsec);
    temp += 4;

    EncodeFixed32(temp, end_time_.tv_sec);
    temp += 4;
    EncodeFixed32(temp, end_time_.tv_nsec);
    temp += 4;

    EncodeFixed32(temp, i_frame_start_time_.tv_sec);
    temp += 4;
    EncodeFixed32(temp, i_frame_start_time_.tv_nsec);
    temp += 4;

    EncodeFixed32(temp, i_frame_end_time_.tv_sec);
    temp += 4;
    EncodeFixed32(temp, i_frame_end_time_.tv_nsec);
    temp += 4;

    uint32_t crc = crc32c::Value(crc_start, length);
    EncodeFixed32(crc_start - 4, crc);

    return 0;
}

int32_t RecordFile::BuildIndex(char *record_file_info_buffer, uint32_t record_file_info_length, char *record_frag_info_buffer,
                                uint32_t record_frag_info_length, uint32_t *record_frag_number)
{
    Log(logger_, "build index");

    EncodeRecordFileInfoIndex(record_file_info_buffer, record_file_info_length);
    EncodeRecordFragInfoIndex(record_frag_info_buffer, record_frag_info_length);
    *record_frag_number = record_fragment_count_;

    return 0;
}

int32_t RecordFile::Append(String &buffer, uint32_t length, BufferTimes &times)
{
    int ret;
    Log(logger_, "write stream %s , length %d", buffer.c_str(), length);

    assert(fd_ < 0);
    if (fd_ == 0)
    {
        char buffer[32] = {0};
        snprintf(buffer, 32, "record_%05d", number_);

        string record_file_path(base_name_);
        record_file_path.append(buffer);

        fd_ = open(record_file_path.c_str(), O_RDWR);
        assert(fd_ > 0);
        lseek(fd_, record_offset_, SEEK_SET);
    }
    
    ret = write(fd_, buffer.c_str(), length);
    assert(ret == length);
    fdatasync(fd_);

    if (state_ != kWriting)
    {
        state_ = kWriting;
        record_fragment_count_ += 1;
    }

    /* update times */
    if((start_time_ == 0) && (update.start_time != 0))
    {
        start_time_ = update.start_time;
    }

    if ((i_frame_start_time_ == 0) && (update.i_frame_start_time != 0))
    {
        i_frame_start_time_ = update.i_frame_start_time;
    }

    if (end_time_ < update.end_time)
    {
        end_time_ = update.end_time;
    }

    if (i_frame_end_time_ < update.i_frame_end_time)
    {
        i_frame_end_time_ = update.i_frame_end_time;
    }

    record_offset_ += length;

    return 0;
}

int32_t RecordFile::FinishWrite()
{
    Log(logger_, "finish write");
    
    if (fd_ > 0)
    {
        close(fd_);
        fd_ = -1;
    }
    state_ = kIdle;

    return 0;
}

int32_t RecordFile::DecodeHeader(char *header, FRAME_INFO_T *frame)
{
    assert(header != NULL);
    assert(frame != NULL);
    Log(logger_, "decode header");
    
    char *temp = header;

    uint32_t magic_code = DecodeFixed32(temp);
    temp += 4;
    if (magic_code != kMagicCode)
    {
        return -ERR_NO_MAGIC_CODE;
    }

    frame->type = DecodeFixed32(temp);
    temp += 4;

    frame->frame_time.seconds = DecodeFixed32(temp);
    temp += 4;

    frame->frame_time.nseconds = DecodeFixed32(temp);
    temp += 4;

    frame->stamp = DecodeFixed64(temp);
    temp += 8;

    frame->size = DecodeFixed32(temp);
    temp += 4;

    return 0;
}

int32_t RecordFile::GetStampOffset(UTime &stamp, uint32_t *offset)
{
    Log(logger_, "get stamp offset");
    uint32_t ret = 0;
    uint32_t stamp_offset = 0;

    if (fd_ < -1)
    {
        fd_ = open(record_file_path.c_str(), O_RDWR);
        assert(fd_ > 0);
    }

    while(stamp_offset < record_offset_)
    {
        char header[kHeaderSize] = {0};
        FRAME_INFO_T frame = {0};
        
        ret = pread(fd_, header, kHeaderSize, stamp_offset);
        assert(ret == kHeaderSize);

        ret = DecodeHeader(header, &frame);
        if (ret != 0)
        {
            return ret;
        }

        if (frame->frame_time >= stamp)
        {
            *offset = stamp_offset;
            return 0;
        }

        stamp_offset += kHeaderSize;
        stamp_offset += frame->size;
    }

    if (stamp_offset >= record_offset_)
    {
        assert("?" != 0);
    }

    return 0;
}

}

