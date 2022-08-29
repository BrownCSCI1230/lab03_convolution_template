#ifndef CANVAS2D_H
#define CANVAS2D_H

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

    void FilterGray(); // TODO
    void FilterInvert(); // TODO
    void FilterIdentity(); // TODO
    void FilterShift(ShiftDirection shiftDir); // TODO

protected:
    std::vector<RGBA> m_data; // image data; used in filter implementations
    int m_canvasW; // canvas width
    int m_canvasH; // canvas height
};

#endif // CANVAS2D_H
