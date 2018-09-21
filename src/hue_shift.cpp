#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  double hue_holder, saturation_holder, value_holder;
  double new_r, new_g, new_b;
  for(int j = 0; j < height; j = j + 1) {
    for(int i = 0; i < width; i = i + 1) {
      //Convert rgb values to hsv values
      rgb_to_hsv((double) rgb[3 * (i + (width * j))] / 255, (double) rgb[1 + (3 * (i + (width * j)))] / 255, (double) rgb[2 + (3 * (i + (width * j)))] / 255, hue_holder, saturation_holder, value_holder);
      //Add the given hue shift
      hue_holder = hue_holder + shift;
      //Change it back to rgb values and put into shifted
      hsv_to_rgb(hue_holder, saturation_holder, value_holder, new_r, new_g, new_b);
      shifted[3 * (i + (width * j))] = (int) (new_r * 255);
      shifted[1 + (3 * (i + (width * j)))] = (int) (new_g * 255);
      shifted[2 + (3 * (i + (width * j)))] = (int) (new_b * 255);
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
