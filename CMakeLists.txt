cmake_minimum_required(VERSION 2.8.11)

project(testproject)


# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON) 

# Find the QtWidgets library
find_package(Qt5Widgets)

# Find the OpenCV library
find_package( OpenCV REQUIRED )

# Find the ITK library
find_package(ITK REQUIRED)

include(${ITK_USE_FILE})
include_directories( ${OpenCV_INCLUDE_DIRS} )


# Tell CMake to create the helloworld executable
add_executable(helloworld main.cpp mainwindow.cpp)

# Use the Widgets module from Qt 5.
target_link_libraries(helloworld Qt5::Widgets ${OpenCV_LIBS} ITKCommon)

