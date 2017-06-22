// Copyright 2017 Eric Smith

#ifndef OSC_CTL_H
#define OSC_CTL_H

#include <cstdint>

#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLabel>
#include <QSpinBox>

#include "radiointerface.h"

class OscCtl: public QGroupBox
{
    Q_OBJECT

public:
    OscCtl(std::string name,
	   RadioInterface *radio_interface,
	   uint32_t min_freq = 3000000,
	   uint32_t max_freq = 29999999);
    ~OscCtl();

protected:
    RadioInterface *radio_interface;
    uint32_t min_freq;
    uint32_t max_freq;

    QVBoxLayout *vbox;
    QHBoxLayout *hbox1;

    QCheckBox *osc_enable;

    // in hbox
    QLabel *freq_label;
    QSpinBox *freq_spinbox;
};

#endif // OSC_CTL_H
