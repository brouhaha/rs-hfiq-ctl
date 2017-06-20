// Copyright 2017 Eric Smith

#ifndef BIT_OSC_CTL_H
#define BIT_OSC_CTL_H

#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>

#include "radiointerface.h"

class BitOscCtl: public QGroupBox
{
    Q_OBJECT

public:
    BitOscCtl(RadioInterface *radio_interface);
    ~BitOscCtl();

private:
    RadioInterface *radio_interface;

    QHBoxLayout *hbox;
    QVBoxLayout *vbox1;
    QVBoxLayout *vbox2;

    // in vbox1
    QPushButton *set_lo_plus_1khz;
    QPushButton *set_lo;
    QPushButton *set_lo_minus_1khz;

    // in vbox2
    QLabel *bit_freq_label;
    QSpinBox *bit_freq;

    QCheckBox *bit_enable;
};

#endif // BIT_OSC_CTL_H
