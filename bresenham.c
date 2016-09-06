// Bresenham line generation algorithm
#include <graphics.h>
#include <stdio.h>
int main(){
  int gd = DETECT, gm;
  double x0 = 100, y0 = 200, x2 = 300, y2 = 350, xi, yi, xk, yk;
  initgraph(&gd, &gm, NULL);
  float d1, d2, slope, b;
  
  // The program is only made for the slope < 1
  // Calculate the slope
  slope = (y2 - y0)/(x2 - x0);

  // Calculate b for y = mx + b
  b = y0 - (slope * x0);

  float calculated1(int xi, int yi){
    return ((slope * (xi + 1)) + b - yi);
  }

  float calculated2(int xi, int yi){
    return (yi + 1 - (slope * (xi + 1)) - b);
  }

  int calculateyk(int xi, int yi){
    d1 = calculated1(xi, yi);
    d2 = calculated2(xi, yi);
    if((d1 - d2) > 0){
      yk = yi + 1;
    }
    else{
      yk = yi;
    }
    return yk;
  }

  int calculatexk(int xi, int yi){
    return 1;
  }
  int i = x0;
  // Call the function which calculate the next point
  void calculatepoints(int xi, int yi, int x2, int y2, float slope){
    putpixel(xi, yi, 300);
    if(slope < 1){
      xk = xi + 1;
      yk = calculateyk(xi, yi);
      //printf("%d\n", x2);
      //printf("%d")
      if(i < x2){
        i++;
        calculatepoints(xk, yk, x2, y2, slope);
      }
    }
    else{
      yk = yi + 1;
      xk = calculatexk(xi, yi);
    }
  }
  //printf("%d\n", x2);
  calculatepoints(x0, y0, x2, y2, slope);

  delay(50000);
  closegraph();
  return 0;
}
