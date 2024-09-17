#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>

int score = 0;                                                                // Store score of current game
int highScore = 0;                                                            // Store overall high score
int direction = 4;                                                            // Store the direction of the snake (Default 4 for Right)
char credits[] = "Created by: Michael Santoro, Bradley Morales, Ryan Tyimok"; // String to hold credits
bool gameOver = false;                                                        // Flag for if game over conditions are met

// Struct for each "Node" of the snake
struct snakeNode{
    int x,y;
};

// Struct for the snake itself
// "List of snake nodes"
struct snake{
    int length;
    struct snakeNode node[256];
};

struct snake snake;      // Creating the Snake

void refreshBoard();
void initGame();
void moveSnake();
bool isGameOver();

int main(){
    srand(time(NULL));    // Initialize seed for random
    initscr();            // Initialize curses library
    initGame();           // Initialize the game 

    endwin();             // Turn off curses library
    
    return 0;
}

// Primary Author: Ryan Tyimok
// Moves the snake by moving the head using deltaCol and deltaLines, then the rest of the snake
// Then Refreshes the board to print the new snake
void moveSnake(){
    int deltaCol;
    int deltaLines;

    // Determine the deltaCol and deltaLines based on the current direction
    switch(direction){
        case 0: // No Direction (Used for When Game is over)
            deltaCol = 0;
            deltaLines = 0;
            break;
        case 1: // UP
            deltaCol = -1;
            deltaLines =0;
            break;
        case 2: // Down  
            deltaCol = 1;
            deltaLines = 0;
            break;
        case 3: // Left
            deltaCol = 0;
            deltaLines =-1;
            break;
        case 4: // Right
            deltaCol = 0;
            deltaLines = 1;
            break;
    }

    // Moves the body of the Snake up by 1
    for(int i = snake.length - 1; i > 0; i--) {
        snake.node[i] = snake.node[i-1];
    }
    
    // Moves the head of the Snake based on deltaCol and deltaLines
    snake.node[0].x += deltaCol;
    snake.node[0].y += deltaLines;


    refreshBoard(); // Calls refreshBoard() to show snakes new postion
}

// Primary Author: Michael Santoro
// Initialize the game, reset variables, and print border/credits
void initGame(){
    score = 0;                            // Reset score
    gameOver = false;                     // Reset game over flag
    clear();                              // Reset the Screen
    curs_set(0);                          // Hide the Cursor
    noecho();                             // Do not echo user input to the screen
    nodelay(stdscr,TRUE);                 // Turn on No Delay
    keypad(stdscr,TRUE);                  // Enable arrow keys

    snake.length = 5;                     // Reset the Snake Length
    snake.node[0].x = 10;                 // Set Starting X Position
    snake.node[0].y = 10;                 // Set Starting Y Position

    // Prints the Snake at the start of the game
    for(int i = 0; i < snake.length; i++){
        snake.node[i].x = 10;
        snake.node[i].y = 10-i;
    }

    // Prints title and credits of game
    int centerX = COLS/2;                 // Get center of screen (x axis)
    move(0,centerX-2);                    // Move cursor to center - offset where offset = "snake"'s length/2
    addstr("Snake");                      // Print the String
    move(1,centerX-(sizeof(credits)/2));  // Move cursor to center - offset of credits string
    addstr(credits);                      // Print the String

    // Draws the border of the board with a 1 character border
    // between the edge of the terminal and border of the snake pit
    for(int i = 2; i < LINES - 2; i++){
        for(int j = 2; j < COLS - 2; j++){
            if(i == 2 || j == 2|| i == LINES-3 || j == COLS-3){
                move(i,j);
                printw("#");
            }
        }
    }

    refreshBoard();                      // Call refreshBoard

    // Primary Author: Ryan Tyimok
    // Handles User Input and changes direction and gameOver tabs as needed
    while(!gameOver){
        int ch = getch(); // Store user input in ch 
        // Primary Authors: Ryan Tyimok and Bradley Morales
        //                  Ryan: Use the user-inputted arror keys to determine direction
        //                  Bradley: Implemented detection for if snake tries to reverse itself
        switch(ch){
            case 'q': // Quit Game
                gameOver = true;
                break;
            case KEY_UP:
                if(direction == 2){
                    direction = 0;
                    gameOver = true;
                    break;
                }
                else{
                    direction = 1;
                    break;
                }
            case KEY_DOWN:
                if(direction == 1){
                    direction = 0;
                    gameOver = true;
                    break;
                }
                else{
                    direction = 2;
                    break;
                }
            case KEY_LEFT:
                if(direction == 4){
                    direction = 0;
                    gameOver = true;
                    break;
                }
                else{
                    direction = 3;
                    break;
                }
            case KEY_RIGHT:
                if(direction == 3){
                    direction = 0;
                    gameOver = true;
                    break;
                }
                else{
                    direction = 4;
                    break;
                }
        }
        moveSnake();       // Call moveSnake   
        gameOver = isGameOver();
        
        usleep(125000);    // Delay between frames
        refreshBoard();  
    }
    if(score > highScore){
        highScore = score;
        refreshBoard();
    }
    keypad(stdscr,FALSE);  // Disable arrow keys at game loss
    direction = 0;         // Set direction to 0 so snake freezes
    sleep(5);              // TEST LINE TO FREEZE FOR 5 SECONDS BEFORE EXITING GAME
}

// Primary Author: Michael Santoro
// Redraws the board and refreshes the screen to show changes in snake, fruits, and score
void refreshBoard(){

    // Clears the Board by replacing everything inside the pit with spaces
    for(int i = 3; i < LINES - 3; i++) {
        for(int j = 3; j < COLS - 3; j++) {
            move(i, j);
            printw(" ");
        }
    }

    // Print the Snake
    for(int i = snake.length - 1; i >= 0; i--){
        if(i == 0){ // Head of the Snake
            move(snake.node[i].x,snake.node[i].y);
            printw("@");
        }
        else{       // Body of the Snake
            move(snake.node[i].x,snake.node[i].y);
            printw("o");    
        }
    }

    // Prints the player's score
    move(LINES - 2,2);                  // Move cursor to bottom left corner
    addstr("Score:");                   // Print the score label
    printw("%d",score);                 // Print the score

    // Prints the High Score
    move(LINES - 2,COLS-14);            // Move cursor to bottom left corner
    addstr("High Score:");              // Print the score label
    printw("%d",highScore);             // Print the score

    refresh();                          // Refresh the Screen
}

// Primary Author: Bradley Morales
// Check if Snake has run into a wall
bool isGameOver(){
    int headX = snake.node[0].x;       // Get the X Coordinate of the Head and store in headX
    int headY = snake.node[0].y;       // Get the Y Coordinate of the Head and store in headY
    
    // Check if Snake has run into a wall
    if(headY >= COLS - 3 || headY <= 2 || headX >= LINES - 3 || headX <= 2){
        return true;
    }
    
    // Check if Snake has run into itself
    for (int i = 1; i < snake.length; i++) {
        if (snake.node[i].x == headX && snake.node[i].y == headY) {
            return true;
        }
    }

    return false;
}