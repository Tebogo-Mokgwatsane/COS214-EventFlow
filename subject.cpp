#include "Subject.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool Subject::isRegistered(Observer *observer) const
{
  for (size_t i = 0; i < registered.size(); i++)
  {
    if (registered[i] == observer)
      return true;
  }
  return false;
}

void Subject::attach(Observer *ob)
{
  if (ob == NULL)
    return;
  if (isRegistered(ob))
    return; // ignore duplicates
  registered.push_back(ob);
}

void Subject::detach(Observer *ob)
{
  if (ob == NULL)
    return;
  vector<Observer *>::iterator it = find(registered.begin(), registered.end(), ob);
  if (it != registered.end())
    registered.erase(it);
  // no-op if not found
}

void Subject::notify(const Notice &notice)
{
  // snapshot so detach during notify is safe
  vector<Observer *> snap = registered;
  for (size_t i = 0; i < snap.size(); ++i)
  {
    if (snap[i] != NULL)
      snap[i]->update(notice);
  }
}

void Subject::clearObserver()
{
  registered.clear();
}

Subject::~Subject()
{
  clearObserver();
}