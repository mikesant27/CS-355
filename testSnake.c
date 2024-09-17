#include <stdio.h>
#include <curses.h>
#include <unistd.h>

int score = 0;                                                                // Store score of current game
int highScore = 0;                                                            // Store overall high score
char credits[] = "Created by: Michael Santoro, Bradley Morales, Ryan Tyimok"; // String to hold credits
int maxY,maxX;     // Store dimentions of the screen

typedef struct{
    int x;
    int y;
} snake;


void refreshBoard();
void initGame();
bool isGameOver();

int main(){
    initscr();  // Initialize curses library
    initGame(); // Initialize the game
    
    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);
    
    //creation of snake
    snake head = {0, 0}; 
    snake direction = {1,0};
    
    while(true){
        int input = getch();
        
        if(input == KEY_UP){
            direction.x = 0;
            direction.y = -1;
        }
        if(input == KEY_DOWN){
            direction.x = 0;
            direction.y = 1;
        }
        if(input == KEY_RIGHT){
            direction.x = 1;
            direction.y = 0;
        }
        if(input == KEY_LEFT){
            direction.x = -1;
            direction.y = 0;
        }
        else{
            break;
        }
        
        head.x += direction.x;
        head.y += direction.y;
        
        refreshBoard();
        
        mvaddch(head.y, head.x, '@');
        
        usleep(125000);
    }
    //getch();    // Wait for user to input something before continuing
    endwin();   // Turn off curses library
    return 0;
}

// Primary Author: Michael Santoro
// Initialize the game, reset variables, and print border/credits
void initGame(){
    score = 0;                            // Reset score
    clear();                              // Reset the Screen
    getmaxyx(stdscr,maxY,maxX);           // Get the bounds of the screen and store it in maxY and maxX

    // Prints title and credits of game
    int centerX = maxX/2;                 // Get center of screen (x axis)
    move(0,centerX-2);                    // Move cursor to center - offset where offset = "snake"'s length/2
    addstr("Snake");                      // Print the String
    move(1,centerX-(sizeof(credits)/2));  // Move cursor to center - offset of credits string
    addstr(credits);                      // Print the String

    // Draws the border of the board with a 1 character border
    // between the edge of the terminal and border of the snake pit
    for(int i = 2; i < maxY - 2; i++){
        for(int j = 2; j < maxX - 2; j++){
            if(i == 2 || j == 2|| i == maxY-3 || j == maxX-3){
                move(i,j);
                addch('#');
            }
        }
    }
    refreshBoard();                      // Call refreshBoard
}

// Primary Author: 
// Redraws the board and refreshes the screen to show changes in snake, fruits, and score
void refreshBoard(){

    // Prints the player's score
    move(maxY - 2,2);        // Move cursor to bottom left corner
    addstr("Score:");        // Print the score label
    printw("%d",score);      // Print the score

    // Prints the High Score
    move(maxY - 2,maxX-14);  // Move cursor to bottom left corner
    addstr("High Score:");   // Print the score label
    printw("%d",highScore);  // Print the score


    refresh();
}

// Primary Author:
// Check if game over conditions have been met, returns true if game is over, and false if game is not over
bool isGameOver(){

}

/*
       Diagram of the Screen
(0,0)                      (0,COLUMNS-1)







(LINES-1,0)               (LINES-1,COLUMNS-1)

*/