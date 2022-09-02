#include "canvas2d.h"
#include "filterutils.h"

void Canvas2D::filterInvert() {
    int width = m_canvasW;
    RGBA* current_pixel = nullptr;
    size_t currentIndex = 0;

    for (int r = 0; r < m_canvasH; r++) {
        currentIndex = r * width;
        current_pixel = &m_data[currentIndex];

        for (int c = 0; c < m_canvasW; c++) {
            // Task 5: Update the pixel's colors with its inversion

            // Advance to the next pixel
            current_pixel++;
            currentIndex++;
        }
    }
}
