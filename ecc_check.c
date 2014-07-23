#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
 
 
#define MEM_START       0xFED10000
#define FILESIZE        32*1024
 
int main(int argc, char *argv[])
{
    int i;
    int fd = -1;
        unsigned long pagesize;
    unsigned char *map;
        unsigned char *mem;
 
    fd = open("/dev/mem", O_RDONLY|O_SYNC);
    if (fd == -1) {
                perror("Error opening /dev/mem for reading");
                exit(EXIT_FAILURE);
    }
 
    map = mmap(0, FILESIZE, PROT_READ, MAP_SHARED, fd, MEM_START);
    if (map == MAP_FAILED) {
                close(fd);
                perror("Error mmapping the file");
                exit(EXIT_FAILURE);
    }
   
        // Get RAM info
        printf("5004-5007h: ");
        for (i = 0x5004; i < 0x5004+4; i++) {
                printf("%lx ", map[i]);
        }
        printf("\n");
 
        printf("5008-500Bh: ");
        for (i = 0x5008; i < 0x5008+4; i++) {
                printf("%lx ", map[i]);
        }
        printf("\n");
 
        // Unmap the file
    if (munmap(map, FILESIZE) == -1) {
                perror("Error un-mmapping the file");
    }
 
    close(fd);
    return 0;
}
