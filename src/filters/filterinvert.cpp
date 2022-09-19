#include "canvas2d.h"
#include "filterutils.h"

void Canvas2D::filterInvert() {

    // For each row
    for (int r = 0; r < m_canvasH; ++r) {
        size_t currentIndex = r * m_canvasW;
        RGBA &currentPixel = m_data[currentIndex];

        // For each column
        for (int c = 0; c < m_canvasW; ++c) {
            // Task 5: Update the pixel's colors with its inversion

            // Advance to the next pixel
            currentIndex++;
            currentPixel = m_data[currentIndex];
        }
    }
}
