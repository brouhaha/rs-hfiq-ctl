#include "bitoscctl.h"

BitOscCtl::BitOscCtl(RadioInterface *radio_interface) : QGroupBox(tr("BIT Oscillator Control"))
{
  this->radio_interface = radio_interface;

  hbox = new QHBoxLayout;

  vbox1 = new QVBoxLayout;
  set_lo_plus_1khz  = new QPushButton(tr("Set BIT to LO Freq + 1kHz"));
  vbox1->addWidget(set_lo_plus_1khz);
  set_lo            = new QPushButton(tr("Set BIT to LO Freq"));
  vbox1->addWidget(set_lo);
  set_lo_minus_1khz = new QPushButton(tr("Set BIT to LO Freq - 1kHz"));
  vbox1->addWidget(set_lo_minus_1khz);
  hbox->addLayout(vbox1);

  vbox2 = new QVBoxLayout;
  bit_freq_label = new QLabel(tr("BIT Frequency (Hz)"));
  vbox2->addWidget(bit_freq_label);
  bit_freq = new QSpinBox();
  bit_freq->setRange(3000000, 29999999);
  bit_freq->setValue(3000000);
  bit_freq->setGroupSeparatorShown(true);
  vbox2->addWidget(bit_freq);
  hbox->addLayout(vbox2);

  bit_enable = new QCheckBox(tr("BIT Enable"));
  hbox->addWidget(bit_enable);

  setLayout(hbox);
}

BitOscCtl::~BitOscCtl()
{
  delete set_lo_plus_1khz;
  delete set_lo;
  delete set_lo_minus_1khz;
  delete bit_freq_label;
  delete bit_freq;
  delete bit_enable;

  delete vbox1;
  delete vbox2;
  delete hbox;
}
