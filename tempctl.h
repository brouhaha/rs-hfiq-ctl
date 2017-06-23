// Copyright 2017 Eric Smith

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
    TempCtl(RadioInterface *radio_interface);
    ~TempCtl();

protected:
    RadioInterface *radio_interface;

    QVBoxLayout *vbox;
    QHBoxLayout *hbox1;
    QHBoxLayout *hbox2;

    QLabel *temp_label;
    QLineEdit *temp_text;

    QLabel *tc_label;
    QRadioButton *tc_disabled;
    QRadioButton *tc_enabled;
    QRadioButton *tc_tcxo;
};

#endif // TEMP_CTL_H
