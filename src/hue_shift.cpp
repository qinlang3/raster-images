#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  double h, s, v, r, g, b;
  for (int i = 0; i < width*height; i++) {
    rgb_to_hsv(rgb[i*3], rgb[i*3+1], rgb[i*3+2], h, s, v);
    h+=shift;
    if(h<0.0) h+=360.0;
    if(h>=360.0) h-=360.0;
    hsv_to_rgb(h, s, v, r, g, b);
    shifted[i*3]=r;
    shifted[i*3+1]=g;
    shifted[i*3+2]=b;
  }
}
