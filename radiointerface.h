// Copyright 2017 Eric Smith

#ifndef RADIOINTERFACE_H
#define RADIOINTERFACE_H

#include "serialportchooser.h"

class RadioInterface
{
public:
  RadioInterface();
  ~RadioInterface();

private:
  SerialPortChooser *serial_port_chooser;
};

#endif // RADIOINTERFACE_H
