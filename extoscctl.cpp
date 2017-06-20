#include "extoscctl.h"

ExtOscCtl::ExtOscCtl(RadioInterface *radio_interface) : QGroupBox(tr("EXT Oscillator Control"))
{
  this->radio_interface = radio_interface;

  hbox = new QHBoxLayout;

  vbox1 = new QVBoxLayout;
  ext_freq_label = new QLabel(tr("EXT Frequency (Hz)"));
  vbox1->addWidget(ext_freq_label);
  ext_freq = new QSpinBox();
  ext_freq->setRange(3000000, 29999999);
  ext_freq->setValue(3000000);
  ext_freq->setGroupSeparatorShown(true);
  vbox1->addWidget(ext_freq);
  hbox->addLayout(vbox1);
  
  ext_on = new QPushButton(tr("EXT ON"));
  hbox->addWidget(ext_on);
  ext_off = new QPushButton(tr("EXT OFF"));
  hbox->addWidget(ext_off);

  setLayout(hbox);
}

ExtOscCtl::~ExtOscCtl()
{
  delete ext_freq_label;
  delete ext_freq;
  delete ext_on;
  delete ext_off;

  delete vbox1;
  delete hbox;
}
