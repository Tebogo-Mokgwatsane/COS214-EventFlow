#include "EventUnit.h"
#include <iostream>

EventUnit::EventUnit(const std::string &name, int capacity) : EventComponent(name), capacity(capacity)
{
}

void EventUnit::open()
{
  isOpen = true;
}

void EventUnit::close()
{
  isOpen = false;
}

int EventUnit::getCapacity() const
{
  std::cout << "Capacity: " << capacity << std::endl;
  return capacity;
}

void EventUnit::reportStatus() const
{
  std::cout << "Status: " << (isOpen ? "Open" : "Closed") << std::endl;
}

EventUnit::~EventUnit() {}