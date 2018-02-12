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
    b = x0 - x1;
  int d;

  double m;
  if ( b == 0 ) m = 2;
  else m = a * 1.0 / -b;
  printf("m = %f\n", m);
    
  // VII
  if ( m < -1 ) {
    d = a - 2*b;
    while ( x <= x1 ) {
      plot(s, clr, x, y);
      if ( d > 0 ) {
	x++;
	d += 2*a;
      }
      y--;
      d -= 2*b;
    }
  }

  // VIII
  else if ( m < 0 ) {
    d = 2*a - b;
    while ( x <= x1 ) {
      plot(s, clr, x, y);
      if ( d < 0 ) {
	y--;
	d -= 2*b;
      }
      x++;
      d += 2*a;
    }
  }

  // I
  else if ( m < 1 ) {
    d = 2*a + b;
    while ( x <= x1 ) {
      plot(s, clr, x, y);
      if ( d > 0 ) {
	y++;
	d += 2*b;
      }
      x++;
      d += 2*a;
    }
  }  

  // II
  else {
    d = a + 2*b;
    while ( x <= x1 ) {
      plot(s, clr, x, y);
      if ( d < 0 ) {
	x++;
	d += 2*a;
      }
      y++;
      d += 2*b;
    }
  }
}
