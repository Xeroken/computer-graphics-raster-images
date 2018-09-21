#include "hsv_to_rgb.h"

void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  double r1, g1, b1;
  int hue_convert = (((int) (h / 60.0)) % 2) - 1;
  if(hue_convert < 0) {
    hue_convert = hue_convert * (-1);
  }
  double x = v * s * (1 - hue_convert);
  if((h >= 0) && (h <= 60)) {
    r = v;
    g = x + v - (v * s);
    b = v - (v * s);
  } else if((h >= 60) && (h <= 120)) {
    r = x + v - (v * s);
    g = v;
    b = v - (v * s);
  } else if((h >= 120) && (h <= 180)) {
    r = v - (v * s);
    g = v;
    b = x + v - (v * s);
  } else if((h >= 180) && (h <= 240)) {
    r = v - (v * s);
    g = x + v - (v * s);
    b = v;
  } else if((h >= 240) && (h <= 300)) {
    r = x + v - (v * s);
    g = v - (v * s);
    b = v;
  } else {
    r = v;
    g = v - (v * s);
    b = x + v - (v * s);
  }
  ////////////////////////////////////////////////////////////////////////////
}
