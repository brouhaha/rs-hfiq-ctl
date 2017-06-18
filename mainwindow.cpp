// Copyright 2017 Eric Smith

#include <QGroupBox>
#include <QMessageBox>
#include <QMenuBar>
#include <QPushButton>
#include <QTextEdit>

#include "mainwindow.h"

MainWindow::MainWindow()
{
  QWidget *central = new QWidget(this);

  vbox = new QVBoxLayout;

  hbox1 = new QHBoxLayout;

  QGroupBox *status_box = new QGroupBox(tr("Status"));
  QVBoxLayout *status_layout = new QVBoxLayout;
  QPushButton *status_button = new QPushButton(tr("Stat"));
  status_layout->addWidget(status_button);
  status_box->setLayout(status_layout);

  hbox1->addWidget(status_box);

  vbox->addLayout(hbox1);

  bit_osc_ctl = new BitOscCtl();
  vbox->addWidget(bit_osc_ctl);

  ext_osc_ctl = new ExtOscCtl();
  vbox->addWidget(ext_osc_ctl);

  hbox2 = new QHBoxLayout;
  
  QGroupBox *act_temp_comp_box = new QGroupBox(tr("Active Temperature Compensation"));
  QVBoxLayout *act_temp_comp_layout = new QVBoxLayout;
  QPushButton *act_temp_comp_button = new QPushButton(tr("Act Temp Comp"));
  act_temp_comp_layout->addWidget(act_temp_comp_button);
  act_temp_comp_box->setLayout(act_temp_comp_layout);

  hbox2->addWidget(act_temp_comp_box);

  QGroupBox *fixed_freq_offset_box = new QGroupBox(tr("Fixed Frequency Offset"));
  QVBoxLayout *fixed_freq_offset_layout = new QVBoxLayout;
  QPushButton *fixed_freq_offset_button = new QPushButton(tr("Fixed Freq Offset"));
  fixed_freq_offset_layout->addWidget(fixed_freq_offset_button);
  fixed_freq_offset_box->setLayout(fixed_freq_offset_layout);

  hbox2->addWidget(fixed_freq_offset_box);

  vbox->addLayout(hbox2);

  central->setLayout(vbox);
  setCentralWidget(central);

  createActions();
  createMenus();
}

MainWindow::~MainWindow()
{
  delete bit_osc_ctl;
  delete ext_osc_ctl;
  delete hbox1;
  delete hbox2;
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
