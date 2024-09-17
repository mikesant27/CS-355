#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define DELAY 30000

int main(int ac, char *av[]){
    int x = 0, y = 0;
    int max_y = 0, max_x = 0;
    int next_x = 0,next_y = 0;
    int directionX = 1;

    initscr();
    noecho();
    curs_set(FALSE);

    getmaxyx(stdscr,max_y,max_x);

    while(1){
        clear();
        mvprintw(y,x,"o");
        refresh();

        usleep(DELAY);

        next_x = x + directionX;
        
        if(next_x >= max_x || next_x < 0)
            directionX *= -1;
        else
            x += directionX;
            
        endwin();
    }
}