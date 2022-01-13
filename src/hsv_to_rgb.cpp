#include "hsv_to_rgb.h"
#include <cmath>

void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  const double c = v * s;
  const double x = c * (1-fabs(fmod(h/60, 2)-1));
  const double m = v - c;
  double r_d;
  double g_d;
  double b_d;
  if(0.0<=h&&h<60.0){
    r_d=c;
    g_d=x;
    b_d=0;
  }
  if(60.0<=h&&h<120.0){
    r_d=x;
    g_d=c;
    b_d=0;
  }
  if(120.0<=h&&h<180.0){
    r_d=0;
    g_d=c;
    b_d=x;
  }
  if(180.0<=h&&h<240.0){
    r_d=0;
    g_d=x;
    b_d=c;
  }
  if(240.0<=h&&h<300.0){
    r_d=x;
    g_d=0;
    b_d=c;
  }
  if(300.0<=h&&h<360.0){
    r_d=c;
    g_d=0;
    b_d=x;
  }
  r = (r_d+m)*255;
  g = (g_d+m)*255;
  b = (b_d+m)*255;
}
