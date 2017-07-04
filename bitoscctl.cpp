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

BitOscCtl::BitOscCtl(RadioInterface *radio_interface) :
  OscCtl(std::string("BIT"), 'B', radio_interface)
{
  set_label = new QLabel(tr("Set to"));
  vbox->addWidget(set_label);
  
  hbox2 = new QHBoxLayout;

  set_lo_plus_1khz  = new QPushButton(tr("LO Freq + 1kHz"));
  hbox2->addWidget(set_lo_plus_1khz);
  set_lo            = new QPushButton(tr("LO Freq"));
  hbox2->addWidget(set_lo);
  set_lo_minus_1khz = new QPushButton(tr("LO Freq - 1kHz"));
  hbox2->addWidget(set_lo_minus_1khz);

  vbox->addLayout(hbox2);
}

BitOscCtl::~BitOscCtl()
{
  delete set_label;
  delete set_lo_plus_1khz;
  delete set_lo;
  delete set_lo_minus_1khz;

  delete hbox2;
}
