#ifndef FIRERESPONSETEAM_H
#define FIRERESPONSETEAM_H

#include "EventUnit.h"

class FireResponseTeam : public EventUnit
{
private:
  bool highReadiness;
  bool deployed;

public:
  FireResponseTeam(const std::string &name, int capacity);
  void increaseReadiness();
  void normalReadiness();
  void deploy();
  void standDown();
  virtual void reportStatus() const override;
  virtual ~FireResponseTeam();
};

#endif