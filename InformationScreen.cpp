#include "InformationScreen.h"
#include <iostream>

InformationScreen::InformationScreen(const std::string &name) : EventUnit(name, 0), displayedMessage("No Message")
{
}

void InformationScreen::displayMessage(const std::string &message)
{
  displayedMessage = message;
}

void InformationScreen::reportStatus() const
{
  std::cout << "Information Screen: " << getName() << (isOpen ? " - Open" : " - Closed") << " - Displayed Message: " << displayedMessage << std::endl;
}

InformationScreen::~InformationScreen()
{
}