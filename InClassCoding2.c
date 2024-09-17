#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd, inode;
    fd = open("/Homework5.c", O_RDONLY);

    if(fd < 0){
        // Some error occured while opening the file
    }

    struct stat file_stat;
    int ret;
    ret = fstat(fd, &file_stat);
    if(ret < 0){
        // error getting file stat
    }

    inode = file_stat.st_ino;

    return 1;
}