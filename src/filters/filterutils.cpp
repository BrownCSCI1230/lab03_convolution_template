#include "filterutils.h"
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>

namespace FilterUtils {

inline std::uint8_t floatToUint8(float x) {
    return round(x * 255.f);
}

// getPixelRepeated(), getPixelReflected(), and getPixelWrapped() all
// have the same input arguments:
//
// data   - the image's data
// width  - the image's width
// height - the image's height
// x      - the x coordinate of the pixel you're attempting to access
// y      - the y coordinate of the pixel you're attempting to access

// Repeats the pixel on the edge of the image such that A,B,C,D looks like ...A,A,A,B,C,D,D,D...
RGBA getPixelRepeated(std::vector<RGBA> &data, int width, int height, int x, int y) {
    int newX = (x < 0) ? 0 : std::min(x, width  - 1);
    int newY = (y < 0) ? 0 : std::min(y, height - 1);
    return data[width * newY + newX];
}

// Flips the edge of the image such that A,B,C,D looks like ...C,B,A,B,C,D,C,B...
RGBA getPixelReflected(std::vector<RGBA> &data, int width, int height, int x, int y) {
    // Task 12: implement this function

    return RGBA{0, 0, 0, 255};
}

// Wraps the image such that A,B,C,D looks like ...C,D,A,B,C,D,A,B...
RGBA getPixelWrapped(std::vector<RGBA> &data, int width, int height, int x, int y) {
    int newX = (x < 0) ? x + width  : x % width;
    int newY = (y < 0) ? y + height : y % height;
    return data[width * newY + newX];
}

// Assumes the input kernel is square, and has an odd-numbered side length
void convolve2D(std::vector<RGBA> &data, int width, int height, const std::vector<float> &kernel) {
    // Task 9: initialize a vector, called `result`, to temporarily store your output image data

    // Task 10: obtain the kernel's dimensions

    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            size_t centerIndex = r * width + c;

            // Task 11:
            // 1. Initialize redAcc, greenAcc, and blueAcc float variables
            // 2. Iterate over the kernel using its dimensions from task 10.
            //    - Get the value, called `weight`, of the kernel at some position.
            //      - Remember that we're doing convolution, so we must "flip" the
            //        given kernel. How can you do that through (clever) indexing?
            //    - Get the value, called `pixel`, of the corresponding pixel in the canvas.
            // 3. Accumulate `weight * pixel` for each channel in redAcc, greenAcc, and blueAcc accordingly

            // Task 13: Update buffer with the new RGBA pixel value created from
            //          redAcc, greenAcc, and blueAcc
        }
    }

    // Task 14: Copy the RGBA data from `result` (task 9) to `data`
}

}

