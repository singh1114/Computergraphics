// digital differetial analysis algorithm for a line having slope < 1
#include<graphics.h>
#include<stdio.h>
int main(){
  int gd = DETECT, gm, x0 = 100, y0 = 200, xn = 300, yn = 300, slope, steps;
  float xinc, yinc, temp2, temp3;
  initgraph(&gd, &gm, NULL);
  // First of all draw the initial points
  putpixel(x0, y0, 300);

  // Now calculate the slope
  slope = (yn - y0)/(xn - x0);

  // For the slope to be less then 1.
  if(slope<1){
    steps = xn - x0;
  }
  else{
    steps = yn - y0;
  }

  // If the value comes out to be negative make it positive again
  if(steps < 0){
    steps = -1 * steps;
  }

  // Calculate the x and y increment
  xinc = (xn - x0)/steps;
  yinc = (float)(yn - y0)/steps;
  temp2 = x0;
  temp3 = y0;

  for(int temp = 0; temp < steps; temp++){
    temp2 += xinc;
    temp3 += yinc;
    x0 = temp2;
    y0 = temp3;
    putpixel(x0, y0, 100);
  }
  delay(50000);
  closegraph();
  return 0;
}
