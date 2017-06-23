// Copyright 2017 Eric Smith

#include <iostream>

#include "radiointerface.h"

RadioInterface::RadioInterface()
{
}

RadioInterface::~RadioInterface()
{
}

bool RadioInterface::choose(void)
{
  SerialPortChooser serial_port_chooser;
  if (serial_port_chooser.exec() != QDialog::Accepted)
    return false;
  serial_port_name = serial_port_chooser.get_selection();
  return true;
}

void RadioInterface::send_command_no_reply(std::string cmd)
{
  std::cout << "Sending command '" << cmd << "'\n";
}

std::string RadioInterface::send_command(std::string cmd)
{
  std::string response = "3579545";
  std::cout << "Sending command '" << cmd << "'\n";
  std::cout << "Returning fake response'" << response << "'\n";
  return response;
}
