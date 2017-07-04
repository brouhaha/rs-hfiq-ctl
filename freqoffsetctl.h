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

#ifndef FREQ_OFFSET_CTL_H
#define FREQ_OFFSET_CTL_H

#include <cstdint>

#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

#include "radiointerface.h"

class FreqOffsetCtl: public QGroupBox
{
    Q_OBJECT

public:
    FreqOffsetCtl(RadioInterface *radio_interface);
    ~FreqOffsetCtl();
    
    void refresh(void);

 private:
    RadioInterface *radio_interface;

    bool refresh_in_progress;

    uint32_t freq_offset;

    QHBoxLayout *hbox;

    QLabel *freq_offset_label;
    QLineEdit *freq_offset_text;
};

#endif // FREQ_OFFSET_CTL_H
