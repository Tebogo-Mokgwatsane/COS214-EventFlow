#ifndef MEDICALPOST_H
#define MEDICALPOST_H

#include "EventUnit.h"

class MedicalPost : public EventUnit
{
private:
  bool emergencyMode;

public:
  MedicalPost(const std::string &name, int capacity);
  void enterEmergencyMode();
  void exitEmergencyMode();
  virtual void reportStatus() const override;
  virtual ~MedicalPost();
};

#endif