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

#ifndef VFO_OSC_CTL_H
#define VFO_OSC_CTL_H

#include "oscctl.h"

class VFOOscCtl: public OscCtl
{
    Q_OBJECT

public:
    VFOOscCtl(RadioInterface *radio_interface);
    ~VFOOscCtl();
};

#endif // VFO_OSC_CTL_H
