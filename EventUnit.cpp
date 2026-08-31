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
  return capacity;
}

void EventUnit::reportStatus() const
{
  std::cout << "Status: " << (isOpen ? "Open" : "Closed") << " | Capacity: " << capacity << std::endl;
}

EventUnit::~EventUnit() {}