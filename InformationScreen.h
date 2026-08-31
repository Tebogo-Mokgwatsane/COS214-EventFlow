#ifndef INFORMATIONSCREEN_H
#define INFORMATIONSCREEN_H

#include "EventUnit.h"
#include <string>

class InformationScreen : public EventUnit
{
private:
  std::string displayedMessage;

public:
  InformationScreen(const std::string &name);
  void update(const Notice& notice) override;
  void displayMessage(const std::string &message);
  virtual void reportStatus() const override;
  virtual ~InformationScreen();
};

#endif