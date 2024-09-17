#include <stdio.h>
#include <curses.h>

int main(){
    initscr();
    start_color();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);

    move(0,0);
    attron(COLOR_PAIR(1));
    printw("bmorales@LAPTOP-UPFREHNL");
    attroff(COLOR_PAIR(1));
    printw(":");
    attron(COLOR_PAIR(2));
    printw("~/Desktop");
    attroff(COLOR_PAIR(2));
    printw("$ ./test");
    getch();

    endwin();
    return 0;
}