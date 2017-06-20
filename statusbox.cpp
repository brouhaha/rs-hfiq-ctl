#include "statusbox.h"

StatusBox::StatusBox(RadioInterface *radio_interface) : QWidget()
{
  this->radio_interface = radio_interface;

  hbox = new QHBoxLayout;

  status_label = new QLabel(tr("RS-HFIQ Status:"));
  hbox->addWidget(status_label);
  status_text = new QLineEdit();
  status_text->setPlaceholderText("Text");
  status_text->setReadOnly(true);
  hbox->addWidget(status_text);
  hbox->addStretch();

  setLayout(hbox);
}

StatusBox::~StatusBox()
{
  delete status_label;
  delete status_text;

  delete hbox;
}
