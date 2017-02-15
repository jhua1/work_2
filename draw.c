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
    //vertical
    if ( !deltx){
      if (delty > 0)
	octant2(x0,y0,x1,y1,s,c);
      else
	octant7(x0,y0,x1,y1,s,c);
    }
    //horizontal
    else if (!delty){
      if (deltx >0)
	octant1(x0,y0,x1,y1,s,c);
      else 
	octant1(x1,y0,x0,y1,s,c);
    }
  }
  //Octant 1,2,7,8
  else if (deltx > 0){
    //Octant1,2
    if ( delty >0){
      if ( delty > deltx)
	octant2(x0,y0,x1,y1,s,c);
      else
	octant1(x0,y0,x1,y1,s,c);
    }
    else{
      delty *= -1;
      if (delty > deltx)
	octant7(x0,y0,x1,y1,s,c);
      else
	octant8(x0,y0,x1,y1,s,c);
    }
  }
}
