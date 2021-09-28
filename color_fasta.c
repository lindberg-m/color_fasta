#include <stdio.h>
#define N_CHARS 256

typedef enum color {
  BLACK = 30, RED = 31, GREEN = 32,
  YELLOW = 33, BLUE = 34, MAGENTA = 35,
  CYAN = 36, WHITE = 37, RESET = 0,
} color;

void set_color(enum color c) { printf("\033[%dm", c); }

void init_dna_color_map(enum color map[N_CHARS])
{
  for (int i=0; i < N_CHARS; i++)
  {
    map[i] = RESET;
    if (i == 'a' || i == 'A') 
      map[i] = RED;
    else if (i == 'c' || i == 'C')
      map[i] = BLUE;
    else if (i == 'g' || i == 'G')
      map[i] = GREEN;
    else if (i == 't' || i == 'T')
      map[i] = YELLOW;
  }
}

int main(int argc, int *argv[]) {
  int c;
  int last_c;

  enum color color_map[N_CHARS]; 
  init_dna_color_map(color_map);

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
      set_color(color_map[c]);
      putchar(c);
    }
    last_c = c;
  }
}
