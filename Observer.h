#ifndef OBSERVER_H
#define OBSERVER_H
#include "Notice.h"
#include <iostream>
using namespace std;

class Observer
{
    public:
        virtual void update(const Notice& notice )=0;
        virtual ~Observer(){};
};
#endif