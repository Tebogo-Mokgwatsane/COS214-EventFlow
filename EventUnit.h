#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"

/**
 * @class EventUnit
 * @brief Provides common behaviour for individual event units.
 *
 * EventUnit is the Leaf-level base class in the Composite design pattern.
 * It represents the shared behaviour of concrete event units such as
 * AirDisplayStage, DroneDisplayUnit, Gate, MedicalPost and other
 * operational units.
 *
 * EventUnit stores the capacity of an individual event unit and provides
 * common implementations for opening, closing, capacity retrieval and
 * status reporting.
 *
 * Concrete subclasses inherit this common behaviour and provide their own
 * Observer reactions through update().
 */
class EventUnit : public EventComponent
{
private:
    int capacity;

public:

    /**
     * @brief Constructs an EventUnit.
     *
     * Initializes the event unit with a name and maximum capacity.
     *
     * @param name Name used to identify the event unit.
     * @param capacity Maximum capacity associated with the unit.
     */
    EventUnit(const std::string &name, int capacity);

    /**
     * @brief Opens the event unit.
     *
     * Changes the operational state of the unit so that it is considered
     * open and active within the event.
     */
    virtual void open();

    /**
     * @brief Closes the event unit.
     *
     * Changes the operational state of the unit so that it is considered
     * closed and unavailable for normal event operations.
     */
    virtual void close();

    /**
     * @brief Returns the capacity of the event unit.
     *
     * @return Maximum capacity assigned to this individual event unit.
     */
    virtual int getCapacity() const override;

    /**
     * @brief Reports the current status of the event unit.
     *
     * Displays common information about the unit, such as its name,
     * open or closed state, and capacity.
     */
    virtual void reportStatus() const override;

    /**
     * @brief Destroys the EventUnit.
     *
     * Provides safe polymorphic destruction for concrete event units
     * derived from EventUnit.
     */
    virtual ~EventUnit();
};

#endif