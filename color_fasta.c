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

void echo_line(void) {
  int c = getchar();
  while ((c != '\n') && (c != EOF)) {
    putchar(c);
    c = getchar();
  }
  putchar('\n');
}

void colorize_dna(char nuc) {
  enum color col;
  switch (nuc){
    case 'a':
      col = RED;
      break;
    case 'A':
      col = RED;
      break;
    case 'c':
      col = BLUE;
      break;
    case 'C':
      col = BLUE;
      break;
    case 'g':
      col = GREEN;
      break;
    case 'G':
      col = GREEN;
      break;
    case 't':
      col = CYAN;
      break;
    case 'T':
      col = CYAN;
      break;
    default:
      col = RESET;
  }
  set_color(col);
}


int main(int argc, int *argv[]) {
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '>') {
      putchar(c);
      echo_line();
    } else {
      colorize_dna(c);
      putchar(c);
    }
  }
}
