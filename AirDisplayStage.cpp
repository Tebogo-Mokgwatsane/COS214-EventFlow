#include "AirDisplayStage.h"
#include <iostream>

AirDisplayStage::AirDisplayStage(const std::string &name, int capacity, const std::string &currentSlot)
    : EventUnit(name, capacity), currentSlot(currentSlot), performing(false), paused(false)
{
}

void AirDisplayStage::startPerformance()
{
  if (!isOpen)
  {
    std::cerr << "Error: Cannot start performance. The stage is closed." << std::endl;
    return;
  }
  performing = true;
  paused = false;
  std::cout << "Performance started on slot: " << currentSlot << std::endl;
}

void AirDisplayStage::pausePerformance()
{
  if (!performing)
  {
    std::cerr << "Error: Cannot pause performance. No performance is currently running." << std::endl;
    return;
  }
  paused = true;
  std::cout << "Performance paused on slot: " << currentSlot << std::endl;
}

void AirDisplayStage::stopPerformance()
{
  if (!performing)
  {
    std::cerr << "Error: Cannot stop performance. No performance is currently running." << std::endl;
    return;
  }
  performing = false;
  paused = false;
  std::cout << "Performance stopped on slot: " << currentSlot << std::endl;
}

void AirDisplayStage::setCurrentSlot(const std::string &slot)
{
  currentSlot = slot;
}

void AirDisplayStage::reportStatus() const
{
  std::cout << "AirDisplayStage: " << getName() << std::endl;
  std::cout << "Current Slot: " << currentSlot << std::endl;
  std::cout << "Capacity: " << getCapacity() << std::endl;
  std::cout << "Status: " << (isOpen ? "Open" : "Closed") << std::endl;
  std::cout << "Performing: " << (performing ? (paused ? "Paused" : "Yes") : "No") << std::endl;
}
void AirDisplayStage::update(const Notice& notice)
{
  //implement here
}
AirDisplayStage::~AirDisplayStage()
{
}