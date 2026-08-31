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
  std::cout << "  [AirDisplayStage] " << getName() << " received notice: " << notice.getMessage() << std::endl;
  switch (notice.getType())
  {
  case OPEN_NOTICE:
    open();
    startPerformance();
    break;
  case CLOSE_NOTICE:
    stopPerformance();
    close();
    break;
  case WEATHER_ALERT:
    if (notice.getSeverity() >= 3)
    {
      if (performing) pausePerformance();
      std::cout << "    >>> PAUSING air display due to weather (severity " << notice.getSeverity() << ")!" << std::endl;
    }
    break;
  case EVACUATE:
    if (performing) stopPerformance();
    close();
    std::cout << "    >>> Air display ABORTED – evacuate!" << std::endl;
    break;
  case RESUME:
    open();
    startPerformance();
    std::cout << "    >>> Performance resumed." << std::endl;
    break;
  case SCHEDULE_CHANGE:
    setCurrentSlot(notice.getMessage());
    std::cout << "    >>> Schedule updated to: " << currentSlot << std::endl;
    break;
  case RUNWAY_ACTIVE:
    std::cout << "    >>> Runway active – display continues if safe." << std::endl;
    break;
  default:
    break;
  }
}

AirDisplayStage::~AirDisplayStage()
{
}