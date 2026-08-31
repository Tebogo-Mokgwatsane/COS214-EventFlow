#include "ShuttleStop.h"
#include <iostream>

ShuttleStop::ShuttleStop(const std::string &name, int capacity, const std::string &normalRoute) : EventUnit(name, capacity), normalRoute(normalRoute), currentRoute(normalRoute), delayed(false)
{
}

void ShuttleStop::setDelayed(bool delayed)
{
  this->delayed = delayed;
}

void ShuttleStop::changeRoute(const std::string &newRoute)
{
  currentRoute = newRoute;
  std::cout << "Shuttle Stop " << getName() << " route changed to: " << currentRoute << std::endl;
}

void ShuttleStop::restoreNormalRoute()
{
  currentRoute = normalRoute;
  delayed = false;
  std::cout << "Shuttle Stop " << getName() << " restored to: " << normalRoute << std::endl;
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
  std::cout << "  [ShuttleStop] " << getName() << " received notice: " << notice.getMessage() << std::endl;
  switch (notice.getType())
  {
  case OPEN_NOTICE:
  case RESUME:
    open();
    restoreNormalRoute();
    break;
  case CLOSE_NOTICE:
    close();
    break;
  case WEATHER_ALERT:
  case EVACUATE:
    changeRoute("Emergency Evacuation Route");
    setDelayed(true);
    break;
  case TRANSPORT_DELAY:
    setDelayed(true);
    std::cout << "    >>> Shuttle delayed: " << notice.getMessage() << std::endl;
    break;
  case SCHEDULE_CHANGE:
    std::cout << "    >>> Shuttle timetable updated." << std::endl;
    break;
  default:
    break;
  }
}

ShuttleStop::~ShuttleStop()
{
}