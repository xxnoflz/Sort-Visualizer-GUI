# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = Sort Visualizer GUI
DESTDIR = ../x64/Debug
CONFIG += debug
LIBS += -L"." \
    -lopengl32
DEPENDPATH += .
MOC_DIR += .
OBJECTS_DIR += debug
UI_DIR += .
RCC_DIR += .
HEADERS += ./source/SortVisualizer GUI/SortVisualizerGUI.h \
    ./source/SortVisualizer GUI/Sort Visualizer/Sort Visualizer.h
SOURCES += ./source/main.cpp \
    ./source/SortVisualizer GUI/SortVisualizerGUI.cpp \
    ./source/SortVisualizer GUI/Sort Visualizer/Sort Visualizer.cpp
FORMS += ./source/SortVisualizer GUI/SortVisualizerGUI.ui
RESOURCES += source/SortVisualizer GUI/SortVisualizerGUI.qrc