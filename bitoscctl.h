// Copyright 2017 Eric Smith

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
