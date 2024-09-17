#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd = open("file.txt",O_RDONLY);

    if(fd == -1){
        perror("Failted to open file.txt!");
        return 0;
    }
    else{
        printf("Sucessfully opened file.txt!");
        close(fd);
    }
    return 0;
}