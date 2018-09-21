#include "rgb_to_gray.h"

void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.resize(height*width);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for(int j = 0; j < height; j = j + 1) {
    for(int i = 0; i < width; i = i + 1) {
      gray[i + (width * j)] = (unsigned char) ((int) ((0.2126 * (float) rgb[3 * (i + (width * j))]) + (0.7152 * (float) rgb[1 + (3 * (i + (width * j)))])  + (0.0722 * (float) rgb[2 + (3 * (i + (width * j)))])));
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}


