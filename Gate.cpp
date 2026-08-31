#include "Gate.h"
#include <iostream>

Gate::Gate(const std::string &name, int capacity) : EventUnit(name, capacity), admitting(false), exitOnly(false), currentCapacity(0)
{
}

void Gate::startAdmitting()
{
  if (isOpen && !exitOnly)
  {
    admitting = true;
    std::cout << "Gate " << getName() << " is now admitting." << std::endl;
  }
  else
  {
    std::cerr << "Error: Cannot start admitting. The gate is either closed or set to exit-only mode." << std::endl;
  }
}

void Gate::stopAdmitting()
{
  admitting = false;
  std::cout << "Gate " << getName() << " has stopped admitting." << std::endl;
}

void Gate::setExitOnly(bool exitOnly)
{
  this->exitOnly = exitOnly;
  if (exitOnly)
  {
    admitting = false;
  }
}

void Gate::setCurrentCapacity(int currentCapacity)
{
  if (currentCapacity >= 0)
  {
    this->currentCapacity = currentCapacity;
  }
}

void Gate::reportStatus() const
{
  std::cout << "Gate: " << getName() << std::endl;
  std::cout << "Capacity: " << getCapacity() << std::endl;
  std::cout << "Current Capacity: " << currentCapacity << std::endl;
  std::cout << "Status: " << (isOpen ? "Open" : "Closed") << std::endl;
  std::cout << "Admitting: " << (admitting ? "Yes" : "No") << std::endl;
  std::cout << "Exit Only: " << (exitOnly ? "Yes" : "No") << std::endl;
}

void Gate::update(const Notice& notice)
{
  std::cout << "  [Gate] " << getName() << " received notice: " << notice.getMessage() << std::endl;
  switch (notice.getType())
  {
  case OPEN_NOTICE:
    open();
    setExitOnly(false);
    startAdmitting();
    break;
  case CLOSE_NOTICE:
    stopAdmitting();
    close();
    break;
  case CAPACITY_ALERT:
    stopAdmitting();
    std::cout << "    >>> Gate CLOSED to new admissions (capacity)." << std::endl;
    break;
  case EVACUATE:
    setExitOnly(true);
    stopAdmitting();
    std::cout << "    >>> Gate switched to EXIT-ONLY mode." << std::endl;
    break;
  case RESUME:
    open();
    setExitOnly(false);
    startAdmitting();
    break;
  case WEATHER_ALERT:
    std::cout << "    >>> Gate remains operational during weather alert." << std::endl;
    break;
  default:
    break;
  }
}

Gate::~Gate()
{
}