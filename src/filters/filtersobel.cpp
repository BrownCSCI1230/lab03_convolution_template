#include "canvas2d.h"
#include "filterutils.h"

void Canvas2D::filterSobel() {
    // Task A: Create your two sobel kernels, Gx (for the x-direction derivative),
    //         and Gy (for the y-direction derivative).

    std::vector<float> Gx = {
        0,    0,    0,
        0,    0,    0,
        0,    0,    0
    };

    std::vector<float> Gy = {
        0,    0,    0,
        0,    0,    0,
        0,    0,    0
    };

    // Task B: Using two copies of your image, call convolve2d() twice, once with each
    //         of the kernels that you created above.

    // Task C: Loop over the image, and calculate the final output pixel values as
    //         described in the handout. Remember to apply the sensitivity parameter
    //         (found in settings.cpp) *before* clamping the values.

}
