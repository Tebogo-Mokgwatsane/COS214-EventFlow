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

void InformationScreen::update(const Notice& notice)
{
  std::cout << "  [InformationScreen] " << getName() << " received notice: " << notice.getMessage() << std::endl;
  displayMessage(notice.getMessage());
  std::cout << "    >>> Display updated: \"" << displayedMessage << "\"" << std::endl;
  switch (notice.getType())
  {
  case OPEN_NOTICE:
    open();
    break;
  case CLOSE_NOTICE:
    close();
    break;
  default:
    break;
  }
}

InformationScreen::~InformationScreen()
{
}