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

  /*
  int i;
  int add = 10;
  for ( i = 0; i <= 500; i += add ) {
    draw_line(i, 0, 500, i, s, c);
  }
  for ( i = 0; i <= 500; i += add ) {
    draw_line(0, i, i, 500, s, c);
  }
  for ( i = 0; i <= 500; i += add ) {
    draw_line(0, 500-i, i, 0, s, c);
  }
  for ( i = 0; i <= 500; i += add ) {
    draw_line(i, 500, 500, 500-i, s, c);
  }
  */

  draw_line(0, 0, 300, 500, s, c); // oct II in green
  draw_line(0, 500, 300, 0, s, c); // oct VII
  draw_line(0, 0, 500, 500, s, c); // m = 1

  c.red = MAX_COLOR;
  draw_line(0, 500, 500, 400, s, c); // oct VIII hopefully yellow
  draw_line(0, 0, 500, 200, s, c); // oct I
  draw_line(0, 500, 500, 0, s, c); // m = -1

  c.green = 0;
  draw_line(0, 200, 500, 200, s, c); // horizontal in red

  c.red = 0;
  c.blue = MAX_COLOR;
  draw_line(300, 0, 300, 400, s, c); // vertical in blue
  draw_line(200, 500, 200, 0, s, c); // vertical going the other way

  display(s);
  save_extension(s, "lines.png");
}
