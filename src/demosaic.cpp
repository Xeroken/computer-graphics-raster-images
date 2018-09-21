#include "demosaic.h"

void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  //Starts green at top left corner, right neighbour is blue and bottom neighbour is red
  for(int j = 0; j < height; j = j + 1) {
    for(int i = 0; i < width; i = i + 1) {
      //For green squares
      if(((i % 2 == 0) && (j % 2 == 0)) || ((i % 2 == 1) && (j % 2 == 1))) {
        //Adding red value
	if(j == 0) {
	  rgb[3 * (i + (width * j))] = bayer[i + (width * (j + 1))];
	} else if((j == height - 1) && (i % 2 == 0)) {
	  rgb[3 * (i + (width * j))] = bayer[i + (width * (j - 1))];
	} else if(j % 2 == 0) {
	  rgb[3 * (i + (width * j))] = (bayer[i + (width * (j + 1))] + bayer[i + (width * (j - 1))]) / 2;
	} else if((j % 2 == 1) && (i == width - 1)) {
	  rgb[3 * (i + (width * j))] = bayer[i - 1 + (width * j)];
	} else {
	  rgb[3 * (i + (width * j))] = (bayer[i - 1 + (width * j)] + bayer[i + 1 + (width * j)]) / 2;
	}
	//Adding green value
	rgb[1 + (3 * (i + (width * j)))] = bayer[i + (width * j)];
	//Adding blue value
	if(i == 0) {
	  rgb[2 + (3 * (i + (width * j)))] = bayer[i + 1 + (width * j)];
	} else if((i == width - 1) && (j % 2 == 0)) {
	  rgb[2 + (3 * (i + (width * j)))] = bayer[i - 1 + (width * j)];
	} else if(i % 2 == 0) {
	  rgb[2 + (3 * (i + (width * j)))] = (bayer[i - 1 + (width * j)] + bayer[i + 1 + (width * j)]) / 2;
	} else if((i % 2 == 1) && (j == height - 1)) {
	  rgb[2 + (3 * (i + (width * j)))] = bayer[i + (width * (j - 1))];
	} else {
	  rgb[2 + (3 * (i + (width * j)))] = (bayer[i + (width * (j - 1))] + bayer[i + (width * (j + 1))]) / 2;
	}
      } else if((i % 2 == 1) && (j % 2 == 0)) {
        //For blue squares
	//Adding red value
        if((j == 0) && (i == width - 1)) {
	  rgb[3 * (i + (width * j))] = bayer[i - 1 + (width * (j + 1))];
	} else if((j == height - 1) && (i == width - 1)) {
	  rgb[3 * (i + (width * j))] = bayer[i - 1 + (width * (j - 1))];
	} else if(j == 0) {
	  rgb[3 * (i + (width * j))] = (bayer[i - 1 + (width * (j + 1))] + bayer[i + 1 + (width * (j + 1))]) / 2;
	} else if(j == height - 1) {
	  rgb[3 * (i + (width * j))] = (bayer[i - 1 + (width * (j - 1))] + bayer[i + 1 + (width * (j - 1))]) / 2;
	} else if(i == width - 1) {
	  rgb[3 * (i + (width * j))] = (bayer[i - 1 + (width * (j - 1))] + bayer[i - 1 + (width * (j + 1))]) / 2;
	} else {
	  rgb[3 * (i + (width * j))] = (bayer[i - 1 + (width * (j - 1))] + bayer[i + 1 + (width * (j - 1))] + bayer[i - 1 + (width * (j + 1))] + bayer[i + 1 + (width * (j + 1))]) / 4;
	}
	//Adding green value
	if((j == 0) && (i == width - 1)) {
          rgb[1 + (3 * (i + (width * j)))] = (bayer[i + (width * (j + 1))] + bayer[i - 1 + (width * j)]) / 2;
        } else if((j == height - 1) && (i == width - 1)) {
          rgb[1 + (3 * (i + (width * j)))] = (bayer[i + (width * (j - 1))] + bayer[i - 1 + (width * j)]) / 2;
        } else if(j == 0) {
          rgb[1 + (3 * (i + (width * j)))] = (bayer[i - 1 + (width * j)] + bayer[i + 1 + (width * j)] + bayer[i + (width * (j + 1))]) / 3;
        } else if(j == height - 1) {
          rgb[1 + (3 * (i + (width * j)))] = (bayer[i - 1 + (width * j)] + bayer[i + 1 + (width * j)] + bayer[i + (width * (j - 1))]) / 3;
        } else if(i == width - 1) {
          rgb[1 + (3 * (i + (width * j)))] = (bayer[i + (width * (j - 1))] + bayer[i + (width * (j + 1))] + bayer[i - 1 + (width * j)]) / 3;
        } else {
          rgb[1 + (3 * (i + (width * j)))] = (bayer[i - 1 + (width * j)] + bayer[i + 1 + (width * j)] + bayer[i + (width * (j + 1))] + bayer[i + (width * (j - 1))]) / 4;
        }
	//Adding blue value
	rgb[2 + (3 * (i + (width * j)))] = bayer[i + (width * j)];
      } else {
        //For red squares
	//Adding red value
        rgb[3 * (i + (width * j))] = bayer[i + (width * j)];
	//Adding green value
	if((i == 0) && (j == height - 1)) {
	  rgb[1 + (3 * (i + (width * j)))] = (bayer[i + 1 + (width * j)] + bayer[i + (width * (j - 1))]) / 2;
	} else if((i == width - 1) && (j == height - 1)) {
	  rgb[1 + (3 * (i + (width * j)))] = (bayer[i - 1 + (width * j)] + bayer[i + (width * (j - 1))]) / 2;
	} else if(i == 0) {
	  rgb[1 + (3 * (i + (width * j)))] = (bayer[i + (width * (j - 1))] + bayer[i + (width * (j + 1))] + bayer[i + 1 + (width * j)]) / 3;
	} else if(i == width - 1) {
	  rgb[1 + (3 * (i + (width * j)))] = (bayer[i + (width * (j - 1))] + bayer[i + (width * (j + 1))] + bayer[i - 1 + (width * j)]) / 3;
	} else if(j == height - 1) {
	  rgb[1 + (3 * (i + (width * j)))] = (bayer[i - 1 + (width * j)] + bayer[i + 1 + (width * j)] + bayer[i + (width * (j - 1))]) / 3;
	} else {
	  rgb[1 + (3 * (i + (width * j)))] = (bayer[i - 1 + (width * j)] + bayer[i + 1 + (width * j)] + bayer[i + (width * (j + 1))] + bayer[i + (width * (j - 1))]) / 4;
	}
	//Adding blue value
	if((i == 0) && (j == height - 1)) {
	  rgb[2 + (3 * (i + (width * j)))] = bayer[i + 1 + (width * (j - 1))];
	} else if((i == width - 1) && (j == height - 1)) {
	  rgb[2 + (3 * (i + (width * j)))] = bayer[i - 1 + (width * (j - 1))];
	} else if(i == 0) {
	  rgb[2 + (3 * (i + (width * j)))] = (bayer[i + (width * (j - 1))] + bayer[i + (width * (j + 1))] + bayer[i + 1 + (width * j)]) / 3;
	} else if(i == width - 1) {
	  rgb[2 + (3 * (i + (width * j)))] = (bayer[i + (width * (j - 1))] + bayer[i + (width * (j + 1))] + bayer[i - 1 + (width * j)]) / 3;
	} else if(j == height - 1) {
	  rgb[2 + (3 * (i + (width * j)))] = (bayer[i - 1 + (width * j)] + bayer[i + 1 + (width * j)] + bayer[i + (width * (j - 1))]) / 3;
	} else {
	  rgb[2 + (3 * (i + (width * j)))] = (bayer[i - 1 + (width * (j - 1))] + bayer[i + 1 + (width * (j - 1))] + bayer[i - 1 + (width * (j + 1))] + bayer[i + 1 + (width * (j + 1))]) / 4;
	}
      }
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
