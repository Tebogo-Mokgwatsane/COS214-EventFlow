#include "MedicalPost.h"
#include <iostream>

MedicalPost::MedicalPost(const std::string &name, int capacity) : EventUnit(name, capacity), emergencyMode(false)
{
}

void MedicalPost::enterEmergencyMode()
{
  emergencyMode = true;
  std::cout << "Medical Post " << getName() << " has entered emergency mode." << std::endl;
}

void MedicalPost::exitEmergencyMode()
{
  emergencyMode = false;
  std::cout << "Medical Post " << getName() << " has exited emergency mode." << std::endl;
}

void MedicalPost::reportStatus() const
{
  std::cout << "Medical Post: " << getName() << std::endl;
  std::cout << "Capacity: " << getCapacity() << std::endl;
  std::cout << "Status: " << (isOpen ? "Open" : "Closed") << std::endl;
  std::cout << "Emergency Mode: " << (emergencyMode ? "Active" : "Inactive") << std::endl;
}

void MedicalPost::update(const Notice& notice)
{
  std::cout << "  [MedicalPost] " << getName() << " received notice: " << notice.getMessage() << std::endl;
  switch (notice.getType())
  {
  case OPEN_NOTICE:
  case RESUME:
    open();
    exitEmergencyMode();
    break;
  case CLOSE_NOTICE:
    // Medical stays open for emergencies
    std::cout << "    >>> Medical post stays open for emergencies." << std::endl;
    break;
  case EVACUATE:
  case WEATHER_ALERT:
  case CAPACITY_ALERT:
    open();
    enterEmergencyMode();
    std::cout << "    >>> Medical post remains ACTIVE." << std::endl;
    break;
  default:
    break;
  }
}

MedicalPost::~MedicalPost()
{
}