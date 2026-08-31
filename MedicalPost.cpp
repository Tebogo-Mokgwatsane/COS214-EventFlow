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

MedicalPost::~MedicalPost()
{
}