#include "EventControl.h"
#include <iostream>

EventControl::EventControl() : name("Control"), currentNotice()
{
}

EventControl::EventControl(const std::string &s) : name(s), currentNotice()
{
}

EventControl::EventControl(const std::string &s, const Notice &type)
    : name(s), currentNotice(type)
{
}

const Notice &EventControl::getCurrentNotice() const
{
  return currentNotice;
}

void EventControl::issueNotice(const Notice &notice)
{
  currentNotice = notice;
  std::cout << "\n=== [" << name << "] ISSUES: " << notice.getMessage() << " (severity " << notice.getSeverity() << ") ===" << std::endl;
  notify(notice);
}
