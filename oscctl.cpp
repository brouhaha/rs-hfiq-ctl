#include "oscctl.h"

#include <QString>

OscCtl::OscCtl(std::string name,
	       char cmd_id,
	       RadioInterface *radio_interface,
	       uint32_t freq_mult,
	       uint32_t min_freq,
	       uint32_t max_freq) :
  QGroupBox(QString::fromStdString(name + std::string(" Oscillator Control")))
{
  this->radio_interface = radio_interface;
  this->cmd_id = cmd_id;
  this->min_freq = min_freq;
  this->max_freq = max_freq;
  this->freq_mult = freq_mult;

  this->freq = min_freq;  // subclass should read current value from radio

  vbox = new QVBoxLayout;

  osc_enable = new QCheckBox(tr("Enable"));
  vbox->addWidget(osc_enable);

  hbox1 = new QHBoxLayout;
  freq_label = new QLabel(tr("Frequency (Hz)"));
  hbox1->addWidget(freq_label);
  freq_spinbox = new QSpinBox();
  freq_spinbox->setRange(min_freq, max_freq);
  freq_spinbox->setValue(min_freq);
  freq_spinbox->setGroupSeparatorShown(true);
  hbox1->addWidget(freq_spinbox);
  hbox1->addStretch();
  vbox->addLayout(hbox1);

  setLayout(vbox);
}

OscCtl::~OscCtl()
{
  delete osc_enable;
  delete freq_label;
  delete freq_spinbox;

  delete hbox1;
  delete vbox;
}

uint32_t OscCtl::get_freq()
{
  return this->freq;
}
