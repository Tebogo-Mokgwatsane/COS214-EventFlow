#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H

#include <iostream>
#include <string>
#include "Subject.h"
#include "Notice.h"

using namespace std;

class EventControl:public Subject
{
private:
  string name;
  Notice currentNotice;

public:
  EventControl();
  EventControl(const string &name);
  EventControl(const string &name, const Notice &initialNotice);

  const Notice &getCurrentNotice() const;
  void issueNotice(const Notice &notice);
  size_t observerCount() const { return registered.size(); }
};

#endif