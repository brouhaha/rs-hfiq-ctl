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

#include <iomanip> // setprecision()
#include <sstream> // stringstream

#include <QString>

#include "tempctl.h"

TempCtl::TempCtl(RadioInterface *radio_interface, bool has_comp):
  QGroupBox(tr("Temperature"))
{
  this->radio_interface = radio_interface;
  this->has_comp = has_comp;
  
  vbox = new QVBoxLayout;

  hbox1 = new QHBoxLayout;

  temp_label_1 = new QLabel(tr("Temperature:"));
  hbox1->addWidget(temp_label_1);

  temp_text_c = new QLineEdit();
  temp_text_c->setReadOnly(true);
  hbox1->addWidget(temp_text_c);

  temp_label_2 = new QLabel("°C,");
  hbox1->addWidget(temp_label_2);

  temp_text_f = new QLineEdit();
  temp_text_f->setReadOnly(true);
  hbox1->addWidget(temp_text_f);

  temp_label_3 = new QLabel("°F");
  hbox1->addWidget(temp_label_3);

  hbox1->addStretch();
  vbox->addLayout(hbox1);

  if (this->has_comp)
    {
      hbox2 = new QHBoxLayout;
      tc_label = new QLabel(tr("Compensation:"));
      hbox2->addWidget(tc_label);
      tc_disabled = new QRadioButton(tr("disabled"));
      QObject::connect(tc_disabled, & QRadioButton::toggled,
		       this, & TempCtl::on_tc_toggled);
      hbox2->addWidget(tc_disabled);
      tc_enabled  = new QRadioButton(tr("enabled"));
      QObject::connect(tc_enabled, & QRadioButton::toggled,
		       this, & TempCtl::on_tc_toggled);
      hbox2->addWidget(tc_enabled);
      tc_tcxo     = new QRadioButton(tr("TCXO"));
      QObject::connect(tc_tcxo, & QRadioButton::toggled,
		       this, & TempCtl::on_tc_toggled);
      hbox2->addWidget(tc_tcxo);
      hbox2->addStretch();
      vbox->addLayout(hbox2);
    }

  setLayout(vbox);

  refresh_in_progress = false;

  refresh();
}

TempCtl::~TempCtl()
{
  delete temp_label_1;
  delete temp_label_2;
  delete temp_label_3;
  delete temp_text_c;
  delete temp_text_f;

  if (this->has_comp)
    {
      delete tc_label;
      delete tc_disabled;
      delete tc_enabled;
      delete tc_tcxo;
      delete hbox2;
    }

  delete hbox1;
  delete vbox;
}

void TempCtl::refresh()
{
  refresh_temp();
  refresh_mode();
}

static float c_to_f(float c)
{
  return (c / 5.0) * 9.0 + 32.0;
}

static std::string ftos(float f)
{
  std::stringstream s;
  s << std::fixed << std::setprecision(1) << f;
  return s.str();
}

void TempCtl::refresh_temp()
{
  refresh_in_progress = true;
  temp_c = std::stof(radio_interface->send_command("*T?"));
  temp_text_c->setText(QString::fromStdString(ftos(temp_c)));
  temp_text_f->setText(QString::fromStdString(ftos(c_to_f(temp_c))));
  refresh_in_progress = false;
}

void TempCtl::refresh_mode()
{
  int mode;

  if (! has_comp)
    return;

  refresh_in_progress = true;
  mode = std::stoi(radio_interface->send_command("*A?"));
  switch (mode)
    {
    case 0: tc_disabled->setChecked(true); break;
    case 1: tc_enabled->setChecked(true); break;
    case 2: tc_tcxo->setChecked(true); break;
    }
  refresh_in_progress = false;
}

void TempCtl::on_tc_toggled(bool checked)
{
  if (refresh_in_progress)
    return;

  int val;
  if (tc_disabled->isChecked())
    val = 0;
  else if (tc_enabled->isChecked())
    val = 1;
  else if (tc_tcxo->isChecked())
    val = 2;
  else
    return; // should never happen

  std::string cmd = std::string("*O") + std::to_string(val);
  radio_interface->send_command_no_reply(cmd);
}
