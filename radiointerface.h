// Copyright 2017 Eric Smith

#ifndef RADIOINTERFACE_H
#define RADIOINTERFACE_H

#include <exception>

#include <QtSerialPort/QSerialPort>

#include "serialportchooser.h"

struct CommException: public std::exception {};

class RadioInterface
{
public:
  RadioInterface();
  ~RadioInterface();

  bool choose(void);

  void send_command_no_reply(std::string cmd);
  std::string send_command(std::string cmd);

private:
  int write_timeout;
  int read_timeout;
  QSerialPort *serial;
};

#endif // RADIOINTERFACE_H
