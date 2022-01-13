#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);
  for (int j = 0; j < width; j++) {     // new height = old width
    for (int i = 0; i < height; i++) {  // new width = old height
      rotated[3*(j*height+i)] = input[3*(i*width+width-j-1)];
      rotated[3*(j*height+i)+1] = input[3*(i*width+width-j-1)+1];
      rotated[3*(j*height+i)+2] = input[3*(i*width+width-j-1)+2];
    }
  }
}
