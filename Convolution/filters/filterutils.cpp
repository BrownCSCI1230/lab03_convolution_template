#include "filterutils.h"
#include <algorithm>
#include "math.h"
#include <cstring>
#include <cstdlib>
#include <memory>
#include <iostream>
using namespace std;

namespace FilterUtils {

inline unsigned char REAL2byte(float f) {
    int i = static_cast<int>((f * 255.0 + 0.5));
    return (i < 0) ? 0 : (i > 255) ? 255 : i;
}

/**
 * @brief getPixelReplicated(), getPixelReflected(), and getPixelWrapped() all have the same
 * input parameters:
 *
 * data - original image data
 * width - image width
 * height - image height
 * row - the current row of the image
 * col - the current col of the image
 */
inline RGBA getPixelReplicated(std::vector<RGBA>* data, int width, int height, int row, int col) {
    int x = (col < 0) ? 0 : min(col, width-1);
    int y = (row < 0) ? 0 : min(row, height-1);
    RGBA replicated = (*data)[width*y + x];
    return replicated;
}

inline RGBA getPixelReflected(std::vector<RGBA>* data, int width, int height, int row, int col) {
    // [TODO] Task 9 -- Implement this function


}

inline RGBA getPixelWrapped(std::vector<RGBA>* data, int width, int height, int row, int col) {
    int x = (col < 0) ? col+width : col%width;
    int y = (row < 0) ? row+height : row%height;
    RGBA wrapped = (*data)[width*y + x];
    return wrapped;
}

void Convolve2D(std::vector<RGBA>* data, int width, int height, const std::vector<float> &kernel) {
    // [TODO]: Task 6 -- Initialize an array buffer to store new RGBA image data


    // [TODO]: Task 7 -- Obtain the kernel dimension


    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            size_t centerIndex = r * width + c;

            // [TODO]: Task 8
            //      1. Initialize red_acc, green_acc, and blue_acc float variables
            //      2. Iterate over the kernel using kernel dimensions from Task 7.
            //         - Get the value of the current kernel element.
            //         - Get the value of the corresponding RGBA pixel.
            //      3. Accumulate the kernel applied to pixel value in red_acc, green_acc, blue_acc



            // [TODO]: Task 10 -- Update buffer with the new RGBA pixel value created from
            //         red_acc, green_acc, and blue_acc


        }
    }

    // [TODO]: Task 11 -- Copy the RGBA data from `result` to `data`.
    //         Don't forget to delete result to prevent memory leaks!


}
}

