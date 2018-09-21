#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  assert(
    (num_channels == 3 || num_channels ==1 ) &&
    ".ppm only supports RGB or grayscale images");
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  std::ofstream ppm_file(filename);
  //States that this is a ppm file
  if (num_channels == 3) {
    ppm_file << "P6\n";
    //States the width and height of the image (for some reason, P3 only shows a black square and doubling the width prevents overlap)
    ppm_file << (2 * width) << " " << height << "\n";
    //States the maximum value for intensity
    ppm_file << "255\n";
    //j represents a row
    for(int j = 0; j < height; j = j + 1) {
      //i represents a column
      for(int i = 0; i < width; i = i + 1) {
        //writes the red, green, and blue values into the file
        ppm_file << data[3 * (i + (width * j))] << " ";
        ppm_file << data[1 + (3 * (i + (width * j)))] << " ";
        ppm_file << data[2 + (3 * (i + (width * j)))];
        //adds a new line instead of a space if it is at the last column
        if(i == width - 1) {
	  ppm_file << "\n";
        } else {
	  ppm_file << " ";
        }
      }
    }
  } else {
    //For grayscale images
    ppm_file << "P5\n";
    ppm_file << (2 * width) << " " << height << "\n";
    //States the maximum value for intensity
    ppm_file << "255\n";
    //j represents a row
    for(int j = 0; j < height; j = j + 1) {
      //i represents a column
      for(int i = 0; i < width; i = i + 1) {
        //writes the greyscale value into the file
        ppm_file << data[i + (width * j)];
        //adds a new line instead of a space if it is at the last column
        if(i == width - 1) {
          ppm_file << "\n";
        } else {
          ppm_file << " ";
        }
      }
    }
  }
  ppm_file.close();
  return true;
  ////////////////////////////////////////////////////////////////////////////
}
