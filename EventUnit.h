#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"

class EventUnit : public EventComponent
{
private:
  int capacity;

public:
  EventUnit(const std::string &name, int capacity);
  virtual void open();
  virtual void close();
  virtual int getCapacity() const override;
  virtual void reportStatus() const override;

  virtual ~EventUnit();
};

#endif