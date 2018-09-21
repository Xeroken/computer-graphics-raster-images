#include "rgba_to_rgb.h"

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  //j is for row number
  for(int j = 0; j < height; j = j + 1) {
    //i is for column number
    for(int i = 0; i < width; i = i + 1) {
      //Overwriting red in rgb
      rgb[3 * (i + (width * j))] = rgba[4 * (i + (width * j))];
      //Overwriting green in rgb
      rgb[1 + (3 * (i + (width * j)))] = rgba[1 + (4 * (i + (width * j)))];
      //Overwriting blue in rgb
      rgb[2 + (3 * (i + (width * j)))] = rgba[2 + (4 * (i + (width * j)))];
    }
  }
}
