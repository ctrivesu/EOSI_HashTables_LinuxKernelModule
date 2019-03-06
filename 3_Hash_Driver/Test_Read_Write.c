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
        int fd_write_1;
        int ret=0;
        int i,j;
        struct dump_arg* darg;
        ret ++;
        
        ht_object_t *ht_node;//, *ht1_data;
        ht_node = (ht_object_t *) malloc(sizeof(ht_object_t));
   

        fd_write_1 = open("/dev/ht530-2",O_RDWR);

        j=0;
        printf("\nIOCTL: HASH TABLE\n");
        while(j<128) 
        {
            //darg = (struct dump_arg*) malloc(sizeof(struct dump_arg));
            darg = (struct dump_arg*) calloc(1, sizeof(struct dump_arg));
            darg->n = j;
            printf("IOCTL BUCKET:%3d|", j);

            ioctl(fd_write_1, DUMP, darg);
            
            for(i = 0; i < 8; ++i) 
            {
              printf("%d K(%3d) D(%3d)|", i+1, darg->object_array[i].key, darg->object_array[i].data);
            }
            printf("\n");
            j++;
            free(darg);
        }
        
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

        j=0;
        printf("\nIOCTL: HASH TABLE\n");
        while(j<128) 
        {
            //darg = (struct dump_arg*) malloc(sizeof(struct dump_arg));
            darg = (struct dump_arg*) calloc(1, sizeof(struct dump_arg));
            darg->n = j;
            printf("IOCTL BUCKET:%3d|", j);

            ioctl(fd_write_1, DUMP, darg);
            
            for(i = 0; i < 8; ++i) 
            {
              printf("%d K(%3d) D(%3d)|", i+1, darg->object_array[i].key, darg->object_array[i].data);
            }
            printf("\n");
            j++;
            free(darg);
        }

        int elem_delete;
        elem_delete = 303;
        ht_node->data = 0;
        ht_node->key = elem_delete;
        ret = write(fd_write_1, ht_node, sizeof(ht_object_t));
        printf("ht530-1: OPENED: %d, DATA TO WRITE: %d %d\n", fd_write_1, ht_node->data, ht_node->key);

        j=0;
        printf("\nIOCTL: HASH TABLE\n");
        while(j<128) 
        {
            //darg = (struct dump_arg*) malloc(sizeof(struct dump_arg));
            darg = (struct dump_arg*) calloc(1, sizeof(struct dump_arg));
            darg->n = j;
            printf("IOCTL BUCKET:%3d|", j);

            ioctl(fd_write_1, DUMP, darg);
            
            for(i = 0; i < 8; ++i) 
            {
              printf("%d K(%3d) D(%3d)|", i+1, darg->object_array[i].key, darg->object_array[i].data);
            }
            printf("\n");
            j++;
            free(darg);
        }

        close(fd_write_1);
        return 0;
}