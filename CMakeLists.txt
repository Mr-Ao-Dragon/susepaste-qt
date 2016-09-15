cmake_minimum_required(VERSION 3.4)
project(susepaste-qt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(CMAKE_AUTOMOC ON)

# Widgets finds its own dependencies (QtGui and QtCore).
find_package(Qt5Widgets REQUIRED)

# The Qt5Widgets_INCLUDES also includes the include directories for
# dependencies QtCore and QtGui
include_directories(${Qt5Widgets_INCLUDES})

# We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
add_definitions(${Qt5Widgets_DEFINITIONS})

# Executables fail to build with Qt 5 in the default configuration
# without -fPIE. We add that here.
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

set(SOURCE_FILES main.cpp ExpireModel.cpp ExpireModel.h ExpireListModel.cpp ExpireListModel.h SyntaxModel.cpp SyntaxModel.h SyntaxListModel.cpp SyntaxListModel.h MainWindow.cpp MainWindow.h)
add_executable(susepaste-qt ${SOURCE_FILES})

# The Qt5Widgets_LIBRARIES variable also includes QtGui and QtCore
target_link_libraries(susepaste-qt ${Qt5Widgets_LIBRARIES})

install( PROGRAMS susepaste-qt_paste.desktop DESTINATION /usr/share/kde4/services/ServiceMenus/)