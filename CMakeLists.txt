cmake_minimum_required(VERSION 3.16)

# Sets project name
project(Convolution LANGUAGES CXX C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Sets C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specifies required Qt components
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Gui)

# Specifies .cpp and .h files to be passed to the compiler
add_executable(${PROJECT_NAME}
  Convolution/main.cpp
  Convolution/mainwindow.h
  Convolution/mainwindow.cpp
  Convolution/settings.h
  Convolution/settings.cpp
  Convolution/RGBA.h
  Convolution/canvas2d.h
  Convolution/canvas2d.cpp
  Convolution/filters/FilterGray.cpp
  Convolution/filters/FilterIdentity.cpp
  Convolution/filters/FilterInvert.cpp
  Convolution/filters/FilterShift.cpp
  Convolution/filters/filterutils.h
  Convolution/filters/filterutils.cpp
)

# Specifies other files
qt_add_resources(${PROJECT_NAME} "Resources"
  PREFIX
  "/"
  FILES
  Fun_Images/amongus.jpg
  Fun_Images/capybara.jpeg
  Fun_Images/graphics_meme.png
  Fun_Images/mona_lisa.jpg
  Fun_Images/rtx_meme.jpeg
  Fun_Images/wimdy.jpg
)

# Specifies libraries to be linked (Qt components, glew, glm, etc)
target_link_libraries(${PROJECT_NAME} PRIVATE
  Qt::Core
  Qt::Widgets
)

# Set this flag to silence warnings on Windows
if (MSVC OR MSYS OR MINGW)
  set(CMAKE_CXX_FLAGS "-Wno-volatile")
endif()

# Set this flag to silence warnings on MacOS
if (APPLE)
  set(CMAKE_CXX_FLAGS "-Wno-deprecated-volatile")
endif()
