#include "canvas2d.h"
#include "filterutils.h"

void Canvas2D::filterInvert() {
    for (int row = 0; row < m_canvasH; ++row) {
        for (int col = 0; col < m_canvasW; ++col) {
            size_t currentIndex = m_canvasW * row + col;
            RGBA &currentPixel = m_data[currentIndex];

            // Task 5: Update the pixel's colors with its inversion
        }
    }
}
