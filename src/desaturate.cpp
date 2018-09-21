#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  double hue_holder, saturation_holder, value_holder;
  double new_r, new_g, new_b;
  for(int j = 0; j < height; j = j + 1) {
    for(int i = 0; i < width; i = i + 1) {
      //Convert rgb values to hsv values
      rgb_to_hsv((double) rgb[3 * (i + (width * j))] / 255, (double) rgb[1 + (3 * (i + (width * j)))] / 255, (double) rgb[2 + (3 * (i + (width * j)))] / 255, hue_holder, saturation_holder, value_holder);
      //Divide saturation by given factor
      saturation_holder = saturation_holder / factor;
      //Change it back to rgb values and put into desaturated
      hsv_to_rgb(hue_holder, saturation_holder, value_holder, new_r, new_g, new_b);
      desaturated[3 * (i + (width * j))] = (int) (new_r * 255);
      desaturated[1 + (3 * (i + (width * j)))] = (int) (new_g * 255);
      desaturated[2 + (3 * (i + (width * j)))] = (int) (new_b * 255);
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
