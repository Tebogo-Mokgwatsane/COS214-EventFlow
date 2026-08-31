#include "VendorStall.h"
#include <iostream>

VendorStall::VendorStall(const std::string &name, int capacity, bool outdoor) : EventUnit(name, capacity), serving(false), outdoor(outdoor)
{
}

void VendorStall::startServing()
{
  if (isOpen)
  {
    serving = true;
    std::cout << "Vendor Stall " << getName() << " is now serving." << std::endl;
  }
  else
  {
    std::cerr << "Error: Cannot start serving. The vendor stall is closed." << std::endl;
  }
}

void VendorStall::stopServing()
{
  serving = false;
  std::cout << "Vendor Stall " << getName() << " has stopped serving." << std::endl;
}

bool VendorStall::isOutdoor() const
{
  return outdoor;
}

void VendorStall::reportStatus() const
{
  std::cout << "Vendor Stall: " << getName() << std::endl;
  std::cout << "Capacity: " << getCapacity() << std::endl;
  std::cout << "Status: " << (isOpen ? "Open" : "Closed") << std::endl;
  std::cout << "Serving: " << (serving ? "Yes" : "No") << std::endl;
  std::cout << "Outdoor: " << (outdoor ? "Yes" : "No") << std::endl;
}

void VendorStall::update(const Notice& notice)
{
  std::cout << "  [VendorStall] " << getName() << " received notice: " << notice.getMessage() << std::endl;
  switch (notice.getType())
  {
  case OPEN_NOTICE:
  case RESUME:
    open();
    startServing();
    break;
  case CLOSE_NOTICE:
    stopServing();
    close();
    break;
  case WEATHER_ALERT:
    if (outdoor && notice.getSeverity() >= 4)
    {
      stopServing();
      std::cout << "    >>> Outdoor serving suspended (severe weather)." << std::endl;
    }
    else
    {
      std::cout << "    >>> Stall continues (indoor or mild weather)." << std::endl;
    }
    break;
  case EVACUATE:
    stopServing();
    close();
    std::cout << "    >>> Stall closed – evacuate." << std::endl;
    break;
  default:
    break;
  }
}

VendorStall::~VendorStall()
{
}