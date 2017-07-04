#include "statusbox.h"

StatusBox::StatusBox(RadioInterface *radio_interface) : QWidget()
{
  this->radio_interface = radio_interface;
  refresh_in_progress = false;

  hbox = new QHBoxLayout;

  firmware_label = new QLabel(tr("Firmware:"));
  hbox->addWidget(firmware_label);
  firmware_text = new QLineEdit();
  firmware_text->setPlaceholderText("Text");
  firmware_text->setReadOnly(true);
  hbox->addWidget(firmware_text);
  hbox->addStretch();

  setLayout(hbox);

  refresh();
}

StatusBox::~StatusBox()
{
  delete firmware_label;
  delete firmware_text;

  delete hbox;
}

void StatusBox::refresh(void)
{
  refresh_in_progress = true;
  firmware_text->setText(QString::fromStdString(radio_interface->send_command("*W")));
  refresh_in_progress = false;
}
