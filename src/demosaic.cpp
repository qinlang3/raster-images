#include "demosaic.h"

// return color integer representaion given postion (i, j),
// 0 = red, 1 = green, 2 = blue, -1 = out of index
int get_color(int i, int j, const int & width, const int & height){
  if(i<0||i>(width-1)||j<0||j>(height-1)) return -1;
  if (j%2==0) {
    if(i%2==0) return 1;
    return 2;
  }else{
    if(i%2==0) return 0;
    return 1;
  }
}

// perform linear interpolation on a given pixel (i, j),
// and return the result
unsigned char linear_interpolation(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  int i,
  int j,
  int color) // 0 = red, 1 = green, 2 = blue
{
  int count=0;
  for(int m=i-1;m<=i+1;m++){
    for(int n=j-1;n<=j+1;n++){
      if(m!=i||n!=j){
        if(get_color(m, n, width, height)==color) count++;
      }
    }
  }
  return ((get_color(i-1, j-1, width, height)==color ? bayer[(j-1)*width+i-1] : 0) +
        (get_color(i, j-1, width, height)==color ? bayer[(j-1)*width+i] : 0) +
        (get_color(i+1, j-1, width, height)==color ? bayer[(j-1)*width+i+1] : 0) +
        (get_color(i-1, j, width, height)==color ? bayer[j*width+i-1] : 0) +
        (get_color(i+1, j, width, height)==color ? bayer[j*width+i+1] : 0) +
        (get_color(i-1, j+1, width, height)==color ? bayer[(j+1)*width+i-1] : 0) +
        (get_color(i, j+1, width, height)==color ? bayer[(j+1)*width+i] : 0) +
        (get_color(i+1, j+1, width, height)==color ? bayer[(j+1)*width+i+1] : 0))/count;
}


void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      if(i%2==0){
        if(j%2==0){ 
          rgb[3*(j*width+i)] = linear_interpolation(bayer, width, height, i, j, 0);
          rgb[3*(j*width+i)+1] = bayer[j*width+i];
          rgb[3*(j*width+i)+2] = linear_interpolation(bayer, width, height, i, j, 2);
        }else{      
          rgb[3*(j*width+i)] = bayer[j*width+i];
          rgb[3*(j*width+i)+1] = linear_interpolation(bayer, width, height, i, j, 1);
          rgb[3*(j*width+i)+2] = linear_interpolation(bayer, width, height, i, j, 2);
        }
      }else{
        if(j%2==0){ 
          rgb[3*(j*width+i)] = linear_interpolation(bayer, width, height, i, j, 0);
          rgb[3*(j*width+i)+1] = linear_interpolation(bayer, width, height, i, j, 1);
          rgb[3*(j*width+i)+2] = bayer[j*width+i];
        }else{      
          rgb[3*(j*width+i)] = linear_interpolation(bayer, width, height, i, j, 0);
          rgb[3*(j*width+i)+1] = bayer[j*width+i];
          rgb[3*(j*width+i)+2] = linear_interpolation(bayer, width, height, i, j, 2);
        }
      }
    }
  }
}








