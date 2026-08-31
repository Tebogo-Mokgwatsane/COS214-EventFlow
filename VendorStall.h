#ifndef VENDORSTALL_H
#define VENDORSTALL_H

#include "EventUnit.h"

class VendorStall : public EventUnit
{
private:
  bool serving;
  bool outdoor;

public:
  VendorStall(const std::string &name, int capacity, bool outdoor);
  void startServing();
  void stopServing();
  bool isOutdoor() const;
  void update(const Notice& notice) override;
  virtual void reportStatus() const override;
  virtual ~VendorStall();
};

#endif