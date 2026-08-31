#ifndef AIRDISPLAYSTAGE_H
#define AIRDISPLAYSTAGE_H

#include "EventUnit.h"
#include <string>

class AirDisplayStage : public EventUnit
{
private:
  std::string currentSlot;
  bool performing;
  bool paused;

public:
  AirDisplayStage(const std::string &name, int capacity, const std::string &currentSlot);
  void startPerformance();
  void pausePerformance();
  void stopPerformance();
  void setCurrentSlot(const std::string &slot);
  void update(const Notice& notice) override;
  virtual void reportStatus() const;
  virtual ~AirDisplayStage();
};

#endif