#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line (int x0, int y0, int x1, int y1, screen s, color clr) {
  int
    x = x0,
    y = y0;
  int
    a = y1 - y0,
    b = x0 - x1,
    c = y0 * (x1 - x0);
  
  int d = a*x + b*y + c;

  while ( x <= x1 ) {
    plot(s, clr, x, y);

    //if ( -b <= 1 && -b >= 0 ) {
      if ( d > 0 ) {
	y++;
	d += 2*b;
      }
      x++;
      d += 2*a;
      //}
  }
}
