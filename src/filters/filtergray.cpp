#include <cstdint>
#include "canvas2d.h"
#include "filterutils.h"

std::uint8_t rgbaToGray(const RGBA &pixel) {
    // Task 3: Calculate and return the gray value of the
    //         pixel using its RGB components.
    // Note: We are returning an std::uint8_t, because it is 1 byte
    //       and can store values from 0-255!

    return 0;
}

void Canvas2D::filterGray() {
    for (int row = 0; row < m_canvasH; ++row) {
        for (int col = 0; col < m_canvasW; ++col) {
            size_t currentIndex = m_canvasW * row + col;
            RGBA &currentPixel = m_data[currentIndex];

            // Task 2: call rgbaToGray()

            // Task 4: Update currentPixel's color
        }
    }
}
