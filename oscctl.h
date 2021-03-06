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

#ifndef OSC_CTL_H
#define OSC_CTL_H

#include <cstdint>

#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLabel>

#include "freqctrl.h"

#include "radiointerface.h"

class OscCtl: public QGroupBox
{
    Q_OBJECT

public:
    OscCtl(std::string name,
	   char cmd_id,
	   RadioInterface *radio_interface,
	   uint32_t min_freq = 1024000,
	   uint32_t max_freq = 112500000);
    ~OscCtl();

    void refresh();
    void refresh_frequency();

    uint32_t get_frequency();
    void set_frequency(uint32_t frequency);

protected:
    char cmd_id;
    RadioInterface *radio_interface;
    uint32_t min_freq;
    uint32_t max_freq;

    uint32_t freq;

    QVBoxLayout *vbox;

private:
    bool refresh_in_progress;

    QCheckBox *osc_enable;

    CFreqCtrl *fc;

private slots:
    void on_enable_stateChanged(int state);
    void on_newFrequency(qint64 freq);
};

#endif // OSC_CTL_H
