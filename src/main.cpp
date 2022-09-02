#include "mainwindow.h"

#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    // Setting up the application
    QApplication a(argc, argv);

    // Create a MainWindow
    MainWindow w;
    w.resize(800, 600);
    w.setWindowTitle(QStringLiteral("Lab 3 Convolution"));
    int desktopArea = QGuiApplication::primaryScreen()->size().width() *
            QGuiApplication::primaryScreen()->size().height();
    int widgetArea = w.width() * w.height();

    // Setup MainWindow GUI (must be called in this order)
    w.setupCanvas2D();
    w.setupUI();
    w.parseCLIAndLoadSettings(QCoreApplication::arguments());

    // Display MainWindow
    if (((float)widgetArea / (float)desktopArea) < 0.75f)
        w.show();
    else
        w.showMaximized();
    return a.exec();
}
