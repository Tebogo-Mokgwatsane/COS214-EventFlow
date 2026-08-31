#include "ShuttleStop.h"
#include <iostream>

ShuttleStop::ShuttleStop(const std::string &name, int capacity, const std::string &normalRoute)
    : EventUnit(name, capacity), normalRoute(normalRoute), currentRoute(normalRoute), delayed(false)
{
}

void ShuttleStop::setDelayed(bool delayed)
{
  this->delayed = delayed;
}

void ShuttleStop::changeRoute(const std::string &newRoute)
{
  currentRoute = newRoute;
}

void ShuttleStop::restoreNormalRoute()
{
  currentRoute = normalRoute;
  delayed = false;
}

void ShuttleStop::reportStatus() const
{
  std::cout << "Shuttle Stop: " << getName() << std::endl;
  std::cout << "Capacity: " << getCapacity() << std::endl;
  std::cout << "Status: " << (isOpen ? "Open" : "Closed") << std::endl;
  std::cout << "Current Route: " << currentRoute << std::endl;
  std::cout << "Delayed: " << (delayed ? "Yes" : "No") << std::endl;
}
void ShuttleStop::update(const Notice& notice)
{
  //implement here
}
ShuttleStop::~ShuttleStop()
{
}