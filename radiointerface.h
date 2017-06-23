// Copyright 2017 Eric Smith

#ifndef RADIOINTERFACE_H
#define RADIOINTERFACE_H

#include "serialportchooser.h"

class RadioInterface
{
public:
  RadioInterface();
  ~RadioInterface();

  bool choose(void);

  void send_command_no_reply(std::string cmd);
  std::string send_command(std::string cmd);

private:
  QString serial_port_name;
};

#endif // RADIOINTERFACE_H
