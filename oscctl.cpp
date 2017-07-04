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

#include "oscctl.h"

#include <QString>

OscCtl::OscCtl(std::string name,
	       char cmd_id,
	       RadioInterface *radio_interface,
	       uint32_t min_freq,
	       uint32_t max_freq) :
  QGroupBox(QString::fromStdString(name + std::string(" Oscillator")))
{
  this->radio_interface = radio_interface;
  this->cmd_id = cmd_id;
  this->min_freq = min_freq;
  this->max_freq = max_freq;

  vbox = new QVBoxLayout;

  osc_enable = new QCheckBox(tr("Enable"));
  QObject::connect(osc_enable, & QCheckBox::stateChanged,
		   this, & OscCtl::enable_state_changed);
  vbox->addWidget(osc_enable);

  hbox1 = new QHBoxLayout;
  freq_label = new QLabel(tr("Frequency (Hz)"));
  hbox1->addWidget(freq_label);
  freq_spinbox = new QSpinBox();
  freq_spinbox->setRange(min_freq, max_freq);
  freq_spinbox->setValue(min_freq);
  freq_spinbox->setGroupSeparatorShown(true);
  QObject::connect(freq_spinbox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
  		   this, & OscCtl::frequency_value_changed);
  hbox1->addWidget(freq_spinbox);
  hbox1->addStretch();
  vbox->addLayout(hbox1);

  setLayout(vbox);

  refresh_in_progress = false;

  refresh();
}

OscCtl::~OscCtl()
{
  delete osc_enable;
  delete freq_label;
  delete freq_spinbox;

  delete hbox1;
  delete vbox;
}

uint32_t OscCtl::get_frequency()
{
  return this->freq;
}

void OscCtl::refresh_frequency(void)
{
  refresh_in_progress = true;
  std::string cmd = std::string("*") + this->cmd_id + "?";
  this->freq = std::stoi(radio_interface->send_command(cmd));
  freq_spinbox->setValue(this->freq);
  refresh_in_progress = false;
}

void OscCtl::refresh(void)
{
  refresh_frequency();
}

void OscCtl::enable_state_changed(int state)
{
  if (! refresh_in_progress)
    {
      std::string cmd = std::string("*O") + this->cmd_id + (state ? "2" : "0");
      radio_interface->send_command_no_reply(cmd);
    }
}

void OscCtl::frequency_value_changed(int value)
{
  if (! refresh_in_progress)
    {
      std::string cmd = std::string("*") + this->cmd_id + std::to_string(value);
      radio_interface->send_command_no_reply(cmd);
    }
}
