#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

void octant1(int x0, int y0, int x1, int y1, screen s, color c) {
  int A,B,x,y,d;
  x = x0;
  y = y0;
  A = y1 - y0;
  B = x0 - x1;
  d = B + 2*A;
  while( x <= x1){
    plot(s,c,x,y);
    if ( d > 0){
      y++;
      d+=2*B;
    }
    x++;
    d+=2*A;
  }
}

void octant2(int x0, int y0, int x1, int y1, screen s, color c) {
  int A,B,x,y,d;
  x = x0;
  y = y0;
  A = y1 - y0;
  B = x0 - x1;
  d = 2*B + A;
  while( y <= y1){
    plot(s,c,x,y);
    if ( d < 0){
      x++;
      d+=2*A;
    }
    y++;
    d+=2*B;
  }
}

void octant7(int x0, int y0, int x1, int y1, screen s, color c) {
  int A,B,x,y,d;
  x = x0;
  y = y0;
  A = y1 - y0;
  B = x0 - x1;
  d = A-2*B;
  while( y >= y1){
    plot(s,c,x,y);
    if ( d > 0){
      x++;
      d+=2*A;
    }
    y--;
    d-=2*B;
  }
}

void octant8(int x0, int y0, int x1, int y1, screen s, color c) {
  int A,B,x,y,d;
  x = x0;
  y = y0;
  A = y1 - y0;
  B = x0 - x1;
  d = 2*A-B;
  while( x <= x1){
    plot(s,c,x,y);
    if ( d < 0){
      y--;
      d-=2*B;
    }
    x++;
    d+=2*A;
  }
}

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int deltx,delty;
  deltx = x1-x0;
  delty = y1-y0;
  //vertical and horizontal lines
  if (deltx==0 || delty==0){
    if ( !deltx){
      if (delty > 0)
	
}
