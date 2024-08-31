#include "canvas2d.h"
#include "filterutils.h"

void Canvas2D::filterBrighten() {
    for (int row = 0; row < m_canvasH; ++row) {
        for (int col = 0; col < m_canvasW; ++col) {
            size_t currentIndex = m_canvasW * row + col;
            RGBA &currentPixel = m_data[currentIndex];

            // Task 6: Multiply the color channels of currentPixel by 1.3

            // Task 7: Convert currentPixel to an RGBAf struct and perform the multiplication here instead

            // Task 8: Use the toRGBA() method to convert the final pixel back to RGBA
        }
    }
}
