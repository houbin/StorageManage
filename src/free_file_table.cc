#include <stdlib.h>
#include "free_file_table.h"
#include "config_opts.h"
#include "../include/storage.h"
#include "index_file.h"

namespace storage
{

FreeFileTable::FreeFileTable(Logger *logger)
: logger_(logger), mutex_("FreeFileTable::Lock")
{

}

int32_t FreeFileTable::Put(RecordFile *record_file)
{
    assert(record_file != NULL);
    Log(logger_, "put record file %p", record_file);

    int32_t ret;
    DiskInfo *disk_info = NULL;

    Mutex::Locker lock(mutex_);

    string disk_base_name(record_file->base_name_);
    map<string, DiskInfo*>::iterator iter = disk_free_file_info_.find(disk_base_name);
    if (iter == disk_free_file_info_.end())
    {
        disk_info = new struct DiskInfo;
        assert(disk_info != NULL);
        disk_free_file_info_.insert(make_pair(disk_base_name, disk_info));
        Log(logger_, "not found disk info");
    }
    else
    {
        disk_info = iter->second;
        Log(logger_, "found disk info");
    }

    assert(disk_info != NULL);

    IndexFile *index_file = NULL;
    ret = index_file_manager->Find(record_file->base_name_, &index_file);
    assert(ret == 0);
    assert(index_file != NULL);

    struct RecordFileInfo record_file_info = {0};
    int32_t write_offset = record_file->number_ * sizeof(struct RecordFileInfo);
    index_file->Write(write_offset, (char *)&record_file_info, sizeof(struct RecordFileInfo));
    record_file->Clear();

    disk_info->free_file_queue.push_back(record_file);
    cond_.Signal();

    return 0;
}

int32_t FreeFileTable::Get(string stream_info, RecordFile **record_file)
{
    assert(record_file != NULL);
    Log(logger_, "get record file");

    int32_t ret;

    Mutex::Locker lock(mutex_);
    map<string, string>::iterator stream_iter = stream_to_disk_map_.find(stream_info);
    if (stream_iter != stream_to_disk_map_.end())
    {
        string disk_str(stream_iter->second);
        map<string, DiskInfo*>::iterator disk_iter = disk_free_file_info_.find(disk_str);
        assert(disk_iter != disk_free_file_info_.end());

        DiskInfo *disk_info = disk_iter->second;
        assert(disk_info != NULL);
        if (!disk_info->free_file_queue.empty())
        {
            *record_file = disk_info->free_file_queue.front();
            disk_info->free_file_queue.pop_front();
            
            return 0;
        }
        else
        {
            // stream migrated to other disk
            disk_info->writing_streams.erase(stream_info);
        }
    }

    ret = GetNewDiskFreeFile(stream_info, record_file);
    assert(ret == 0);

    return 0;
}

int32_t FreeFileTable::GetNewDiskFreeFile(string stream_info, RecordFile **record_file)
{
    assert(record_file != NULL);
    Log(logger_, "get new disk free file, stream info is %s", stream_info.c_str());

    DiskInfo *valid_disk_info = NULL;
    string disk_str;
    while (true)
    {
        map<string, DiskInfo*>::iterator iter = disk_free_file_info_.begin();
        for (; iter != disk_free_file_info_.end(); iter++)
        {
            DiskInfo *disk_info = iter->second;
            assert(disk_info != NULL);

            uint32_t stream_counts = disk_info->writing_streams.size();
            if (stream_counts >= kMaxStreamsPerDisk)
            {
                continue;
            }

            if (disk_info->free_file_queue.empty())
            {
                continue;
            }

            disk_str = iter->first;
            valid_disk_info = disk_info;
            break;
        }

        if (valid_disk_info == NULL)
        {
            store_client_center->Recycle();
            cond_.Wait(mutex_);
        }
        else
        {
            break;
        }
    }

    // update disk info
    *record_file = valid_disk_info->free_file_queue.front();
    valid_disk_info->free_file_queue.pop_front();
    valid_disk_info->writing_streams.insert(stream_info);

    map<string, string>::iterator iter = stream_to_disk_map_.find(stream_info);
    if (iter != stream_to_disk_map_.end())
    {
        iter->second = disk_str;
    }
    else
    {
        stream_to_disk_map_.insert(make_pair(stream_info, disk_str));
    }

    return 0;
}

int32_t FreeFileTable::Close(string stream_info)
{
    Log(logger_, "close stream %s", stream_info.c_str());

    string disk_base_name;

    Mutex::Locker lock(mutex_);
    map<string, string>::iterator iter = stream_to_disk_map_.find(stream_info);
    if (iter != stream_to_disk_map_.end())
    {
        disk_base_name = iter->second;
        stream_to_disk_map_.erase(iter);

        map<string, DiskInfo*>::iterator iter = disk_free_file_info_.find(disk_base_name);
        if (iter != disk_free_file_info_.end())
        {
            DiskInfo *disk_info = iter->second;
            disk_info->writing_streams.erase(stream_info);
        }
    }

    return 0;
}

int32_t FreeFileTable::Shutdown()
{
    Log(logger_, "shutdown");

    Mutex::Locker lock(mutex_);
    while(!disk_free_file_info_.empty())
    {
        map<string, DiskInfo*>::iterator iter = disk_free_file_info_.begin();

        DiskInfo *disk_info = iter->second;
        while(!disk_info->free_file_queue.empty())
        {
            RecordFile *record_file = disk_info->free_file_queue.front();
            disk_info->free_file_queue.pop_front();
            if (record_file != NULL)
            {
                delete record_file;
                record_file = NULL;
            }
        }
        
        disk_free_file_info_.erase(iter);
        delete disk_info;
        disk_info = NULL;
    }
    
    return 0;
}

}

