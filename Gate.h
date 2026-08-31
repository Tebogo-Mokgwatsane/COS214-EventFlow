#ifndef GATE_H
#define GATE_H

#include "EventUnit.h"

/**
 * @class Gate
 * @brief Represents an attendee access gate at the SkyPulse event.
 *
 * Gate is a concrete Leaf in the Composite pattern and a concrete Observer
 * in the Observer pattern. It manages attendee admission and can change its
 * operating mode in response to event notices such as capacity alerts,
 * closures, evacuations, or resumption notices.
 *
 * The gate tracks whether it is currently admitting attendees, whether it is
 * operating in exit-only mode, and its current number of attendees.
 */
class Gate : public EventUnit
{
private:
    bool admitting;
    bool exitOnly;
    int currentCapacity;

public:

    /**
     * @brief Constructs a Gate.
     *
     * @param name Name used to identify the gate.
     * @param capacity Maximum capacity associated with the gate.
     */
    Gate(const std::string &name, int capacity);

    /**
     * @brief Starts admitting attendees through the gate.
     *
     * Changes the gate's operational state so that new attendees may enter
     * through this access point.
     */
    void startAdmitting();

    /**
     * @brief Stops admitting attendees through the gate.
     *
     * Prevents further entry through the gate while preserving the gate's
     * current operational information.
     */
    void stopAdmitting();

    /**
     * @brief Sets whether the gate operates in exit-only mode.
     *
     * When exit-only mode is enabled, attendees may leave through the gate
     * but new attendees should not be admitted.
     *
     * @param exitOnly true to place the gate in exit-only mode;
     *                 false to disable exit-only mode.
     */
    void setExitOnly(bool exitOnly);

    /**
     * @brief Updates the gate's current attendee count.
     *
     * @param currentCapacity Current number of attendees associated with
     *                        this gate.
     */
    void setCurrentCapacity(int currentCapacity);

    /**
     * @brief Reacts to an event notification.
     *
     * Implements the Observer update operation. The Gate changes its
     * admission behaviour according to the type and severity of the
     * supplied Notice. For example, capacity or evacuation notices may
     * stop admission or place the gate in exit-only mode.
     *
     * @param notice Notice pushed to the gate by its Subject.
     */
    void update(const Notice &notice) override;

    /**
     * @brief Reports the current operational status of the gate.
     *
     * Displays information such as whether the gate is admitting attendees,
     * whether it is in exit-only mode, and its current capacity state.
     */
    virtual void reportStatus() const override;

    /**
     * @brief Destroys the Gate.
     *
     * The Gate does not own the Subject objects that may notify it.
     * If it is registered as an Observer, that registration must be removed
     * before the Gate is destroyed.
     *
     * If the Gate is owned by an EventGroup, the owning Composite is
     * responsible for deleting it.
     */
    virtual ~Gate();
};

#endif