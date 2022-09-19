#pragma once

#include "RGBA.h"
#include <cstdint>
#include <vector>

namespace FilterUtils {

inline std::uint8_t floatToUint8(float x);

void convolve2D(std::vector<RGBA>& data,
                int width,
                int height,
                const std::vector<float>& kernel);

}
