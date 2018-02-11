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

  int m;
  if ( b == 0 ) m = 2;
  else if ( a < 0 ) m = a / -b - 0.5;
  else m = a / -b + 0.5;

  int c = y - m*x;
  
  int d = a*x + b*y + c;

  if( m >= 1 || m < -1 ) {
    while ( y <= y1 ) {
      plot(s, clr, x, y);

      // VII
      if ( a < 0 ) {
	if ( d < 0 ) {
	  x++;
	  d += 2*a;
	}
	y--;
	d += 2*b;
      }

      // II
      else { 
	if ( d < 0 ) {
	  x++;
	  d += 2*a;
	}
	y++;
	d += 2*b;
      }
    }
  }

  else {
    while ( x <= x1 ) {
      plot(s, clr, x, y);

      // VIII
      if ( a < 0 ){
	if ( d < 0 ) {
	  y--;
	  d += 2*b;
	}
	x++;
	d += 2*a;
      }

      // I
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
}
