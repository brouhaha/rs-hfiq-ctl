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

#ifndef BIT_OSC_CTL_H
#define BIT_OSC_CTL_H

#include <QPushButton>

#include "oscctl.h"

class BitOscCtl: public OscCtl
{
    Q_OBJECT

public:
    BitOscCtl(RadioInterface *radio_interface);
    ~BitOscCtl();

private:
    QLabel *set_label;
    QHBoxLayout *hbox2;

    QPushButton *set_lo_plus_1khz;
    QPushButton *set_lo;
    QPushButton *set_lo_minus_1khz;
};

#endif // BIT_OSC_CTL_H
