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
