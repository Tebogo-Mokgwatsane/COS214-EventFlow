#include "FireResponseTeam.h"
#include <iostream>

FireResponseTeam::FireResponseTeam(const std::string &name, int capacity) : EventUnit(name, capacity), highReadiness(false), deployed(false)
{
}

void FireResponseTeam::increaseReadiness()
{
  highReadiness = true;
}

void FireResponseTeam::normalReadiness()
{
  highReadiness = false;
}

void FireResponseTeam::deploy()
{
  highReadiness = true;
  deployed = true;
  std::cout << "Fire Response Team " << getName() << " has been deployed." << std::endl;
}

void FireResponseTeam::standDown()
{
  deployed = false;
  highReadiness = false;
  std::cout << "Fire Response Team " << getName() << " has stood down." << std::endl;
}

void FireResponseTeam::reportStatus() const
{
  std::cout << "Fire Response Team: " << getName() << std::endl;
  std::cout << "Capacity: " << getCapacity() << std::endl;
  std::cout << "Status: " << (isOpen ? "Open" : "Closed") << std::endl;
  std::cout << "High Readiness: " << (highReadiness ? "Yes" : "No") << std::endl;
  std::cout << "Deployed: " << (deployed ? "Yes" : "No") << std::endl;
}

void FireResponseTeam::update(const Notice& notice)
{
  std::cout << "  [FireResponseTeam] " << getName() << " received notice: " << notice.getMessage() << std::endl;
  switch (notice.getType())
  {
  case OPEN_NOTICE:
    open();
    normalReadiness();
    break;
  case CLOSE_NOTICE:
    // Stay ready even if area closes
    std::cout << "    >>> Team stays ready despite area close." << std::endl;
    break;
  case WEATHER_ALERT:
  case EVACUATE:
  case CAPACITY_ALERT:
    increaseReadiness();
    std::cout << "    >>> Team remains OPERATIONAL and on high readiness." << std::endl;
    break;
  case RESUME:
    standDown();
    open();
    break;
  default:
    break;
  }
}

FireResponseTeam::~FireResponseTeam()
{
}