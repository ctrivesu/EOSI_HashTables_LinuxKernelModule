#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <pthread.h>
#include <sched.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

//HASH TABLE OBJECT
typedef struct ht_object
{
    int key;
    int data ;
} ht_object_t;

int main()
{
        int fd_write_1;
        int ret;

        ht_object_t *ht_node, *ht1_data;
        ht_node = (ht_object_t *) malloc(sizeof(ht_object_t));
        ht1_data = (ht_object_t *) malloc(sizeof(ht_object_t));
        

        fd_write_1 = open("/dev/ht530-1",O_RDWR);
        
        int elem_delete;

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
        
        elem_delete = 70;

        ht1_data->key = elem_delete;
        ret = read(fd_write_1, ht1_data, sizeof(ht_object_t));
        printf("ht530-1: OPENED: %d, READRET: %d, BUFFER: %d %d\n", fd_write_1, ret, ht1_data->data, ht1_data->key);
        

        ht_node->data = 0;
        ht_node->key = elem_delete;
        ret = write(fd_write_1, ht_node, sizeof(ht_object_t));
        printf("ht530-1: OPENED: %d, DATA TO WRITE: %d %d\n", fd_write_1, ht_node->data, ht_node->key);

        ht1_data->key = elem_delete;
        ret = read(fd_write_1, ht1_data, sizeof(ht_object_t));
        printf("ht530-1: OPENED: %d, READRET: %d, BUFFER: %d %d\n", fd_write_1, ret, ht1_data->data, ht1_data->key);
        close(fd_write_1);
        
        return 0;


}