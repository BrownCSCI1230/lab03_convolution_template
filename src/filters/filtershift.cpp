#include "canvas2d.h"
#include "filterutils.h"

void createShiftKernel(ShiftDirection shiftDir, std::vector<float> &kernel, int num) {
    // [Optional] Implement this function that creates a shift kernel that shifts an image
    // by `num` pixels
}

void Canvas2D::filterShift(ShiftDirection shiftDir) {
    // Task 14: Create your shift kernel depending on shiftDir

    // Task 15: Using the kernel you made in task 15 and the Canvas2D's
    //          canvas data, call FilterUtils::Convolve2D()
}
