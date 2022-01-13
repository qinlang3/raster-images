#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
  double h, s, v, r, g, b;
  for (int i = 0; i < width*height; i++) {
    rgb_to_hsv(rgb[i*3], rgb[i*3+1], rgb[i*3+2], h, s, v);
    if(h<0.0) h+=360.0;
    s-=factor*s;
    hsv_to_rgb(h, s, v, r, g, b);
    desaturated[i*3]=r;
    desaturated[i*3+1]=g;
    desaturated[i*3+2]=b;
  }
}
