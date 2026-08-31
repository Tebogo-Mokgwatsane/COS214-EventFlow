#ifndef FIRERESPONSETEAM_H
#define FIRERESPONSETEAM_H

#include "EventUnit.h"

/**
 * @class FireResponseTeam
 * @brief Represents the fire and emergency response unit at the SkyPulse event.
 *
 * FireResponseTeam is a concrete Leaf in the Composite pattern and a
 * concrete Observer in the Observer pattern. It provides emergency-response
 * behaviour for safety-related notices and can change between normal and
 * elevated readiness states.
 *
 * The team may also be dynamically reassigned between EventGroup objects
 * during execution, so Composite ownership and Observer registration must
 * be updated separately when it is moved.
 */
class FireResponseTeam : public EventUnit
{
private:
    bool highReadiness;
    bool deployed;

public:

    /**
     * @brief Constructs a FireResponseTeam.
     *
     * @param name Name used to identify the fire response team.
     * @param capacity Maximum capacity associated with the team.
     */
    FireResponseTeam(const std::string &name, int capacity);

    /**
     * @brief Places the fire response team in a high-readiness state.
     *
     * Used when an operational or safety notice requires the team to
     * prepare for possible emergency deployment.
     */
    void increaseReadiness();

    /**
     * @brief Returns the fire response team to normal readiness.
     *
     * Restores the team's readiness state after elevated alert conditions
     * have ended.
     */
    void normalReadiness();

    /**
     * @brief Reacts to an event notification.
     *
     * Implements the Observer update operation. The FireResponseTeam
     * changes its readiness or deployment state according to the type
     * and severity of the supplied Notice.
     *
     * @param notice Notice pushed to the fire response team by its Subject.
     */
    void update(const Notice &notice) override;

    /**
     * @brief Deploys the fire response team.
     *
     * Changes the team's state to indicate that it is actively responding
     * to an incident.
     */
    void deploy();

    /**
     * @brief Stands down the fire response team.
     *
     * Ends an active deployment and returns the team to a non-deployed
     * operational state.
     */
    void standDown();

    /**
     * @brief Reports the current status of the fire response team.
     *
     * Displays information such as whether the team is in high readiness
     * and whether it is currently deployed.
     */
    virtual void reportStatus() const override;

    /**
     * @brief Destroys the FireResponseTeam.
     *
     * The team does not own the Subject objects that may notify it.
     * If it is registered as an Observer, that registration must be removed
     * before the team is destroyed.
     *
     * If the team is owned by an EventGroup, the owning Composite is
     * responsible for deleting it unless ownership has first been released
     * using remove().
     */
    virtual ~FireResponseTeam();
};

#endif