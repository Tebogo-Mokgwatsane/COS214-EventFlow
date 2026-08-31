#include "EventControl.h"
#include <iostream>

EventControl::EventControl(const string &s,const Notice& type)
{
    this->name=s;
    this->currentNotice=type;
}
const Notice& EventControl::getCurrentNotice()const
{
    return currentNotice;
}
void EventControl::issueNotice(const Notice& notice)
{
    this->currentNotice=notice;
    cout<< "\n[" << name << "] "<< notice.getMessage()<< std::endl;
    notify(notice);
}
