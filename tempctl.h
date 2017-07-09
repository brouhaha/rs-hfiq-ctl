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
    TempCtl(RadioInterface *radio_interface, bool has_comp);
    ~TempCtl();

    void refresh();

private:
    RadioInterface *radio_interface;
    bool has_comp;

    bool refresh_in_progress;

    float temp_c;
    int mode;

    QVBoxLayout *vbox;
    QHBoxLayout *hbox1;
    QHBoxLayout *hbox2;

    QLabel *temp_label_1;
    QLineEdit *temp_text_c;
    QLabel *temp_label_2;
    QLineEdit *temp_text_f;
    QLabel *temp_label_3;

    QLabel *tc_label;
    QRadioButton *tc_disabled;
    QRadioButton *tc_enabled;
    QRadioButton *tc_tcxo;

    void refresh_temp();
    void refresh_mode();

private slots:
  void on_tc_toggled(bool checked);
};

#endif // TEMP_CTL_H
