#ifndef FILTERUTILS_H
#define FILTERUTILS_H


#include "Convolution/RGBA.h"
#include <vector>

namespace FilterUtils {

inline unsigned char REAL2byte(float f);
void Convolve2D(std::vector<RGBA>* data, int width, int height, const std::vector<float> &kernel);

}

#endif // FILTERUTILS_H
