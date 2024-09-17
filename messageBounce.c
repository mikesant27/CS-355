#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include <unistd.h>

int maxLine, maxCol;

void handleInterrupt(int sig){
    endwin();
    exit(0);
}

int main(){
    initscr();
    getmaxyx(stdscr,maxLine,maxCol);

    signal(SIGINT,handleInterrupt);

    int line = maxLine / 2;
    int dir = 1;

    while(1){
        clear();

        move(line, maxCol/2);
        printw("Hello World!");
        refresh();

        usleep(200000);

        line += dir;

        if(line <= 0 || line >= maxLine - 1)
            dir *= -1;
    }
    endwin();
    return 0;
}