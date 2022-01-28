#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      if(num_channels==1){
        reflected[(j*width+i)] = input[(j*width+width-i-1)];
      }else{
        reflected[3*(j*width+i)] = input[3*(j*width+width-i-1)];
        reflected[3*(j*width+i)+1] = input[3*(j*width+width-i-1)+1];
        reflected[3*(j*width+i)+2] = input[3*(j*width+width-i-1)+2];
      }
    }
  }
}
