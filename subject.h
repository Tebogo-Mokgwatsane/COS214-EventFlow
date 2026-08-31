#ifndef SUBJECT_H
#define SUBJECT_H
#include "Observer.h"
#include <iostream>
#include <vector>
using namespace std;
/**
 * @class Subject
 * @brief Abstract Subject participant in the Observer design pattern.
 *
 * Maintains a list of registered observers and sends notices to them.
 *
 * Observer pointers are non-owning. The Subject does not delete
 * registered observers.
 */
class Subject
{
    public:
     /**
     * @brief Registers an observer for future notifications.
     *
     * The pointer is stored as non-owning.
     *
     * @param observer Pointer to the observer to register.
     */

        virtual void attach(Observer* observer);

    /**
     * @brief Removes an observer from the registration list.
     *
     * @param observer Pointer to the observer to remove.
     */
        virtual void detach(Observer* observer);
    
     /**
     * @brief Sends a notice to all currently registered observers.
     *
     * @param notice Notice to distribute.
     */

        virtual void notify(const Notice& notice);
    
    /**
     * @brief Virtual destructor for Subject.
     */
    
        virtual ~Subject()=0;
protected:

    /**
     * @brief Stores the observers currently registered with this Subject.
     *
     * These pointers are non-owning. The Subject does not delete the
     * Observer objects contained in this collection.
     */
    std::vector<Observer*> registered;

    /**
     * @brief Checks whether an Observer is already registered.
     *
     * @param observer Pointer to the Observer to search for.
     *
     * @return true if the Observer is currently registered;
     *         otherwise false.
     */
    bool isRegistered(Observer *observer) const;

    /**
     * @brief Clears all Observer registrations.
     *
     * This operation removes the stored non-owning Observer pointers
     * without deleting the Observer objects.
     */
    void clearObserver();
};
#endif