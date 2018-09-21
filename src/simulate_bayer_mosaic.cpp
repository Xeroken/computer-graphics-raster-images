#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  //Starts green at top left corner, right neighbour is blue and bottom neighbour is red
  for(int j = 0; j < height; j = j + 1) {
    for(int i = 0; i < width; i = i + 1) {
      //For green squares
      if(((i % 2 == 0) && (j % 2 == 0)) || ((i % 2 == 1) && (j % 2 == 1))) {
	bayer[i + (width * j)] = rgb[1 + (3 * (i + (width * j)))];
      } else if((i % 2 == 1) && (j % 2 == 0)) {
	//For blue squares
	bayer[i + (width * j)] = rgb[2 + (3 * (i + (width * j)))];
      } else {
	//For red squares
	bayer[i + (width * j)] = rgb[3 * (i + (width * j))];
      }
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
