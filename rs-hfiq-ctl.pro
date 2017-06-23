QT       += core gui widgets serialport

CONFIG += debug c++11 windeployqt

TARGET = rs-hfiq-ctl
TEMPLATE = app

SOURCES += main.cpp \
    radiointerface.cpp \
    serialportchooser.cpp \
    mainwindow.cpp \
    statusbox.cpp \
    oscctl.cpp \
    vfooscctl.cpp \
    bitoscctl.cpp \
    extoscctl.cpp \
    tempctl.cpp \
    freqoffsetctl.cpp

HEADERS += \
    mainwindow.h \
    radiointerface.h \
    serialportchooser.h \
    statusbox.h \
    oscctl.h \
    vfooscctl.h \
    bitoscctl.h \
    extoscctl.h \
    tempctl.h \
    freqoffsetctl.h

