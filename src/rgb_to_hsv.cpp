#include "rgb_to_hsv.h"
#include <algorithm>
#include <cmath>

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  const double r_d = r/255;
  const double g_d = g/255;
  const double b_d = b/255;
  const double cmax = std::max(std::max(r_d, g_d), b_d);
  const double cmin = std::min(std::min(r_d, g_d), b_d);
  const double delta = cmax - cmin;
  if (delta==0.0){
    h = 0;
  }else if(cmax==r_d){
    h = 60 * fmod((g_d-b_d)/delta, 6);
  }else if(cmax==g_d){
    h = 60 * (((b_d-r_d)/delta)+2);
  }else {
    h = 60 * (((r_d-g_d)/delta)+4);
  }
  if (cmax == 0.0){
    s = 0;
  }else{
    s = delta/cmax;
  }
  v = cmax;
}
