#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handleInterrupt(int signum){
    printf("You Pressed Ctrl+C!\n");
}

int main(){
    signal(SIGINT,handleInterrupt);

    while(1){

    }
    return 0;
}