#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;

  clear_screen(s);

  draw_line(0, 0, 300, 200, s, c); // oct I in green

  c.red = MAX_COLOR;
  draw_line(100, 300, 400, 100, s, c); // oct VIII hopefully yellow

  c.green = 0;
  draw_line(0, 200, 500, 200, s, c); // horizontal in red

  c.red = 0;
  c.blue = MAX_COLOR;
  draw_line(300, 0, 300, 400, s, c); // vertical in blue

  display(s);
  save_extension(s, "lines.png");
}
