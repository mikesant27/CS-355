// Michael Santoro
// CS 355
// Homework 8

#include <stdlib.h>
#include <curses.h>
#include <signal.h>

static void finish(int sig);

int main(int argc, char *argv[]){
    int num = 0;

    (void) signal(SIGINT,finish);
    (void) initscr();
    keypad(stdscr, TRUE);
    (void) nonl();
    (void) cbreak();
    (void) echo();

    // Check if the terminal supports colors
    if(has_colors()){
        start_color(); // Start color if the terminal supports it

        // Initiate color pairs
        init_pair(1,COLOR_RED,COLOR_BLACK);
        init_pair(2,COLOR_GREEN,COLOR_BLACK);
        init_pair(3,COLOR_YELLOW,COLOR_BLACK);
        init_pair(4,COLOR_BLUE,COLOR_BLACK);
        init_pair(5,COLOR_CYAN,COLOR_BLACK);
        init_pair(6,COLOR_MAGENTA,COLOR_BLACK);
        init_pair(7,COLOR_WHITE,COLOR_BLACK);

    }

    // Get user input and display it using the corresponding color using num
    for(;;){
        int c = getch();
        attrset(COLOR_PAIR(num % 8));
        num++;
    }

    finish(0);
}

// ends the window when the user does ctrl + c
static void finish(int sig){
    endwin();
    exit(0);
}

/*
This program takes in user input through getch() and prints that character in color. 
This color changes with every character typed because of num % 8. The result is the string being typed
being colored as a rainbow, starting with red, then green, yellow, blue, cyan, magenta, and then white.
Additionally, we can exit the program by pressing ctrl+c, which using the signal, calls the finish function 
which ends the window.
*/