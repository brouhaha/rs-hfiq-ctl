// Copyright 2017 Eric Smith

#include <QPushButton>
#include <QSerialPortInfo>

#include "serialportchooser.h"

SerialPortChooser::SerialPortChooser(QWidget *parent, Qt::WindowFlags f):
  QDialog(parent, f)
{
  selection = "";

  layout = new QVBoxLayout(this);

  buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
  buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

  connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
  connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

  QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
  QSerialPortInfo port;

  if (ports.empty())
    {
      label = new QLabel("No serial ports found");
      layout->addWidget(label);
    }
  else
    {
      label = new QLabel("Select serial port");
      layout->addWidget(label);

      list = new QListWidget(this);

      foreach (port, ports)
	list->addItem(port.portName());

      connect(list, SIGNAL(itemSelectionChanged()), this, SLOT(selectionChanged()));

      layout->addWidget(list);
    }

  layout->addWidget(buttonBox);

  setLayout(layout);
}

QString SerialPortChooser::get_selection()
{
  return selection;
}

void SerialPortChooser::selectionChanged()
{
  QList<QListWidgetItem *> items = list->selectedItems();
  bool empty = items.empty();

  buttonBox->button(QDialogButtonBox::Ok)->setEnabled(! empty);
  if (empty)
    selection = "";
  else
    selection = items[0]->text();
}
