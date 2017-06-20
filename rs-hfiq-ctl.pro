QT       += core gui widgets serialport

CONFIG += debug c++11 windeployqt

TARGET = rs-hfiq-ctl
TEMPLATE = app

SOURCES += main.cpp \
    radiointerface.cpp \
    serialportchooser.cpp \
    mainwindow.cpp \
    statusbox.cpp \
    bitoscctl.cpp \
    extoscctl.cpp

HEADERS += \
    mainwindow.h \
    radiointerface.h \
    serialportchooser.h \
    statusbox.h \
    bitoscctl.h \
    extoscctl.h
