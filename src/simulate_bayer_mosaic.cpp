#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      if(i%2==0){
        bayer[j*width+i] = j%2==0 ? rgb[3*(j*width+i)+1] : rgb[3*(j*width+i)];
      }else{
        bayer[j*width+i] = j%2==0 ? rgb[3*(j*width+i)+2] : rgb[3*(j*width+i)+1];
      }
    }
  }
}
