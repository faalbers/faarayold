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
    renderjob.cpp \
    viewplane.cpp \
    scene.cpp \
    tracethread.cpp \
    testscenes.cpp \
    camera.cpp \
    pinholecamera.cpp \
    geometricobject.cpp \
    sphere.cpp \
    light.cpp \
    pointlight.cpp \
    sampler.cpp \
    regularsampler.cpp \
    tracer.cpp \
    raycasttracer.cpp

HEADERS += faaray.h\
        faaray_global.h \
    renderjob.h \
    viewplane.h \
    scene.h \
    tracethread.h \
    testscenes.h \
    camera.h \
    pinholecamera.h \
    geometricobject.h \
    sphere.h \
    light.h \
    pointlight.h \
    sampler.h \
    regularsampler.h \
    tracer.h \
    raycasttracer.h

QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS += -fvisibility=hidden

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


unix|win32: LIBS += -L$$PWD/../inst/lib/ -lgfa

INCLUDEPATH += $$PWD/../inst/include
DEPENDPATH += $$PWD/../inst/include

warning($$PWD)
