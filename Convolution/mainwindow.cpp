#include "mainwindow.h"
#include "canvas2d.h"
#include "iostream"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>

/**
 * @brief Parses command line arguments
 */
void MainWindow::parseCLIAndLoadSettings(QStringList args) {
    std::string filtertype = "";
    if (args.count() > 1) {
        filtertype = args.at(1).toStdString();
    }

    FilterType ft = FILTER_NONE;
    if (filtertype == "grayscale") {
        filterType_label->setText("Grayscale Filter");
        ft = FILTER_GRAYSCALE;
    }
    else if (filtertype == "identity") {
        filterType_label->setText("Identity Filter");
        ft = FILTER_IDENTITY;
    }
    else if (filtertype == "invert") {
        filterType_label->setText("Invert Filter");
        ft = FILTER_INVERT;
    }
    else if (filtertype == "shiftLeft") {
        filterType_label->setText("Shift Left Filter");
        ft = FILTER_SHIFT_LEFT;
    }
    else if (filtertype == "shiftRight") {
        filterType_label->setText("Shift Right Filter");
        ft = FILTER_SHIFT_RIGHT;
    } else {
        std::cout << "Unknown Filter type: " << filtertype << std::endl;
    }

    settings.loadSettingsOrDefaults(ft);
    m_imagePath = settings.lastSelectedImage;
    if (!m_imagePath.isEmpty()) {
        QFileInfo fi(m_imagePath);
        imageName_label->setText(fi.fileName());
        m_canvas->loadImageFromFile(m_imagePath);
    }
}

/**
 * @brief Sets up SupportCanvas2D and loads in saved settings if it exists
 */
void MainWindow::setupCanvas2D() {
    m_canvas = new Canvas2D();
    m_canvas->loadBlackImage();
}

/**
 * @brief Sets up the GUI
 */
void MainWindow::setupUI() {
    // Create layouts
    QVBoxLayout *vLayout = new QVBoxLayout();
    QHBoxLayout *hLayout = new QHBoxLayout();
    vLayout->setAlignment(Qt::AlignTop);
    vLayout->addLayout(hLayout);
    this->setLayout(vLayout);

    // Fonts for text
    QFont header;
    header.setPointSize(24);
    header.setBold(true);
    QFont italics;
    italics.setPointSize(14);
    italics.setItalic(true);

    // Create Labels
    filterType_label = new QLabel();
    filterType_label->setText("No Filter Selected");
    filterType_label->setFont(header);
    imageName_label = new QLabel();
    imageName_label->setText("(No image selected)");
    imageName_label->setFont(italics);

    // Create Buttons
    filter_button = new QPushButton();
    filter_button->setText("Apply Filter");
    revert_button = new QPushButton();
    revert_button->setText("Revert to Original Image");
    upload_button = new QPushButton();
    upload_button->setText("Choose Image");

    // Connect Buttons
    connectButtons();

    // Add all UI elements to layouts
    hLayout->addWidget(imageName_label, 0, Qt::AlignCenter);
    hLayout->addWidget(filterType_label, 0, Qt::AlignCenter);
    hLayout->addWidget(upload_button, 0, Qt::AlignCenter);
    vLayout->addWidget(m_canvas, 1, Qt::AlignCenter);
    vLayout->addWidget(filter_button);
    vLayout->addWidget(revert_button, 0, Qt::AlignCenter);
}

/**
 * @brief Connects all GUI elements that need connecting
 */
void MainWindow::connectButtons() {
    connect(filter_button, &QPushButton::clicked, this, &MainWindow::onFilterButtonClick);
    connect(revert_button, &QPushButton::clicked, this, &MainWindow::onRevertButtonClick);
    connect(upload_button, &QPushButton::clicked, this, &MainWindow::onUploadButtonClick);
}

/**
 * @brief Called when the Filter button is clicked. Filters and displays
 * the filtered image.
 */
void MainWindow::onFilterButtonClick() {
    m_canvas->filterImage();
    m_canvas->displayImage();
}

/**
 * @brief Called when the Revert button is clicked. Reverts and displays
 * the original image.
 */
void MainWindow::onRevertButtonClick() {
    m_canvas->loadImageFromFile(m_imagePath);
    m_canvas->displayImage();
}

/**
 * @brief Called when the Upload Image button is clicked. Opens
 * a QFileDialog that allows user to select an image to upload.
 */
void MainWindow::onUploadButtonClick() {
    // Get new image path selected by user
    QString file = QFileDialog::getOpenFileName(this, tr("Open Image"), QDir::homePath(), tr("Image Files (*.png *.jpg *.jpeg)"));
    if (file.isEmpty()) { return; }
    m_imagePath = file;

    // Update image name QLabel
    QFileInfo fi(m_imagePath);
    imageName_label->setText(fi.fileName());

    // Display new image
    m_canvas->loadImageFromFile(m_imagePath);

    // Save settings
    settings.lastSelectedImage = m_imagePath;
    settings.saveSettings();
}
