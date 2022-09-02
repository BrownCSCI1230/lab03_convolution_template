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
    std::vector<RGBA> *getImage() { return &m_data; }

    // TODO: Implement the functions below
    void filterImage(); // TODO

    void filterGray(); // TODO
    void filterInvert(); // TODO
    void filterIdentity(); // TODO
    void filterShift(ShiftDirection shiftDir); // TODO

protected:
    std::vector<RGBA> m_data; // Image data; used in filter implementations
    int m_canvasW; // Canvas width
    int m_canvasH; // Canvas height
};
