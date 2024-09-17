#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void ouch(int);

int ouch_count = 0;

void long_loop(){
    for(int i = 0; i < 10; i++){
        printf("Hello %d\n",i);
        sleep(1);
    }
}

int main(){
    signal(SIGINT, ouch);
    long_loop();
}

void ouch(int signum){
    printf("---OUCH!!!\n");
    ouch_count++;
    if(ouch_count>=3){
        printf("You are killing me...\n");
        signal(SIGINT,SIG_DFL);
        raise(SIGINT);
    }
}