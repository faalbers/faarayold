#-------------------------------------------------
#
# Project created by QtCreator 2014-05-10T21:58:28
#
#-------------------------------------------------

QT       -= gui

TARGET = faaray
TEMPLATE = lib

DEFINES += FAARAY_LIBRARY

SOURCES += faaray.cpp \
    renderjob.cpp

HEADERS += faaray.h\
        faaray_global.h \
    renderjob.h

unix {
    target.path = $$PWD/../inst/lib
    headers.path = $$PWD/../inst/include/faaray
    headers.files = *.h
    INSTALLS += target headers
}

win32 {
    target.path = $$PWD/../inst/lib
    headers.path = $$PWD/../inst/include/faaray
    headers.files = *.h
    INSTALLS += target headers
}

