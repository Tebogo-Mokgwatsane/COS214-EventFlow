#ifndef OBSERVER_H
#define OBSERVER_H

#include "Notice.h"

/**
 * @class Observer
 * @brief Defines the interface for objects that receive event notifications.
 *
 * Observer is the Observer participant in the Observer design pattern.
 * EventFlow uses the Push model, so the complete Notice object is passed
 * directly to update().
 */
class Observer
{
public:

    /**
     * @brief Receives an event notification from a Subject.
     *
     * @param notice Notice pushed to this Observer.
     */
    virtual void update(const Notice &notice) = 0;

    /**
     * @brief Virtual destructor for safe polymorphic destruction.
     */
    virtual ~Observer() {};
};

#endif