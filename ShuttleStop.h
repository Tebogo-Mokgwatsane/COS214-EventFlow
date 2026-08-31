#ifndef SUTTLESTOP_H
#define SUTTLESTOP_H

#include "EventUnit.h"
#include <string>

class ShuttleStop : public EventUnit
{
private:
  std::string normalRoute;
  std::string currentRoute;
  bool delayed;

public:
  ShuttleStop(const std::string &name, int capacity, const std::string &normalRoute);
  void setDelayed(bool delayed);
  void changeRoute(const std::string &newRoute);
  void restoreNormalRoute();
  void update(const Notice& notice) override;
  virtual void reportStatus() const override;
  virtual ~ShuttleStop();
};

#endif