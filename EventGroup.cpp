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
EventGroup::~EventGroup()
{
  for (std::vector<EventComponent *>::iterator it = children.begin(); it != children.end(); ++it)
  {
    detach(*it);
    delete *it;
  }

  children.clear();
}
void EventGroup::update(const Notice& notice)
{
    notify(notice);
}