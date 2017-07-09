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
		   this, & OscCtl::on_enable_stateChanged);
  vbox->addWidget(osc_enable);

  fc = new CFreqCtrl();
  fc->setup(8, min_freq, max_freq, 1, FCTL_UNIT_HZ);
  QObject::connect(fc, & CFreqCtrl::newFrequency,
		   this, & OscCtl::on_newFrequency);
  vbox->addWidget(fc);

  setLayout(vbox);

  refresh_in_progress = false;

  refresh();
}

OscCtl::~OscCtl()
{
  delete osc_enable;
  delete fc;

  delete vbox;
}

uint32_t OscCtl::get_frequency()
{
  return freq;
}

void OscCtl::set_frequency(uint32_t frequency)
{
  freq = frequency;
  std::string cmd = std::string("*") + this->cmd_id + std::to_string(freq);
  radio_interface->send_command_no_reply(cmd);
  fc->setFrequency(this->freq);
}

void OscCtl::refresh_frequency()
{
  refresh_in_progress = true;
  std::string cmd = std::string("*") + this->cmd_id + "?";
  freq = std::stoi(radio_interface->send_command(cmd));
  fc->setFrequency(freq);
  refresh_in_progress = false;
}

void OscCtl::refresh()
{
  refresh_frequency();
}

void OscCtl::on_enable_stateChanged(int state)
{
  if (refresh_in_progress)
    return;
  
  std::string cmd = std::string("*O") + this->cmd_id + (state ? "2" : "0");
  radio_interface->send_command_no_reply(cmd);
}

void OscCtl::on_newFrequency(qint64 freq)
{
  if (refresh_in_progress)
    return;

  set_frequency(freq);
}
