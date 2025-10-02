#pragma once

#include <QObject>
#include "RGBA.h"

// Enumeration values for the Filters that the user can select in the GUI.
enum FilterType { 
    FILTER_IDENTITY,
    FILTER_SHIFT_LEFT,
    FILTER_SHIFT_RIGHT,
    FILTER_SOBEL,
    FILTER_NONE /// Ignore this when implementing Convolution. This is used in the support code.
};

/**
 * @struct Settings
 *
 * Stores application settings for the CS123 GUI.
 *
 * You can access all app settings through the "settings" global variable.
 * The settings will be automatically updated when things are changed in the
 * GUI (the reverse is not true however: changing the value of a setting does
 * not update the GUI).
*/
struct Settings {
    void loadSettingsOrDefaults(FilterType ft);
    void saveSettings();
    QString lastSelectedImage;

    FilterType filterType; /// The selected filter @see FilterType
};

// The global Settings object, will be initialized by MainWindow
extern Settings settings;


