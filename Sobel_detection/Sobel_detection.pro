#-------------------------------------------------
#
# Project created by QtCreator 2019-12-06T20:47:45
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Sobel_detection
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

INCLUDEPATH +=D:/Qt/mingw2/install/include/opencv
INCLUDEPATH +=D:/Qt/mingw2/install/include/opencv2
INCLUDEPATH +=D:/Qt/mingw2/install/include
LIBS +=-L D:/Qt/mingw2/install/x86/mingw/lib/libopencv_nonfree2411.dll.a
LIBS +=-L D:/Qt/mingw2/install/x86/mingw/lib/libopencv_calib3d2411.dll.a
LIBS +=-L D:/Qt/mingw2/install/x86/mingw/lib/libopencv_features2d2411.dll.a
LIBS +=-L D:/Qt/mingw2/install/x86/mingw/lib/libopencv_*.a
