cmake_minimum_required(VERSION 3.16)

# Sets project name
project(lab06 LANGUAGES CXX C)

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

# Allows you to include files from within those directories, without prefixing their filepaths
include_directories(src)

# Specifies .cpp and .h files to be passed to the compiler
add_executable(${PROJECT_NAME}
  src/main.cpp
  
  src/mainwindow.cpp
  src/settings.cpp
  src/canvas2d.cpp
  src/filters/filtersobel.cpp
  src/filters/filteridentity.cpp
  src/filters/filtershift.cpp
  src/filters/filterutils.cpp
  
  src/mainwindow.h
  src/settings.h
  src/RGBA.h
  src/canvas2d.h
  src/filters/filterutils.h

)

# Specifies other files
qt_add_resources(${PROJECT_NAME} "Resources"
  PREFIX
  "/"
  FILES
  resources/amongus.jpg
  resources/capybara.jpeg
  resources/graphics_meme.png
  resources/mona_lisa.jpg
  resources/rtx_meme.jpeg
  resources/wimdy.jpg
)

# Specifies libraries to be linked (Qt components, glew, etc)
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
