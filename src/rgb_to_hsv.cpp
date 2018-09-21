#include "rgb_to_hsv.h"

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  double max = r;
  double min = r;
  //Calculating hue
  if(g > max) {
    max = g;
  }
  if(g < min) {
    min = g;
  }
  if(b > max) {
    max = b;
  }
  if(b < min) {
    min = b;
  }
  if((r == g) && (r == b)) {
    h = 0;
  } else if((r >= g) && (r >= b)) {
    h = 60 * ((g - b) / (max - min));
  } else if((g >= r) && (g >= b)) {
    h = 60 * (2 + ((b - r) / (max - min)));
  } else {
    h = 60 * (4 + ((r - g) / (max - min)));
  }
  if(h < 0) {
    h = h + 360;
  }
  //Calculating saturation
  if(max == 0) {
    s = 0;
  } else {
    s = (max - min) / max;
  }
  //Calculating value
  v = max;
  ////////////////////////////////////////////////////////////////////////////
}
