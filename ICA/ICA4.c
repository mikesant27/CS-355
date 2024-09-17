// Michael Santoro
// ICA 4

// Put sufficient comments to show what the program does.
// Take a screenshot of the output.

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

struct termios orig_termios;                 // Struct which holds the original terminal settings

void disableRawMode() {
  tcsetattr(0, TCSAFLUSH, &orig_termios);    // Restore terminal settings from orig_termios
}

void enableRawMode() {
  tcgetattr(0, &orig_termios);               // Get current terminal settings and store in orig_termios
  
  struct termios raw = orig_termios;         // Initialize the struct and store original terminal settings for modification
  raw.c_lflag &= ~(ECHO | ICANON);           // Disable echo and canonical mode

  tcsetattr(0, TCSAFLUSH, &raw);             // Flush all pending output
}

int main() {
  enableRawMode();                           // Enable Raw Mode

  char c;                                    // Variable to store the character read
  while (read(0, &c, 1) == 1 && c != 'q');   // Read charactes until q is read
  return 0;                                  // Quit the program after the user enters 'q'
}