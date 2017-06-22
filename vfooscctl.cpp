#include "vfooscctl.h"

VFOOscCtl::VFOOscCtl(RadioInterface *radio_interface) :
  OscCtl(std::string("VFO"), radio_interface)
{
}

VFOOscCtl::~VFOOscCtl()
{
}
