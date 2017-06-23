#include "vfooscctl.h"

VFOOscCtl::VFOOscCtl(RadioInterface *radio_interface) :
  OscCtl(std::string("VFO"), 'F', radio_interface,
	 3000000, 29999999)
{
}

VFOOscCtl::~VFOOscCtl()
{
}
