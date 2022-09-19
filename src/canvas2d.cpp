#include <vector>
#include <cstdint>
#include <iostream>

#include "canvas2d.h"

/**
 * @brief Assigns m_image as a black 500x500 image.
 */
void Canvas2D::loadBlackImage() {
    m_data.assign(250000, RGBA{0, 0, 0, 255});
    m_canvasW = 500;
    m_canvasH = 500;
    this->displayImage();
}

void Canvas2D::filterImage() {
    // Task 1: Call the appropriate filter function depending
    //         on the settings
}

/**
 * @brief Stores the image specified from the input file in this class's
 * `std::vector<RGBA> m_image` as well as in Canvas2D's `std::vector<RGBA> m_image`.
 * Also saves the image width and height to m_canvasW and m_canvasH respectively.
 * @param file: file path to an image
 * @return True if successfully loads image, False otherwise.
 */
bool Canvas2D::loadImageFromFile(const QString &file){
    QImage myImage;
    if (!myImage.load(file)) {
        std::cout<<"Failed to load in image"<<std::endl;
        return false;
    }
    myImage = myImage.convertToFormat(QImage::Format_RGBX8888);
    QByteArray arr = QByteArray::fromRawData((const char*) myImage.bits(), myImage.sizeInBytes());
    m_data.clear();
    for (int i = 0; i < arr.size() / 4; i++){
        m_data.push_back(RGBA{(std::uint8_t) arr[4*i], (std::uint8_t) arr[4*i+1], (std::uint8_t) arr[4*i+2], (std::uint8_t) arr[4*i+3]});
    }
    m_canvasW = myImage.width();
    m_canvasH = myImage.height();
    this->displayImage();
    return true;
}

/**
 * @brief Get Canvas2D's image data and display this to the GUI
 */
void Canvas2D::displayImage() {
    QByteArray img(reinterpret_cast<const char*>(m_data.data()), 4*m_data.size());
    QImage now = QImage((const uchar*)img.data(), getWidth(), getHeight(), QImage::Format_RGBX8888);
    this->setPixmap(QPixmap::fromImage(now));
    this->setFixedSize(m_canvasW, m_canvasH);
    this->update();
}
