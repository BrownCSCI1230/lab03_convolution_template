#include "canvas2d.h"
#include "filterutils.h"

void Canvas2D::filterIdentity() {
    // Task 12: We have created an identity kernel and called your FilterUtils::convolve2D()
    //          with it. However, the identity kernel is not returning the original image.
    //          Fix this code such that convolving with the identity kernel returns the original image.

    std::vector<float> kernel = {
      0,    0,    0,
      0,  1/9.f,  0,
      0,    0,    0
    };

    FilterUtils::convolve2D(m_data, m_canvasW, m_canvasH, kernel);
}
