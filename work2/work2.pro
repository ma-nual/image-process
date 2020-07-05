#-------------------------------------------------
#
# Project created by QtCreator 2019-10-07T20:34:39
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = work2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    GLCM.cpp


INCLUDEPATH +=D:/Qt/mingw2/install/include/opencv
INCLUDEPATH +=D:/Qt/mingw2/install/include/opencv2
INCLUDEPATH +=D:/Qt/mingw2/install/include
LIBS +=-L D:/Qt/mingw2/install/x86/mingw/lib/libopencv_nonfree2411.dll.a
LIBS +=-L D:/Qt/mingw2/install/x86/mingw/lib/libopencv_calib3d2411.dll.a
LIBS +=-L D:/Qt/mingw2/install/x86/mingw/lib/libopencv_features2d2411.dll.a
LIBS +=-L D:/Qt/mingw2/install/x86/mingw/lib/libopencv_*.a

HEADERS += \
    GLCM.h
