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
  
  ext_enable = new QCheckBox(tr("EXT Enable"));
  hbox->addWidget(ext_enable);

  setLayout(hbox);
}

ExtOscCtl::~ExtOscCtl()
{
  delete ext_freq_label;
  delete ext_freq;
  delete ext_enable;

  delete vbox1;
  delete hbox;
}
