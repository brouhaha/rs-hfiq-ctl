#include "bitoscctl.h"

BitOscCtl::BitOscCtl(RadioInterface *radio_interface) :
  OscCtl(std::string("BIT"), 'B', radio_interface,
	 1, 1024000, 112500000)
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
