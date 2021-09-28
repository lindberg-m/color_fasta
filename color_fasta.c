#include <stdio.h>

typedef enum color {
  BLACK = 30, RED = 31, GREEN = 32,
  YELLOW = 33, BLUE = 34, MAGENTA = 35,
  CYAN = 36, WHITE = 37, RESET = 0,
} color;

void set_color(enum color c) { printf("\033[%dm", c); }

int main(int argc, int *argv[]) {
  int c;
  int last_c;

  color nuc_map[256];
  for (int i=0; i < 256; i++)
  {
    nuc_map[i] = RESET;
    if (i == 'a' || i == 'A') 
      nuc_map[i] = RED;
    else if (i == 'c' || i == 'C')
      nuc_map[i] = BLUE;
    else if (i == 'g' || i == 'G')
      nuc_map[i] = GREEN;
    else if (i == 't' || i == 'T')
      nuc_map[i] = YELLOW;
  }

  while ((c = getchar()) != EOF) {
    if (c == '>') {
      set_color(RESET);
      putchar(c);
      while ((c = getchar()) != EOF && c != '\n') {
        putchar(c);
      }
      putchar('\n');
    } else if (c == last_c) {
      putchar(c);
    } else {
      set_color(nuc_map[c]);
      putchar(c);
    }
    last_c = c;
  }
}
