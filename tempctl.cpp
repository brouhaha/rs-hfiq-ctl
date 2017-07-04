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

#include "tempctl.h"

TempCtl::TempCtl(RadioInterface *radio_interface):
  QGroupBox(tr("Temperature"))
{
  this->radio_interface = radio_interface;
  vbox = new QVBoxLayout;

  hbox1 = new QHBoxLayout;
  temp_label = new QLabel(tr("Temperature:"));
  hbox1->addWidget(temp_label);
  temp_text = new QLineEdit();
  temp_text->setPlaceholderText("0");
  temp_text->setReadOnly(true);
  hbox1->addWidget(temp_text);
  hbox1->addStretch();
  vbox->addLayout(hbox1);

  hbox2 = new QHBoxLayout;
  tc_label = new QLabel(tr("Compensation:"));
  hbox2->addWidget(tc_label);
  tc_disabled = new QRadioButton(tr("disabled"));
  hbox2->addWidget(tc_disabled);
  tc_enabled  = new QRadioButton(tr("enabled"));
  hbox2->addWidget(tc_enabled);
  tc_tcxo     = new QRadioButton(tr("TCXO"));
  hbox2->addWidget(tc_tcxo);
  hbox2->addStretch();
  vbox->addLayout(hbox2);

  setLayout(vbox);
}

TempCtl::~TempCtl()
{
  delete temp_label;
  delete temp_text;
  delete tc_label;
  delete tc_disabled;
  delete tc_enabled;
  delete tc_tcxo;

  delete hbox1;
  delete hbox2;
  delete vbox;
}
