#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include "EventComponent.h"
// #include "Subject.h"
#include <vector>

class EventGroup : public EventComponent
//  public Subject

{
private:
  std::vector<EventComponent *> children;

public:
  EventGroup(const std::string &name);
  void add(EventComponent *child);
  EventComponent *remove(EventComponent *child);
  virtual void open();
  virtual void close();
  virtual int getCapacity() const;
  void reportStatus() const;
  virtual ~EventGroup();
};

#endif