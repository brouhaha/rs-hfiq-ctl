// Copyright 2017 Eric Smith

#ifndef EXT_OSC_CTL_H
#define EXT_OSC_CTL_H

#include "oscctl.h"

class ExtOscCtl: public OscCtl
{
    Q_OBJECT

public:
    ExtOscCtl(RadioInterface *radio_interface);
    ~ExtOscCtl();
};

#endif // EXT_OSC_CTL_H
