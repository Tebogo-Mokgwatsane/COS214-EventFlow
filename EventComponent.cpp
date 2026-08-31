#include "EventComponent.h"

EventComponent::EventComponent(const std::string &name) : name(name), isOpen(false)
{
}

std::string EventComponent::getName() const
{
  return name;
}

EventComponent::~EventComponent()
{
}