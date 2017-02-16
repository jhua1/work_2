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

  //testing octants
  //octant1(0,0,300,250,s,c);
  //octant2(0,0,100,400,s,c);
  //octant7(250,250,300,100,s,c);
  //octant8(250,250,500,200,s,c);
  
  //testing slopes 1 and -1
  //octant1(0,0,500,500,s,c); only 1
  //octant2(0,0,500,500,s,c); only 1
  //octant7(0,500,500,0,s,c); only -1
  //octant8(0,500,500,0,s,c); only -1
  
  //testing slopes horizontal
  //octant1(250,250,0,250,s,c); works going right
  //octant2(250,250,0,250,s,c); no work
  //octant7(250,250,0,250,s,c); no work
  //octant8(0,250,500,250,s,c); works going right

  //testing slopes vertical
  //octant1(100,500,100,250,s,c); no work
  //octant2(100,250,100,500,s,c); works going up
  //octant7(100,500,100,250,s,c); works going down
  //octant8(100,500,100,250,s,c); no work

  draw_line(250,250,125,250,s,c); //drawing left
  draw_line(250,250,375,250,s,c); //drawing right
  draw_line(250,250,250,375,s,c); //drawing up
  draw_line(250,250,250,125,s,c); //drawing down
  draw_line(125,250,250,375,s,c); //drawing left to top
  draw_line(250,375,375,250,s,c); //drawing top to right
  draw_line(375,250,250,125,s,c); //drawing right to bottom
  draw_line(250,125,125,250,s,c); //drawing bottom to left
  draw_line(0,0,250,500,s,c);
  draw_line(250,500,500,0,s,c);
  draw_line(500,0,375,125,s,c);
  draw_line(375,125,125,125,s,c);
  draw_line(125,125,0,0,s,c);
  draw_line(0,500,250,0,s,c);
  draw_line(250,0,500,500,s,c);
  draw_line(500,500,375,375,s,c);
  draw_line(375,375,125,375,s,c);
  draw_line(125,375,0,500,s,c);
  
  display(s);
  save_extension(s, "lines.png");
}  
