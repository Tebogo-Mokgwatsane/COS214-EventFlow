#ifndef SUTTLESTOP_H
#define SUTTLESTOP_H

#include "EventUnit.h"
#include <string>

/**
 * @class ShuttleStop
 * @brief Represents a shuttle transport stop at the SkyPulse event.
 *
 * ShuttleStop is a concrete Leaf in the Composite pattern and a concrete
 * Observer in the Observer pattern. It manages shuttle route information
 * and reacts to transport-related event notices such as delays or route
 * changes.
 *
 * The stop stores both its normal route and its current active route,
 * allowing temporary route changes to be reversed when normal operations
 * resume.
 */
class ShuttleStop : public EventUnit
{
private:
    std::string normalRoute;
    std::string currentRoute;
    bool delayed;

public:

    /**
     * @brief Constructs a ShuttleStop.
     *
     * @param name Name used to identify the shuttle stop.
     * @param capacity Maximum capacity associated with the shuttle stop.
     * @param normalRoute Normal route assigned to the shuttle stop.
     */
    ShuttleStop(const std::string &name,
                int capacity,
                const std::string &normalRoute);

    /**
     * @brief Sets the delay status of the shuttle stop.
     *
     * @param delayed true if shuttle services are delayed;
     *                false if services are operating normally.
     */
    void setDelayed(bool delayed);

    /**
     * @brief Changes the current shuttle route.
     *
     * Replaces the currently active route with a temporary or alternative
     * route.
     *
     * @param newRoute New route to assign to the shuttle stop.
     */
    void changeRoute(const std::string &newRoute);

    /**
     * @brief Restores the shuttle stop to its normal route.
     *
     * Replaces the current route with the route originally assigned
     * to the shuttle stop.
     */
    void restoreNormalRoute();

    /**
     * @brief Reacts to an event notification.
     *
     * Implements the Observer update operation. The ShuttleStop changes
     * its delay or route state according to the type and severity of the
     * supplied Notice.
     *
     * @param notice Notice pushed to the shuttle stop by its Subject.
     */
    void update(const Notice &notice) override;

    /**
     * @brief Reports the current operational status of the shuttle stop.
     *
     * Displays information such as the current route, normal route and
     * whether shuttle services are currently delayed.
     */
    virtual void reportStatus() const override;

    /**
     * @brief Destroys the ShuttleStop.
     *
     * The ShuttleStop does not own the Subject objects that may notify it.
     * If it is registered as an Observer, that registration must be removed
     * before the stop is destroyed.
     *
     * If the ShuttleStop is owned by an EventGroup, the owning Composite is
     * responsible for deleting it.
     */
    virtual ~ShuttleStop();
};

#endif