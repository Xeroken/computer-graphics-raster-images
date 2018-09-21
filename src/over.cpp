#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  //Assuming that A and B are the same image size
  for(int j = 0; j < height; j = j + 1) {
    for(int i = 0; i < width; i = i + 1) {
      //If both images have a colour present, use colour from A and calculate new alpha
      if(A[3 + (4 * (i + (width * j)))] > 0) {
	C[4 * (i + (width * j))] = A[4 * (i + (width * j))];
        C[1 + (4 * (i + (width * j)))] = A[1 + (4 * (i + (width * j)))];
        C[2 + (4 * (i + (width * j)))] = A[2 + (4 * (i + (width * j)))];
	if(B[3 + (4 * (i + (width * j)))] > 0) {
	  C[3 + (4 * (i + (width * j)))] = (A[3 + (4 * (i + (width * j)))] * (1 - B[3 + (4 * (i + (width * j)))])) + (B[3 + (4 * (i + (width * j)))] * (1 - A[3 + (4 * (i + (width * j)))])) + (A[3 + (4 * (i + (width * j)))] * B[3 + (4 * (i + (width * j)))]);
	} else {
	  //If only A has a present colour, use A's alpha value
	  C[3 + (4 * (i + (width * j)))] = A[3 + (4 * (i + (width * j)))];
	}
      } else if(B[3 + (4 * (i + (width * j)))] > 0) {
	//If only B has a present colour, use B's colour and alpha value
	C[4 * (i + (width * j))] = B[4 * (i + (width * j))];
        C[1 + (4 * (i + (width * j)))] = B[1 + (4 * (i + (width * j)))];
        C[2 + (4 * (i + (width * j)))] = B[2 + (4 * (i + (width * j)))];
	C[3 + (4 * (i + (width * j)))] = B[3 + (4 * (i + (width * j)))];
      } else {
	//Leave alpha as 0 if no colour is present
	C[4 * (i + (width * j))] = A[4 * (i + (width * j))];
        C[1 + (4 * (i + (width * j)))] = A[1 + (4 * (i + (width * j)))];
        C[2 + (4 * (i + (width * j)))] = A[2 + (4 * (i + (width * j)))];
        C[3 + (4 * (i + (width * j)))] = 0;
      }
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
