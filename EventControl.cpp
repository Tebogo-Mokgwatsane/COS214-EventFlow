#include "EventControl.h"
#include <iostream>

EventController::EventController(const string &s,const Notice& type)
{
    this->name=s;
    this->currentNotice=type;
}
const Notice& EventController::getCurrentNotice()const
{
    return currentNotice;
}
void EventController::issueNotice(const Notice& notice)
{
    this->currentNotice=notice;
    cout<< "\n[" << name << "] "<< notice.getMessage()<< std::endl;
    notify(notice);
}
