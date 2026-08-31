#ifndef MEDICALPOST_H
#define MEDICALPOST_H

#include "EventUnit.h"

/**
 * @class MedicalPost
 * @brief Represents a medical support post at the SkyPulse event.
 *
 * MedicalPost is a concrete Leaf in the Composite pattern and a concrete
 * Observer in the Observer pattern. It provides medical support during
 * normal event operations and can switch into emergency mode when required
 * by safety-related notices.
 *
 * The medical post tracks whether it is currently operating in emergency
 * mode and reacts to event notifications accordingly.
 */
class MedicalPost : public EventUnit
{
private:
    bool emergencyMode;

public:

    /**
     * @brief Constructs a MedicalPost.
     *
     * @param name Name used to identify the medical post.
     * @param capacity Maximum capacity associated with the medical post.
     */
    MedicalPost(const std::string &name, int capacity);

    /**
     * @brief Reacts to an event notification.
     *
     * Implements the Observer update operation. The MedicalPost changes
     * its operational state according to the type and severity of the
     * supplied Notice. Emergency-related notices may cause the post to
     * enter emergency mode.
     *
     * @param notice Notice pushed to the medical post by its Subject.
     */
    void update(const Notice &notice) override;

    /**
     * @brief Places the medical post into emergency mode.
     *
     * Changes the internal state to indicate that the post is responding
     * to an emergency situation.
     */
    void enterEmergencyMode();

    /**
     * @brief Returns the medical post to normal operating mode.
     *
     * Ends emergency mode once the relevant emergency or safety condition
     * has been resolved.
     */
    void exitEmergencyMode();

    /**
     * @brief Reports the current operational status of the medical post.
     *
     * Displays information such as whether the medical post is currently
     * operating in emergency mode.
     */
    virtual void reportStatus() const override;

    /**
     * @brief Destroys the MedicalPost.
     *
     * The MedicalPost does not own the Subject objects that may notify it.
     * If it is registered as an Observer, that registration must be removed
     * before the medical post is destroyed.
     *
     * If the MedicalPost is owned by an EventGroup, the owning Composite is
     * responsible for deleting it.
     */
    virtual ~MedicalPost();
};

#endif