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
	   char cmd_id,
	   RadioInterface *radio_interface,
	   uint32_t freq_mult = 1,
	   uint32_t min_freq = 1024000,
	   uint32_t max_freq = 112500000);
    ~OscCtl();

    uint32_t get_freq(void);

protected:
    char cmd_id;
    RadioInterface *radio_interface;
    uint32_t min_freq;
    uint32_t max_freq;
    uint32_t freq_mult;

    uint32_t freq;

    QVBoxLayout *vbox;
    QHBoxLayout *hbox1;

    QCheckBox *osc_enable;

    // in hbox
    QLabel *freq_label;
    QSpinBox *freq_spinbox;
};

#endif // OSC_CTL_H
