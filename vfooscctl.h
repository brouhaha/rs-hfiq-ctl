// Copyright 2017 Eric Smith

#ifndef VFO_OSC_CTL_H
#define VFO_OSC_CTL_H

#include "oscctl.h"

class VFOOscCtl: public OscCtl
{
    Q_OBJECT

public:
    VFOOscCtl(RadioInterface *radio_interface);
    ~VFOOscCtl();
};

#endif // VFO_OSC_CTL_H
