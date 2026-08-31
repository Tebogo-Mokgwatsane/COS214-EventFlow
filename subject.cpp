#include "subject.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool Subject:: isRegistered(Observer* observer)const
{
    for(size_t i=0;i<registered.size();i++)
    {
        if(registered[i]==observer)
        {
            return true;
        }
    }
    return false;
}
void Subject::attach(Observer* ob)
{
    if(ob==NULL)
    {
        return;
    }
    if(isRegistered(ob)==true)
    {
        return;
    }
    registered.push_back(ob);
}
void Subject:: detach(Observer * ob)
{
    if(ob==NULL)
    {
        return;
    }
    if(isRegistered(ob)==false)
    {
        return;
    }
    vector<Observer*>::iterator it=find(registered.begin(),registered.end(),ob);
    if(it !=registered.end())
    {
        registered.erase(it);
    }
}
void Subject::notify(const Notice& type)
{
    vector<Observer*> snap=registered;
    for(Observer * observe:snap)
    {
        if(observe!= NULL && isRegistered(observe))
        {
            observe->update(type);
        }
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