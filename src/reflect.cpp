#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for(int j = 0; j < height; j = j + 1) {
    for(int i = 0; i < width; i = i + 1) {
      //To reflect along the y axis, just invert the x values for the original colour pixel map
      reflected[num_channels * (i + (width * j))] = input[num_channels * ((width - 1 - i) + (width * j))];
      reflected[1 + (num_channels * (i + (width * j)))] = input[1 + (num_channels * ((width - 1 - i) + (width * j)))];
      reflected[2 + (num_channels * (i + (width * j)))] = input[2 + (num_channels * ((width - 1 - i) + (width * j)))];
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
