QT       += core gui widgets serialport

CONFIG += debug c++11 windeployqt

TARGET = rs-hfiq-ctl
TEMPLATE = app

SOURCES += main.cpp \
    serialportchooser.cpp \
    mainwindow.cpp \
    bitoscctl.cpp \
    extoscctl.cpp

HEADERS += serialportchooser.h \
    mainwindow.h \
    bitoscctl.h \
    extoscctl.h

