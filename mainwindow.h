// Control panel application for RS-HFIQ SDR transceiver
// Copyright 2017 Eric Smith <spacewar@gmail.com>

// This program is free software: you can redistribute it and/or modify
// it under the terms of version 3 of the GNU General Public License
// as published by the Free Software Foundation.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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
