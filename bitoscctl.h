// Copyright 2017 Eric Smith

#ifndef BIT_OSC_CTL_H
#define BIT_OSC_CTL_H

#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>

class BitOscCtl: public QGroupBox
{
    Q_OBJECT

public:
    BitOscCtl();
    ~BitOscCtl();

private:
    QHBoxLayout *hbox;
    QVBoxLayout *vbox1;
    QVBoxLayout *vbox2;
    QVBoxLayout *vbox3;

    // in vbox1
    QPushButton *set_lo_plus_1khz;
    QPushButton *set_lo;
    QPushButton *set_lo_minus_1khz;

    // in vbox2
    QLabel *bit_freq_label;
    QSpinBox *bit_freq;

    // in vbox3
    QPushButton *bit_on;
    QPushButton *bit_off;
};

#endif // BIT_OSC_CTL_H
