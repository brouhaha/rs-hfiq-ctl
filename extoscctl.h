// Copyright 2017 Eric Smith

#ifndef EXT_OSC_CTL_H
#define EXT_OSC_CTL_H

#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>

#include "radiointerface.h"

class ExtOscCtl: public QGroupBox
{
    Q_OBJECT

public:
    ExtOscCtl(RadioInterface *radio_interface);
    ~ExtOscCtl();

private:
    RadioInterface *radio_interface;

    QHBoxLayout *hbox;
    QVBoxLayout *vbox1;

    // in vbox1
    QLabel *ext_freq_label;
    QSpinBox *ext_freq;

    QPushButton *ext_on;
    QPushButton *ext_off;
};

#endif // EXT_OSC_CTL_H
