// Copyright 2017 Eric Smith

#ifndef FREQ_OFFSET_CTL_H
#define FREQ_OFFSET_CTL_H

#include <cstdint>

#include <QGroupBox>
#include <QVBoxLayout>
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

    QVBoxLayout *vbox;

    QLabel *freq_offset_label;
    QLineEdit *freq_offset_text;
};

#endif // FREQ_OFFSET_CTL_H
