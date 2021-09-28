#include <stdio.h>

typedef enum color {
  BLACK = 30,
  RED = 31,
  GREEN = 32,
  YELLOW = 33,
  BLUE = 34,
  MAGENTA = 35,
  CYAN = 36,
  WHITE = 37,
  RESET = 0,
} color;
 
void set_color(enum color c)
{
  printf("\033[%dm", c);
}

char echo_line(void) {
  int c = getchar();
  while (c != EOF){
    putchar(c);
    if (c == '\n') break;
    c = getchar();
  }  
  return(c);
}

void colorize_dna(char nuc) {
  switch (nuc){
    case 'a': set_color(RED); break;
    case 'A': set_color(RED); break;
    case 'c': set_color(BLUE); break;
    case 'C': set_color(BLUE); break;
    case 'g': set_color(GREEN); break;
    case 'G': set_color(GREEN); break;
    case 't': set_color(CYAN); break;
    case 'T': set_color(CYAN); break;
    default:  set_color(RESET);
  }
}

int main(int argc, int *argv[]) {
  int c;
  int last_c;

  while ((c = getchar()) != EOF) {
    if (c == '>') {
      c = putchar(c);
      echo_line();
    } else if (c == last_c) {
      putchar(c);
    } else {
      colorize_dna(c);
      putchar(c);
    }
    last_c = c;
  }
}
