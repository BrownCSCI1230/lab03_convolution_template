#include "canvas2d.h"
#include "filterutils.h"

std::vector<float> createShiftKernel(ShiftDirection shiftDir, int num) {
    std::vector<float> kernel;

    // [Optional] Implement this function that creates a shift kernel
    //            which can shift an image by `num` pixels

    return kernel; // Note: this creates and returns a copy
}

void Canvas2D::filterShift(ShiftDirection shiftDir) {
    // Task 16: Create your shift kernel, depending on shiftDir. Alternatively, you
    //          may implement and call createShiftKernel().
    //
    // Remember:
    // - we're doing convolution, not correlation, and
    // - your kernel must be square, with an odd-numbered side length

    // Task 17: Using the kernel you made in task 15 and the Canvas2D's
    //          canvas data, call FilterUtils::convolve2D()
}
