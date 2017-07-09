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

#include "firmwarectl.h"

FirmwareCtl::FirmwareCtl(RadioInterface *radio_interface) : QWidget()
{
  this->radio_interface = radio_interface;
  refresh_in_progress = false;

  hbox = new QHBoxLayout;

  firmware_label = new QLabel(tr("Firmware:"));
  hbox->addWidget(firmware_label);
  firmware_text = new QLineEdit();
  firmware_text->setPlaceholderText("Text");
  firmware_text->setReadOnly(true);
  hbox->addWidget(firmware_text);
  hbox->addStretch();

  setLayout(hbox);

  refresh();
}

FirmwareCtl::~FirmwareCtl()
{
  delete firmware_label;
  delete firmware_text;

  delete hbox;
}

void FirmwareCtl::refresh()
{
  refresh_in_progress = true;
  firmware_text->setText(QString::fromStdString(radio_interface->send_command("*W")));
  refresh_in_progress = false;
}
