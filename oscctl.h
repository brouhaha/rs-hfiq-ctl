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
	   uint32_t min_freq = 1024000,
	   uint32_t max_freq = 112500000);
    ~OscCtl();

    void refresh(void);
    void refresh_frequency(void);

    uint32_t get_frequency(void);

protected:
    char cmd_id;
    RadioInterface *radio_interface;
    uint32_t min_freq;
    uint32_t max_freq;

    uint32_t freq;

    QVBoxLayout *vbox;
    QHBoxLayout *hbox1;

private:
    bool refresh_in_progress;

    QCheckBox *osc_enable;

    // in hbox
    QLabel *freq_label;
    QSpinBox *freq_spinbox;

private slots:
    void enable_state_changed(int state);
    void frequency_value_changed(int value);
};

#endif // OSC_CTL_H
