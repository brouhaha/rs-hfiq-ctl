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

#ifndef SERIALPORTCHOOSER_H
#define SERIALPORTCHOOSER_H

#include <QObject>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QDialogButtonBox>

class SerialPortChooser: public QDialog
{
  Q_OBJECT

public:
  SerialPortChooser(QWidget *parent = 0, Qt::WindowFlags f = 0);

  QString get_selection();

private:
  QVBoxLayout *layout;
  QLabel *label;
  QListWidget *list;
  QDialogButtonBox *buttonBox;
  QString selection;

private slots:
  void selectionChanged();
};

#endif // SERIALPORTCHOOSER_H
