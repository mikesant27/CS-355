#include <stdio.h>
#include <sys/stat.h>

int main(){
    struct stat infobuf; 

    if(stat("C:/Users/Michael/Downloads/CCSU/Spring 2024/CS 355/C Files/ICA3part1.c",&infobuf) == -1)
        perror("C:/Users/Michael/Downloads/CCSU/Spring 2024/CS 355/C Files/ICA3part1.c");
    else   
        printf("The size of the C:/Users/Michael/Downloads/CCSU/Spring 2024/CS 355/C Files/ICA3part1.c is %d\n",infobuf.st_size);
}