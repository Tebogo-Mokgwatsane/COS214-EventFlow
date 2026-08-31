#include "EventGroup.h"
#include <iostream>

EventGroup::EventGroup(const std::string &name) : EventComponent(name)
{
}

void EventGroup::add(EventComponent *child)
{

  if (child == nullptr)
  {
    std::cerr << "Error: Cannot add a null child to the EventGroup." << std::endl;
    return;
  }

  for (std::vector<EventComponent *>::iterator it = children.begin(); it != children.end(); ++it)
  {
    if (*it == child)
    {
      std::cerr << "Error: Child already exists in the EventGroup." << std::endl;
      return;
    }
  }
  children.push_back(child);
}

EventComponent *EventGroup::remove(EventComponent *child)
{

  if (child == nullptr)
  {
    std::cerr << "Error: Cannot add a null child to the EventGroup." << std::endl;
    return nullptr;
  }

  for (std::vector<EventComponent *>::iterator it = children.begin(); it != children.end(); ++it)
  {
    if (*it == child)
    {
      EventComponent *removedChild = *it;
      children.erase(it);
      return removedChild;
    }
  }
  return nullptr;
}

void EventGroup::open()
{
  isOpen = true;
  std::vector<EventComponent *>::iterator it;

  for (it = children.begin(); it != children.end(); ++it)
  {
    (*it)->open();
  }
}
void EventGroup::close()
{
  isOpen = false;

  for (std::vector<EventComponent *>::iterator it = children.begin(); it != children.end(); ++it)
  {
    (*it)->close();
  }
}
int EventGroup::getCapacity() const
{
  int total = 0;

  for (std::vector<EventComponent *>::const_iterator it = children.begin(); it != children.end(); ++it)
  {
    total += (*it)->getCapacity();
  }

  return total;
}
void EventGroup::reportStatus() const
{
  std::cout << name << ": " << (isOpen ? "OPEN" : "CLOSED") << std::endl;
}
EventGroup::~EventGroup()
{
  for (std::vector<EventComponent *>::iterator it = children.begin(); it != children.end(); ++it)
  {
    delete *it;
  }

  children.clear();
}
void EventGroup::update(const Notice& notice)
{
    notify(notice);
}