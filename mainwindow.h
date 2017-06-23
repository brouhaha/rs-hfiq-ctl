// Copyright 2017 Eric Smith

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "radiointerface.h"

#include "statusbox.h"
#include "vfooscctl.h"
#include "bitoscctl.h"
#include "extoscctl.h"

#include "tempctl.h"

#include "freqoffsetctl.h"

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(RadioInterface *radio_interface);
    ~MainWindow();

private slots:
    void about();

private:
    RadioInterface *radio_interface;

    void createActions();
    void createMenus();

    QMenu *fileMenu;

    QAction *exitAct;
    QAction *aboutAct;

    QVBoxLayout *vbox;

    StatusBox *status_box;

    VFOOscCtl *vfo_osc_ctl;
    BitOscCtl *bit_osc_ctl;
    ExtOscCtl *ext_osc_ctl;

    TempCtl *temp_ctl;

    FreqOffsetCtl *freq_offset_ctl;
};

#endif // MAINWINDOW_H
