#ifndef SUBJECT_H
#define SUBJECT_H
#include "Observer.h"
#include <iostream>
#include <vector>
using namespace std;

class Subject
{
    public:
        virtual void attach(Observer* observer);
        virtual void detach(Observer* observer);
        virtual void notify(const Notice& notice);
        virtual ~Subject()=0;
    protected:
        vector<Observer*> registered;
        bool isRegistered(Observer * observer)const;
        void clearObserver();
};
#endif