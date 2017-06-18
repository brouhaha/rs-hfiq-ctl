// Copyright 2017 Eric Smith

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "bitoscctl.h"
#include "extoscctl.h"

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private slots:
    void about();

private:
    void createActions();
    void createMenus();

    QMenu *fileMenu;

    QAction *exitAct;
    QAction *aboutAct;

    QVBoxLayout *vbox;
    QHBoxLayout *hbox1;
    QHBoxLayout *hbox2;
    BitOscCtl *bit_osc_ctl;
    ExtOscCtl *ext_osc_ctl;
};

#endif // MAINWINDOW_H