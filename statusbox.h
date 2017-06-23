// Copyright 2017 Eric Smith

#ifndef STATUS_BOX_H
#define STATUS_BOX_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

#include "radiointerface.h"

class StatusBox: public QWidget
{
    Q_OBJECT

public:
    StatusBox(RadioInterface *radio_interface);
    ~StatusBox();

private:
    RadioInterface *radio_interface;

    QHBoxLayout *hbox;

    QLabel *status_label;
    QLineEdit *status_text;
};

#endif // STATUS_BOX_H
