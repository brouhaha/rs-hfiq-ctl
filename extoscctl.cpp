#include "extoscctl.h"

ExtOscCtl::ExtOscCtl(RadioInterface *radio_interface) :
  OscCtl(std::string("Ext"), radio_interface)
{
}

ExtOscCtl::~ExtOscCtl()
{
}
