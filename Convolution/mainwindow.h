#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "canvas2d.h"
#include <QLabel>
#include <QPushButton>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    void setupUI();
    void setupCanvas2D();
    void parseCLIAndLoadSettings(QStringList args);
    void displayImage();

private:
    QString m_imagePath;
    Canvas2D *m_canvas;

    QLabel *filterType_label;
    QLabel *imageName_label;
    QPushButton *filter_button;
    QPushButton *revert_button;
    QPushButton *upload_button;
    void connectButtons();
    void onFilterButtonClick();
    void onRevertButtonClick();
    void onUploadButtonClick();
};
#endif // MAINWINDOW_H
