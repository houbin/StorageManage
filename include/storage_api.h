#ifndef STORAGE_INCLUDE_C_
#define STORAGE_INCLUDE_C_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/* ������1970��1��1��00:00:00������������������ */
typedef struct utime
{
    uint32_t seconds;   
    uint32_t nseconds;    
}UTIME_T;

/* ����ĳһ��Ƶ����Ӧ��¼�����Ϣ */
typedef struct fragment_info
{
    UTIME_T start_time;
    UTIME_T end_time;
}FRAGMENT_INFO_T;

typedef struct frame_info
{
    uint32_t type;      // ֡����
    UTIME_T frame_time; // ����ʱ�䣬���ڱ�ʾ֡��ʱ��
    uint64_t stamp;     // ���ʱ��������ڿ���֡�Ĳ���
    uint32_t size;      // ֡����
    char *buffer;       // ֡����
}FRAME_INFO_T;

typedef struct disk_info
{
    char name[32];
    uint32_t capacity;
    char status[32];
}DISK_INFO_T;

/* ���ܣ� ��ȡ������Ϣ
 * ���룺 disk ��������
 *
 * ����� disk_info ��ȡ�Ĵ�����Ϣ
 * ���أ� �ɹ�����0��ʧ�ܷ��ظ���
 */
extern int32_t storage_get_disk_info(char *disk, DISK_INFO_T *disk_info);

/* ���ܣ� ��ʽ��һ�����
 * ���룺 disk  ��������
 *
 * ����� ��
 * ���أ� �ɹ�����0��ʧ�ܷ��ظ���
 */
extern int32_t storage_formate_disk(char *disk);

/* ���ܣ� ��ʼ��storageģ�� 
 * ���룺   ��
 *
 * �����   ��
 * ���أ�   ��
 */
extern void storage_init();

/* ���ܣ� ͨ��stream info�Ͷ�д��־��ȡ��Ƶ������id����ȡ��Ƶ���������Դ򿪶�Σ�д��Ƶ������ֻ�ܴ�һ��
 * ���룺   stream_info     ��Ƶ����Ϣ
 *          size            ��Ƶ����Ϣ���ȣ��������64���ֽ�
 *          flag            �����ı�־��������д��
 *                          0 �� 
 *                          1 д
 *
 * �����   id              ��Ƶ������id
 *          
 * ���أ� �ɹ�����0��ʧ�ܷ��ظ���
 */
extern int32_t storage_open(char *stream_info, uint32_t size, int flags, uint32_t *id);

/* ���ܣ� ͨ��idд�����ݣ�
 * ���룺   id          ��������id
 *          frame_info  ��Ƶ��������
 *
 * ���أ� �ɹ�����0��ʧ�ܷ��ظ���
 */
extern int32_t storage_write(const uint32_t id, FRAME_INFO_T *frame_info);

/* ���ܣ� ��ȡָ��ʱ��ε�¼�����Ϣ�б�
 * ���룺   id          ��������Ƶ��id
 *          start       ��ʼʱ��
 *          end         ����ʱ��
 *          frag_info   ¼�������ͷָ��
 *          
 * �����   frag_info   ��ȡ��¼�������ͷָ��
 *          count       ¼��θ���
 *
 * ���أ� �ɹ�����0��ʧ�ܷ��ظ���
 */
extern int32_t storage_list_record_fragments(const uint32_t id, const UTIME_T *start, const UTIME_T *end, FRAGMENT_INFO_T **frag_info, uint32_t *count);

/* ���ܣ� �ͷ�¼����ڴ�
 * ���룺   frag_info   ¼�������ͷָ��
 *
 * ���أ� �ɹ�����0��ʧ�ܷ��ظ���
 */
extern void storage_free_record_fragments(FRAGMENT_INFO_T *frag_info);

/* ���ܣ� ��ȡ¼������ʱ��seek��ĳһʱ��
 * ���룺   id      ��������Ƶ��id
 *          stamp   ��Ҫseek����ʱ��
 *
 * ���أ� �ɹ�����0��ʧ�ܷ��ظ���
 */
extern int32_t storage_seek(const uint32_t id, const UTIME_T *stamp);

/* ���ܣ� ��ȡ��Ƶ������
 * ���룺   id      ��������Ƶ��id
 *          
 * �����   frame_info  ��ȡ����Ƶ֡���ݣ������õ����ڴ��ɵ���������
 *           
 * ���أ� ��ȡ���ֽ�����0��ʾû�ж������ݣ���ʧ�ܷ��ظ���
 */
extern int32_t storage_read(const uint32_t id, FRAME_INFO_T *frame_info);

/* ���ܣ� �ر���Ƶ��id
 * ���룺   id ��Ҫ�رյ���Ƶ������id
 *
 * �����   ��
 * ���أ�   ��
 */
extern void storage_close(const uint32_t id);

/* ���ܣ� �ر�storageģ��
 * ���룺
 *
 * �����   ��
 * ���أ�   ��
 */
extern void storage_shutdown();


#ifdef __cplusplus
}
#endif

#endif
