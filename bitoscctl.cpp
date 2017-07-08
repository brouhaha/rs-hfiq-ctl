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

#include "bitoscctl.h"

BitOscCtl::BitOscCtl(RadioInterface *radio_interface, OscCtl *vfo_osc_ctl) :
  OscCtl(std::string("BIT"), 'B', radio_interface)
{
  this->vfo_osc_ctl = vfo_osc_ctl;

  set_label = new QLabel(tr("Set to"));
  vbox->addWidget(set_label);
  
  hbox2 = new QHBoxLayout;

  btn_set_lo_minus_1khz = new QPushButton(tr("LO Freq - 1kHz"));
  QObject::connect(btn_set_lo_minus_1khz, &QPushButton::clicked,
		   this, & BitOscCtl::set_lo_minus_1khz);
  hbox2->addWidget(btn_set_lo_minus_1khz);

  btn_set_lo            = new QPushButton(tr("LO Freq"));
  QObject::connect(btn_set_lo, &QPushButton::clicked,
		   this, & BitOscCtl::set_lo);
  hbox2->addWidget(btn_set_lo);

  btn_set_lo_plus_1khz  = new QPushButton(tr("LO Freq + 1kHz"));
  QObject::connect(btn_set_lo_plus_1khz, &QPushButton::clicked,
		   this, & BitOscCtl::set_lo_plus_1khz);
  hbox2->addWidget(btn_set_lo_plus_1khz);

  vbox->addLayout(hbox2);
}

BitOscCtl::~BitOscCtl()
{
  delete set_label;
  delete btn_set_lo_minus_1khz;
  delete btn_set_lo;
  delete btn_set_lo_plus_1khz;

  delete hbox2;
}

void BitOscCtl::set_lo_minus_1khz()
{
  uint32_t lo = vfo_osc_ctl->get_frequency();
  set_frequency(lo - 1000);
}

void BitOscCtl::set_lo()
{
  uint32_t lo = vfo_osc_ctl->get_frequency();
  set_frequency(lo);
}

void BitOscCtl::set_lo_plus_1khz()
{
  uint32_t lo = vfo_osc_ctl->get_frequency();
  set_frequency(lo + 1000);
}

