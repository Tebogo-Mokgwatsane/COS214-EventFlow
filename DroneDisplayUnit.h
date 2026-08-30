#ifndef DRONEDISPLAYUNIT_H
#define DRONEDISPLAYUNIT_H

#include "EventUnit.h"

class DroneDisplayUnit : public EventUnit
{
private:
  bool airbone;
  bool demonstrationActive;

public:
  DroneDisplayUnit(const std::string &name, int capacity);
  void startDemonstration();
  void landDrones();
  virtual void reportStatus() const override;
  virtual ~DroneDisplayUnit();
};

#endif