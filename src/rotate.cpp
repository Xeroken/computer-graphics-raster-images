#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  // Have to flip for loop rotation to fit new orientation
  for(int j = 0; j < width; j = j + 1) {
    for(int i = 0; i < height; i = i + 1) {
      //Rotate counter clockwise by swapping x and y values, then invert the new y value
      rotated[num_channels * (i + (height * j))] = input[num_channels * ((width - 1 - j) + (width * i))];
      rotated[1 + (num_channels * (i + (height * j)))] = input[1 + (num_channels * ((width - 1 - j) + (width * i)))];
      rotated[2 + (num_channels * (i + (height * j)))] = input[2 + (num_channels * ((width - 1 - j) + (width * i)))];
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
