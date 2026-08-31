#ifndef DRONEDISPLAYUNIT_H
#define DRONEDISPLAYUNIT_H

#include "EventUnit.h"
/**
 * @class DroneDisplayUnit
 * @brief Represents a drone demonstration unit at the SkyPulse event.
 *
 * DroneDisplayUnit is a concrete Leaf in the Composite pattern and a
 * concrete Observer in the Observer pattern. It manages drone display
 * activity and reacts to operational and safety-related event notices.
 *
 * The unit keeps track of whether the drones are airborne and whether
 * a demonstration is currently active.
 */

class DroneDisplayUnit : public EventUnit
{
private:
  bool airbone;
  bool demonstrationActive;

public:
  /**
  * @brief Constructs a DroneDisplayUnit.
  *
  * @param name Name used to identify the drone display unit.
  * @param capacity Maximum capacity associated with the unit.
  */
  DroneDisplayUnit(const std::string &name, int capacity);
  
  /**
  * @brief Starts a drone demonstration.
  *
  * Updates the internal state to indicate that the demonstration
  * is active and that the drones are operating.
  */

  void startDemonstration();

  /**
  * @brief Lands all drones associated with the display unit.
  *
  * Used when drone operations must be stopped, for example in
  * response to a runway activation or safety-related notice.
  */

  void landDrones();
  
  /**
  * @brief Reacts to an event notification.
  *
  * Implements the Observer update operation. The DroneDisplayUnit
  * responds according to the type and severity of the supplied Notice.
  * Safety-critical notices may cause active drones to land.
  *
  * @param notice Notice pushed to the drone display unit by its Subject.
  */

  void update(const Notice& notice) override;

  /**
  * @brief Reports the current status of the drone display unit.
  *
  * Displays information about whether the drone demonstration is
  * active and whether the drones are currently airborne.
  */

  virtual void reportStatus() const override;
  /**
  * @brief Destroys the DroneDisplayUnit.
  *
  * The unit does not own the Subject objects that may notify it.
  * If it is owned by an EventGroup, the owning group is responsible
  * for removing its Observer registration before deletion.
  */
  virtual ~DroneDisplayUnit();
};

#endif