#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  double alpha, alpha_a, alpha_b, r, g, b;
  for (int i = 0; i < width*height; i++) {
    alpha_a = A[i*4+3];
    alpha_b = B[i*4+3];
    alpha = (alpha_a/255)+(alpha_b/255)*(1-alpha_a/255);
    r = (A[i*4]*(alpha_a/255)+B[i*4]*(alpha_b/255)*(1-alpha_a/255))/alpha;
    g = (A[i*4+1]*(alpha_a/255)+B[i*4+1]*(alpha_b/255)*(1-alpha_a/255))/alpha;
    b = (A[i*4+2]*(alpha_a/255)+B[i*4+2]*(alpha_b/255)*(1-alpha_a/255))/alpha;
    C[i*4]=r;
    C[i*4+1]=g;
    C[i*4+2]=b;
    C[i*4+3]=alpha*255;
  }
}
