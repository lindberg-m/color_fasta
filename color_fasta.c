#include <stdio.h>
#define N_CHARS 256

typedef enum color {
  BLACK  = 30, RED   = 31, GREEN   = 32,
  YELLOW = 33, BLUE  = 34, MAGENTA = 35,
  CYAN   = 36, WHITE = 37, RESET   = 0,
} color;

void set_color(enum color c) { printf("\033[%dm", c); }

void init_dna_color_map(enum color map[N_CHARS])
{
  map['a'] = map['A'] = RED;
  map['c'] = map['C'] = BLUE;
  map['g'] = map['G'] = GREEN;
  map['t'] = map['T'] = YELLOW;
}

int main(int argc, int *argv[]) {
  int c;
  int last_c;

  enum color color_map[N_CHARS] = {RESET}; 
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
