#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

#include <string>
#include <vector>

class EventComponent
{
protected:
  std::string name;
  bool isOpen;

public:
  EventComponent(const std::string &name);
  virtual void open() = 0;
  virtual void close() = 0;
  virtual int getCapacity() const = 0;
  virtual void reportStatus() const = 0;

  std::string getName() const;

  virtual ~EventComponent();
};

#endif