#include "freqoffsetctl.h"

FreqOffsetCtl::FreqOffsetCtl(RadioInterface *radio_interface) :
  QGroupBox(tr("Frequency Offset"))
{
  this->radio_interface = radio_interface;

  refresh_in_progress = false;
  
  vbox = new QVBoxLayout;
  freq_offset_label = new QLabel(tr("Offset"));
  vbox->addWidget(freq_offset_label);
  freq_offset_text = new QLineEdit();
  freq_offset_text->setPlaceholderText("0");
  freq_offset_text->setReadOnly(true);
  vbox->addWidget(freq_offset_text);

  setLayout(vbox);

  refresh();
}

FreqOffsetCtl::~FreqOffsetCtl()
{
  delete freq_offset_label;
  delete freq_offset_text;

  delete vbox;
}

void FreqOffsetCtl::refresh()
{
  refresh_in_progress = true;
  this->freq_offset = std::stoi(radio_interface->send_command("*D?"));
  freq_offset_text->setText(QString::fromStdString(std::to_string(this->freq_offset)));
  refresh_in_progress = false;
}
