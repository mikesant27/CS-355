#include <stdio.h>
#include <termios.h>

int main(){
    struct termios info;
    int rv;

    rv = tcgetattr(0,&info);

    if(rv == -1){
        perror("tcgetattr");
        return 0;
    }
    if(info.c_lflag & ECHO)
        printf("Echo is on, since its bit is 1\n");
    else
        printf("Echo is off, since its bit is 0\n");

    return 0;
}