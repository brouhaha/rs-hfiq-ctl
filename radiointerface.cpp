// Control panel application for RS-HFIQ SDR transceiver
// Copyright 2017 Eric Smith <spacewar@gmail.com>

// This program is free software: you can redistribute it and/or modify
// it under the terms of version 3 of the GNU General Public License
// as published by the Free Software Foundation.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <iostream>

#include <unistd.h>

#include "radiointerface.h"

RadioInterface::RadioInterface()
{
  serial = new QSerialPort();
  write_timeout = 10000;
  read_timeout = 10000;
}

RadioInterface::~RadioInterface()
{
  serial->close();
  delete serial;
}

bool RadioInterface::choose(void)
{
  SerialPortChooser serial_port_chooser;
  if (serial_port_chooser.exec() != QDialog::Accepted)
    return false;
  QString serial_port_name = serial_port_chooser.get_selection();

  serial->setPortName(serial_port_name);

  if (! serial->open(QIODevice::ReadWrite))
    return false;
#if 1
  if (! serial->setBaudRate(QSerialPort::Baud57600))
    return false;
  if (! serial->setDataBits(QSerialPort::Data8))
    return false;
  if (! serial->setParity(QSerialPort::NoParity))
    return false;
  if (! serial->setStopBits(QSerialPort::OneStop))
    return false;
  if (! serial->setFlowControl(QSerialPort::NoFlowControl))
    return false;
#endif
  sleep(2);
  std::cout << "Serial port opened and configured.\n";
  return true;
}

void RadioInterface::send_command_no_reply(std::string cmd)
{
  std::cout << "Sending command '" << cmd << "'\n";
  cmd += '\r';
  QByteArray qba = QByteArray(cmd.c_str(), cmd.length());
  std::cout << qba.toHex().toStdString() << "\n";
  serial->write(qba);
  if (! serial->waitForBytesWritten(write_timeout))
    throw CommException();
  std::cout << "Command sent.\n";
}

std::string RadioInterface::send_command(std::string cmd)
{
  send_command_no_reply(cmd);

  std::cout << "Waiting for reply.\n";

#if 0
  // Simpler but doesn't time out
  QByteArray response_data;
  while (response_data.length() == 0)
    {
      response_data += serial->readLine();
    }
  std::cout << response_data.toHex().toStdString() << "\n";
#else
  QByteArray response_data;
  int cr_pos = -1;
  while (cr_pos < 0)
    {
      if (! serial->waitForReadyRead(read_timeout))
	{
	  throw CommException();
	}
      response_data += serial->readAll();
      std::cout << response_data.toHex().toStdString() << "\n";
      cr_pos = response_data.indexOf('\r');
    }
  response_data.resize(cr_pos);  // truncate carriage return
#endif

  return std::string(response_data.constData(), response_data.length());
}
