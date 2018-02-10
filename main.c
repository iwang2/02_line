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

  draw_line(100, 100, 300, 500, s, c); // oct II in green
  draw_line(100, 100, 500, 500, s, c); // m = 1
  draw_line(100, 100, 500, 200, s, c); // oct I

  c.red = MAX_COLOR;
  draw_line(100, 300, 400, 200, s, c); // oct VIII hopefully yellow
  draw_line(100, 500, 400, 100, s, c); // oct VII
  draw_line(100, 400, 400, 100, s, c); // m = -1

  c.green = 0;
  draw_line(0, 200, 500, 200, s, c); // horizontal in red

  c.red = 0;
  c.blue = MAX_COLOR;
  draw_line(300, 0, 300, 400, s, c); // vertical in blue

  display(s);
  save_extension(s, "lines.png");
}
