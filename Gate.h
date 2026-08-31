#ifndef GATE_H
#define GATE_H

#include "EventUnit.h"

class Gate : public EventUnit
{
private:
  bool admitting;
  bool exitOnly;
  int currentCapacity;

public:
  Gate(const std::string &name, int capacity);
  void startAdmitting();
  void stopAdmitting();
  void setExitOnly(bool exitOnly);
  void setCurrentCapacity(int currentCapacity);
  void update(const Notice& notice) override;
  virtual void reportStatus() const override;
  virtual ~Gate();
};

#endif