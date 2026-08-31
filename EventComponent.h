#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

#include "Observer.h"
#include <string>
#include <vector>

/**
 * @class EventComponent
 * @brief Defines the common interface for all objects in the event structure.
 *
 * EventComponent is the Component participant in the Composite design pattern.
 * It allows both individual event units and groups of event units to be treated
 * uniformly through common operations such as opening, closing, reporting
 * status and calculating capacity.
 *
 * EventComponent also inherits from Observer, allowing components in the
 * event hierarchy to receive event notifications through the Observer pattern.
 *
 * Concrete subclasses must provide implementations for the common event
 * operations and for the Observer update operation.
 */
class EventComponent : public Observer
{
protected:

    /**
     * @brief Name used to identify this event component.
     */
    std::string name;

    /**
     * @brief Indicates whether this event component is currently open.
     */
    bool isOpen;
public:

    /**
     * @brief Constructs an EventComponent with the specified name.
     *
     * Initializes the common state shared by all event components.
     *
     * @param name Name used to identify the event component.
     */
    EventComponent(const std::string &name);

    /**
     * @brief Opens the event component.
     *
     * Concrete subclasses define how the component becomes operational.
     */
    virtual void open() = 0;

    /**
     * @brief Closes the event component.
     *
     * Concrete subclasses define how the component becomes non-operational.
     */
    virtual void close() = 0;

    /**
     * @brief Returns the capacity associated with the event component.
     *
     * For a Leaf, this normally represents its own capacity. For a Composite,
     * the capacity may be calculated recursively from its children.
     *
     * @return Capacity of the event component.
     */
    virtual int getCapacity() const = 0;

    /**
     * @brief Reports the current status of the event component.
     *
     * Concrete subclasses provide status information appropriate to their
     * specific event role.
     */
    virtual void reportStatus() const = 0;

    /**
     * @brief Receives an event notification from a Subject.
     *
     * This operation is inherited from the Observer interface and must be
     * implemented by concrete subclasses so that each event component can
     * react appropriately to the supplied Notice.
     *
     * @param notice Notice pushed to the component by a Subject.
     */
    virtual void update(const Notice &notice) = 0;

    /**
     * @brief Returns the name of the event component.
     *
     * @return Name identifying the event component.
     */
    std::string getName() const;

    /**
     * @brief Virtual destructor for EventComponent.
     *
     * Ensures that derived event components can be destroyed safely through
     * an EventComponent pointer.
     */
    virtual ~EventComponent();
};

#endif