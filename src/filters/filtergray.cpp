#include <cstdint>
#include "canvas2d.h"
#include "filterutils.h"

std::uint8_t rgbaToGray(const RGBA &pixel) {
    // Task 3: Calculate and return the gray value of the
    //         pixel using its RGB components.
    // Note: We are returning an std::uint8_t because it is 1 byte
    //       which can store values from 0-255!

    return 0;
}

void Canvas2D::filterGray() {
    // For each row
    for (int r = 0; r < m_canvasH; ++r) {
        size_t currentIndex = r * m_canvasW;
        RGBA &currentPixel = m_data[currentIndex];

        // For each column
        for (int c = 0; c < m_canvasW; ++c) {

            // Task 2: call RGBAToGray()

            // Task 4: Update the currentPixel's color

            // Advance to the next pixel
            currentIndex++;
            currentPixel = m_data[currentIndex];
        }
    }
}
