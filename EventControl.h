#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H
#include<iostream>
#include "subject.h"
#include "Notice.h"
using namespace std;

class EventControl:public Subject
{
    private:
        string name;
        Notice currentNotice;
    public:
        EventControl(){};
        EventControl(const string &name,const Notice &intialNotice);
        const Notice & getCurrentNotice()const;
        void issueNotice(const Notice& notice);

};
#endif