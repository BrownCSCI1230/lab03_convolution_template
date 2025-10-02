#pragma once

#include <QLabel>
#include "RGBA.h"
#include "settings.h"

enum ShiftDirection {
    SHIFT_LEFT,
    SHIFT_RIGHT
};

class Canvas2D : public QLabel {
    Q_OBJECT
public:
    bool loadImageFromFile(const QString &file);
    void loadBlackImage();
    void displayImage();

    int getWidth() { return m_canvasW; }
    int getHeight() { return m_canvasH; }
    std::vector<RGBA> &getImage() { return m_data; }

    // Stencil provided for Sobel Filtering (No TODOs)
    void filterGrayscale(); // Edge detection requires a grayscale image!
    float sobelSensitivity = 0.9; // Applied before clamping Sobel outputs

    // TODO: Implement the functions below
    void applyFilter();
    void filterIdentity();
    void filterShift(ShiftDirection shiftDir);
    void filterSobel();

protected:
    std::vector<RGBA> m_data; // Image data; used in filter implementations
    int m_canvasW; // Canvas width
    int m_canvasH; // Canvas height
};
