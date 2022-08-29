#include "settings.h"
#include <QFile>
#include <QSettings>
#include "iostream"

Settings settings;


/**
 * @brief Loads the application settings and sets filterType from
 * command line input
 */
void Settings::loadSettingsOrDefaults(FilterType ft) {
    /// Set Filter
    filterType = ft;

    /// Load image settings
    QSettings s("CS123", "CS123");
    lastSelectedImage = s.value("selectedImage", "").toString();
}

/**
 * @brief Saves settings from this session to be loaded
 * in for next session.
 */
void Settings::saveSettings() {
    QSettings s("CS123", "CS123");
    s.setValue("selectedImage", lastSelectedImage);
}
