#-------------------------------------------------
#
# Project created by QtCreator 2014-05-10T21:58:28
#
#-------------------------------------------------

QT       -= gui

TARGET = faaray
TEMPLATE = lib

DEFINES += FAARAY_LIBRARY

SOURCES += faaray.cpp

HEADERS += faaray.h\
        faaray_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
