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

  octant1(0,0,300,250,s,c);
  octant2(0,0,100,400,s,c);
  octant7(250,250,300,100,s,c);
  octant8(250,250,500,200,s,c);

  display(s);
  save_extension(s, "lines.png");
}  
