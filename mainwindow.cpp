// Copyright 2017 Eric Smith

#include <QGroupBox>
#include <QMessageBox>
#include <QMenuBar>
#include <QPushButton>

#include "mainwindow.h"

MainWindow::MainWindow(RadioInterface *radio_interface)
{
  this->radio_interface = radio_interface;

  QWidget *central = new QWidget(this);

  vbox = new QVBoxLayout;

  status_box = new StatusBox(this->radio_interface);
  vbox->addWidget(status_box);

  vfo_osc_ctl = new VFOOscCtl(this->radio_interface);
  vbox->addWidget(vfo_osc_ctl);

  bit_osc_ctl = new BitOscCtl(this->radio_interface);
  vbox->addWidget(bit_osc_ctl);

  ext_osc_ctl = new ExtOscCtl(this->radio_interface);
  vbox->addWidget(ext_osc_ctl);

  temp_ctl = new TempCtl(this->radio_interface);
  vbox->addWidget(temp_ctl);

  freq_offset_ctl = new FreqOffsetCtl(this->radio_interface);
  vbox->addWidget(freq_offset_ctl);

  central->setLayout(vbox);
  setCentralWidget(central);

  createActions();
  createMenus();
}

MainWindow::~MainWindow()
{
  delete status_box;
  delete bit_osc_ctl;
  delete ext_osc_ctl;

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
