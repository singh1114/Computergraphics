#include <graphics.h>

int main(){

  int gd = DETECT, gm;
  double x0 = 0, y0 = 140, xi, yi, radius = 140, calmid;
  float ymid, xmid;
  initgraph(&gd, &gm, NULL);
  float square(float a){
    return (a*a);
  }
  //putpixel(x0, y0, 300);
  xmid = x0 + 1;
  ymid = y0 - 0.5;
  xi = x0;
  yi = y0;
  while(yi > xi){
    putpixel(xi, yi, 300);
    calmid = square(xmid) + square(ymid) - square(radius);
    if(calmid > 0){
      ymid = ymid - 1;
      yi = yi -1;
    }
    xmid = xmid + 1;
    xi = xi + 1;
  }
  delay(50000);
  closegraph();
  return 0;
}
