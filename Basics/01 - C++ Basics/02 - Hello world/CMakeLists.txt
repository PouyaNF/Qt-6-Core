# Set the minimum required version of CMake for this project
cmake_minimum_required(VERSION 3.14)

# Define the project name and specify that it will use C++
project(qt6cb-3-1 LANGUAGES CXX)

# Include the current directory in the list of directories to search for header files
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Enable automatic processing of Qt-specific files
set(CMAKE_AUTOUIC ON)  # Automatically process Qt's .ui files
set(CMAKE_AUTOMOC ON) # Automatically run the Meta-Object Compiler (MOC) on C++ files
set(CMAKE_AUTORCC ON) # Automatically process Qt's .qrc files

# Set the C++ standard to C++11 and make it required
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find and configure Qt libraries; look for either Qt6 or Qt5
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)

# Find and configure the specific Qt version found in the previous step
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

# Create an executable named 'qt6cb-3-1' from the source file 'main.cpp'
add_executable(qt6cb-3-1
  main.cpp
)

# Link the executable with the Qt Core library
target_link_libraries(qt6cb-3-1 Qt${QT_VERSION_MAJOR}::Core)
