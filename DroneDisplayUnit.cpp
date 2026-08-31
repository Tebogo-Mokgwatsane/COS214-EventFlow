#include "DroneDisplayUnit.h"
#include <iostream>

DroneDisplayUnit::DroneDisplayUnit(const std::string &name, int capacity) : EventUnit(name, capacity), airbone(false), demonstrationActive(false)
{
}

void DroneDisplayUnit::startDemonstration()
{
  if (isOpen)
  {
    airbone = true;
    demonstrationActive = true;
    std::cout << "Drone Display Unit " << getName() << " has started the demonstration." << std::endl;
  }
  else
  {
    std::cerr << "Error: Cannot start demonstration. The drone display unit is closed." << std::endl;
  }
}

void DroneDisplayUnit::landDrones()
{
  airbone = false;
  demonstrationActive = false;
  std::cout << "Drone Display Unit " << getName() << " has landed the drones." << std::endl;
}

void DroneDisplayUnit::reportStatus() const
{
  std::cout << "Drone Display Unit: " << getName() << std::endl;
  std::cout << "Capacity: " << getCapacity() << std::endl;
  std::cout << "Status: " << (isOpen ? "Open" : "Closed") << std::endl;
  std::cout << "Airborne: " << (airbone ? "Yes" : "No") << std::endl;
  std::cout << "Demonstration Active: " << (demonstrationActive ? "Yes" : "No") << std::endl;
}
void DroneDisplayUnit::update(const Notice& notice)
{
  
}
DroneDisplayUnit::~DroneDisplayUnit()
{
}