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

#ifndef TEMP_CTL_H
#define TEMP_CTL_H

#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>

#include "radiointerface.h"

class TempCtl: public QGroupBox
{
    Q_OBJECT

public:
    TempCtl(RadioInterface *radio_interface);
    ~TempCtl();

protected:
    RadioInterface *radio_interface;

    QVBoxLayout *vbox;
    QHBoxLayout *hbox1;
    QHBoxLayout *hbox2;

    QLabel *temp_label;
    QLineEdit *temp_text;

    QLabel *tc_label;
    QRadioButton *tc_disabled;
    QRadioButton *tc_enabled;
    QRadioButton *tc_tcxo;
};

#endif // TEMP_CTL_H
