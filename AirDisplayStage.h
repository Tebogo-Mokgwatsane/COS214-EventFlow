#ifndef AIRDISPLAYSTAGE_H
#define AIRDISPLAYSTAGE_H

#include "EventUnit.h"
#include <string>
/**
 * @class AirDisplayStage
 * @brief Represents an air display stage within the SkyPulse event.
 *
 * AirDisplayStage is a concrete Leaf in the Composite pattern and a
 * concrete Observer in the Observer pattern. It reacts to operational
 * notices such as weather alerts, runway activity and event status
 * changes.
 */
class AirDisplayStage : public EventUnit
{
private:
  std::string currentSlot;
  bool performing;
  bool paused;

public:
  /**
  * @brief Constructs an air display stage.
  *
  * @param name Name used to identify the stage.
  * @param capacity Maximum capacity associated with the stage.
  * @param currentSlot Initial scheduled slot for the performance.
  */
  AirDisplayStage(const std::string &name, int capacity, const std::string &currentSlot);

  /**
  * @brief Starts the scheduled air display performance.
  *
  * Changes the operational state of the stage to indicate that
  * a performance is currently taking place.
  */
  void startPerformance();

  /**
  * @brief Pauses the current air display performance.
  *
  * Temporarily suspends an active performance while allowing it
  * to be resumed later when conditions permit.
  */
  void pausePerformance();

  /**
  * @brief Stops the current air display performance.
  *
  * Ends the current performance and updates the operational state
  * of the air display stage accordingly.
  */
  void stopPerformance();

  /**
  * @brief Changes the scheduled performance slot.
  *
  * Updates the time or schedule slot associated with the air display
  * stage.
  *
  * @param slot New performance slot to assign to the stage.
  */

  void setCurrentSlot(const std::string &slot);

  /**
  * @brief Reacts to an event notification.
  *
  * The response depends on the type and severity of the supplied
  * notice. For example, a weather alert may cause air displays
  * to be paused.
  *
  * @param notice Notice pushed to the stage by its Subject.
  */

  void update(const Notice& notice) override;
  
  /**
  * @brief Reports the current operational status of the air display stage.
  *
  * Displays information about the stage such as its current performance
  * slot and operational state.
  */

  virtual void reportStatus() const;

  /** @brief Destroys the AirDisplayStage.
  *
  * The AirDisplayStage does not own the Subject that may notify it.
  * When the stage is owned by an EventGroup, the owning EventGroup is
  * responsible for removing its Observer registration before deleting it.
  */

  virtual ~AirDisplayStage();
};

#endif