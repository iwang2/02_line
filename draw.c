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

  int m;
  if ( b == 0 ) m = 2;
  else m = a / -b + 0.5;
  
  int d = a*x + b*y + c;

  while ( y <= y1 && (m >= 1 || m < -1) ) {
    plot(s, clr, x, y);

    // octant II
    if ( a > 0 ) { 
      if ( d < 0 ) {
	x++;
	d += 2*a;
      }
      y++;
      d += 2*b;
    }

    // octant VII
    else {
      if ( d > 0 ) {
	x++;
	d += 2*a;
      }
      y--;
      d += 2*b;
    }
  }

  // I, VIII
  while ( x <= x1 && (m < 1 || m >= -1) ) {
    plot(s, clr, x, y);
    
    if ( a < 0 ){
      if ( d < 0 ) {
        y--;
	d += 2*b;
      }
      x++;
      d += 2*a;
    }
    
    else {
      if ( d > 0 ) {
	y++;
	d += 2*b;
      }
      x++;
      d += 2*a;
    }
  }
}
