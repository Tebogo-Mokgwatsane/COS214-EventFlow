#ifndef VENDORSTALL_H
#define VENDORSTALL_H

#include "EventUnit.h"

/**
 * @class VendorStall
 * @brief Represents a vendor stall operating at the SkyPulse event.
 *
 * VendorStall is a concrete Leaf in the Composite pattern and a concrete
 * Observer in the Observer pattern. It manages whether the stall is
 * currently serving customers and whether it operates outdoors.
 *
 * The stall can react differently to event notices depending on its
 * location. For example, an outdoor vendor may need to stop serving
 * during severe weather conditions.
 */
class VendorStall : public EventUnit
{
private:
    bool serving;
    bool outdoor;

public:

    /**
     * @brief Constructs a VendorStall.
     *
     * @param name Name used to identify the vendor stall.
     * @param capacity Maximum capacity associated with the stall.
     * @param outdoor true if the vendor stall operates outdoors;
     *                false if it operates indoors.
     */
    VendorStall(const std::string &name, int capacity, bool outdoor);

    /**
     * @brief Starts service at the vendor stall.
     *
     * Changes the stall's operational state so that it is actively
     * serving customers.
     */
    void startServing();

    /**
     * @brief Stops service at the vendor stall.
     *
     * Changes the stall's operational state so that it is no longer
     * serving customers.
     */
    void stopServing();

    /**
     * @brief Determines whether the vendor stall operates outdoors.
     *
     * @return true if the stall is outdoors; otherwise false.
     */
    bool isOutdoor() const;

    /**
     * @brief Reacts to an event notification.
     *
     * Implements the Observer update operation. The VendorStall changes
     * its serving state according to the type and severity of the supplied
     * Notice. Outdoor stalls may react differently to weather-related
     * notices.
     *
     * @param notice Notice pushed to the vendor stall by its Subject.
     */
    void update(const Notice &notice) override;

    /**
     * @brief Reports the current operational status of the vendor stall.
     *
     * Displays information such as whether the stall is serving customers
     * and whether it is located outdoors.
     */
    virtual void reportStatus() const override;

    /**
     * @brief Destroys the VendorStall.
     *
     * The VendorStall does not own the Subject objects that may notify it.
     * If it is registered as an Observer, that registration must be removed
     * before the stall is destroyed.
     *
     * If the VendorStall is owned by an EventGroup, the owning Composite is
     * responsible for deleting it.
     */
    virtual ~VendorStall();
};

#endif