#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <pthread.h>
#include <sched.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#define DUMP _IOWR(530,0, struct dump_arg)


//HASH TABLE OBJECT
typedef struct ht_object
{
    int key;
    int data ;
} ht_object_t;

//IOCTL STRUCT
struct dump_arg 
{
    int n;                          //Bucket number N
    ht_object_t object_array[8];    //8 objects to retrieve
};

int main()
{
        int fd_write_1, ret;
        ht_object_t *ht_node;
        ht_node = (ht_object_t *) malloc(sizeof(ht_object_t));
        fd_write_1 = open("/dev/ht530-1",O_RDWR);

        ht_node->data = 1;
        ht_node->key = 303;
        ret = write(fd_write_1, ht_node, sizeof(ht_object_t));
        printf("ht530-1: OPENED: %d, DATA TO WRITE: %d %d\n", fd_write_1, ht_node->data, ht_node->key);

        ht_node->data = 2;
        ht_node->key = 21;
        ret = write(fd_write_1, ht_node, sizeof(ht_object_t));
        printf("ht530-1: OPENED: %d, DATA TO WRITE: %d %d\n", fd_write_1, ht_node->data, ht_node->key);        
        
        ht_node->data = 3;
        ht_node->key = 70;
        ret = write(fd_write_1, ht_node, sizeof(ht_object_t));
        printf("ht530-1: OPENED: %d, DATA TO WRITE: %d %d\n", fd_write_1, ht_node->data, ht_node->key);



        struct dump_arg* d_arg = (struct dump_arg*) malloc(sizeof(struct dump_arg));
        
        d_arg->n = 94;
        ret = ioctl(fd_write_1, DUMP, d_arg);
        printf("ht530-1: IOCTL ret: %d\n", ret);
        close(fd_write_1);
        
        return 0;


}