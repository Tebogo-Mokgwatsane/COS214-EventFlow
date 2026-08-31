#include "EventGroup.h"
#include <iostream>
#include <algorithm>

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
  for (size_t i = 0; i < children.size(); ++i)
  {
    if (children[i] == child)
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
    return nullptr;
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
  std::cout << "[EventGroup] " << name << " is now OPEN." << std::endl;
  for (size_t i = 0; i < children.size(); ++i)
    children[i]->open();
}

void EventGroup::close()
{
  isOpen = false;
  std::cout << "[EventGroup] " << name << " is now CLOSED." << std::endl;
  for (size_t i = 0; i < children.size(); ++i)
    children[i]->close();
}

int EventGroup::getCapacity() const
{
  int total = 0;
  for (size_t i = 0; i < children.size(); ++i)
    total += children[i]->getCapacity();
  return total;
}

void EventGroup::reportStatus() const
{
  std::cout << "[EventGroup] " << name << ": " << (isOpen ? "OPEN" : "CLOSED") << " | capacity=" << getCapacity() << " | children=" << children.size() << std::endl;
  for (size_t i = 0; i < children.size(); ++i)
    children[i]->reportStatus();
}

EventComponent *EventGroup::getChild(size_t index) const
{
  if (index < children.size())
    return children[index];
  return nullptr;
}

void EventGroup::printTree(const std::string &indent) const
{
  std::cout << indent << "+-- " << name << " [Group, open=" << (isOpen ? "Y" : "N") << ", cap=" << getCapacity() << "]" << std::endl;
  for (size_t i = 0; i < children.size(); ++i)
  {
    EventGroup *g = dynamic_cast<EventGroup *>(children[i]);
    if (g)
      g->printTree(indent + "    ");
    else
      std::cout << indent << "    |-- " << children[i]->getName() << std::endl;
  }
}

bool EventGroup::transferChild(EventComponent *child, EventGroup *newParent)
{
  if (child == nullptr || newParent == nullptr || newParent == this) return false;
  EventComponent *removed = remove(child);
  if (removed == nullptr) return false;
  // Detach from this subject's observer list if registered
  detach(child);
  newParent->add(child);
  newParent->attach(child);
  std::cout << "[Transfer] " << child->getName() << " moved from " << name << " to " << newParent->getName() << std::endl;
  return true;
}

void EventGroup::update(const Notice &notice)
{
  std::cout << "[EventGroup::update] " << name << " received: " << notice.getMessage() << std::endl;

  switch (notice.getType())
  {
  case OPEN_NOTICE:
    open();
    break;
  case CLOSE_NOTICE:
    close();
    break;
  case EVACUATE:
    close();
    std::cout << "    >>> " << name << " EVACUATING area!" << std::endl;
    break;
  case RESUME:
    open();
    std::cout << "    >>> " << name << " resuming operations." << std::endl;
    break;
  case WEATHER_ALERT:
    std::cout << "    >>> " << name << " processing weather alert (severity " << notice.getSeverity() << ")." << std::endl;
    break;
  case CAPACITY_ALERT:
    std::cout << "    >>> " << name << " capacity alert received." << std::endl;
    break;
  default:
    break;
  }
  // Cascade to registered observers
  notify(notice);
}

EventGroup::~EventGroup()
{
  for (size_t i = 0; i < children.size(); ++i)
    delete children[i];
  children.clear();
}