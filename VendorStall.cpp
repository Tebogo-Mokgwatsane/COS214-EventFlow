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
  //implement here
}
VendorStall::~VendorStall()
{
}