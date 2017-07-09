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

#include <QGroupBox>
#include <QMessageBox>
#include <QMenuBar>
#include <QPushButton>

#include "mainwindow.h"

MainWindow::MainWindow(RadioInterface *radio_interface)
{
  this->radio_interface = radio_interface;

  QWidget *central = new QWidget(this);

  // have to get firmware version early
  firmware_ctl = new FirmwareCtl(this->radio_interface);

  vbox = new QVBoxLayout;

  vfo_osc_ctl = new VFOOscCtl(this->radio_interface);
  vbox->addWidget(vfo_osc_ctl);

  bit_osc_ctl = new BitOscCtl(this->radio_interface, vfo_osc_ctl);
  vbox->addWidget(bit_osc_ctl);

  ext_osc_ctl = new ExtOscCtl(this->radio_interface);
  vbox->addWidget(ext_osc_ctl);

  // XXX check firmware version to determine whether there are
  // temperature compensation settings.
  temp_ctl = new TempCtl(this->radio_interface, true);
  vbox->addWidget(temp_ctl);

  freq_offset_ctl = new FreqOffsetCtl(this->radio_interface);
  vbox->addWidget(freq_offset_ctl);

  vbox->addWidget(firmware_ctl);

  vbox->addStretch();

  central->setLayout(vbox);
  setCentralWidget(central);

  createActions();
  createMenus();
}

MainWindow::~MainWindow()
{
  delete vfo_osc_ctl;
  delete bit_osc_ctl;
  delete ext_osc_ctl;
  delete freq_offset_ctl;
  delete temp_ctl;
  delete firmware_ctl;

  delete vbox;
}

void MainWindow::about()
{
  QMessageBox::about(this, tr("About rs-hfiq-ctl"),
		     tr("This program controls the "
			"HobbyPCB RS-HFIQ Software Defined Radio."));
}

void MainWindow::createActions()
{
  exitAct = new QAction(tr("E&xit"), this);
  exitAct->setShortcuts(QKeySequence::Quit);
  exitAct->setStatusTip(tr("Exit the application"));
  connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

  aboutAct = new QAction(tr("&About"), this);
  aboutAct->setStatusTip(tr("About this application"));
  connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
}

void MainWindow::createMenus()
{
  fileMenu = menuBar()->addMenu(tr("&File"));
  fileMenu->addAction(aboutAct);
  fileMenu->addSeparator();
  fileMenu->addAction(exitAct);
}
