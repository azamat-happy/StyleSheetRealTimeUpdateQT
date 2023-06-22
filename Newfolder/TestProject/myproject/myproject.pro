#ACSS_OUT_ROOT = $$PWD/..
ACSS_OUT_ROOT = $${OUT_PWD}/..
QT += core gui widgets quickwidgets qml

CONFIG += c++14
CONFIG += debug_and_release

DESTDIR = $${ACSS_OUT_ROOT}/lib
TARGET = myproject
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mainwindowfirst.cpp

HEADERS += \
    mainwindow.h \
    mainwindowfirst.h

FORMS += \
    mainwindow.ui \
    mainwindowfirst.ui

RESOURCES +=

#DEFINES += "STYLES_DIR=$$PWD/../../../styles"

LIBS += -L$${ACSS_OUT_ROOT}/lib
include(../acss.pri)
INCLUDEPATH += ../src
DEPENDPATH += ../src

DISTFILES +=
