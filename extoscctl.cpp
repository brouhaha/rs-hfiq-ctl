#include "extoscctl.h"

ExtOscCtl::ExtOscCtl(RadioInterface *radio_interface) :
  OscCtl(std::string("Ext"), 'E', radio_interface)
{
}

ExtOscCtl::~ExtOscCtl()
{
}
