#include "canvas2d.h"
#include "filterutils.h"
#include <cstdint>

/**
 *  This converts a given pixel's RGB values into one grayscale value using the Luma method.
 *  The Luma method is a common grayscale approach that calculates a weighted sum between the
 *  three color channels using percentages that account for the human perceptual system.
 */
std::uint8_t rgbaToGray(const RGBA &pixel) {
    return 0.299 * pixel.r + 0.587 * pixel.g + 0.114 * pixel.b;
}

/**
 *  Our provided implementation of a grayscale filter. This is a per-pixel filter,
 *  which means that the output value is independent of any neighboring pixel values
 *  (unlike in convolution, where output pixels *do* depend on surrounding pixels).
 */
void Canvas2D::filterGrayscale() {
    for (int row = 0; row < m_canvasH; ++row) {
        for (int col = 0; col < m_canvasW; ++col) {
            size_t currentIndex = m_canvasW * row + col;
            RGBA &currentPixel = m_data[currentIndex];

            auto intensity = rgbaToGray(currentPixel);

            currentPixel.r = intensity;
            currentPixel.g = intensity;
            currentPixel.b = intensity;
        }
    }
}

void Canvas2D::filterSobel() {
    // Task 11 (a): Create your two sobel kernels, Gx (for the x-direction derivative),
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

    // Task 11 (b): Apply the provided grayscale filter to your image. Then, using two copies of the image,
    //         call convolve2d() twice, once with each of the kernels that you created above.

    // Task 12: Loop over the image dimensions, and calculate the output pixel values (G) as
    //         described in the handout. Remember to apply the Sobel sensitivity parameter
    //         (found in canvas2d.h) *before* clamping the values.

}
