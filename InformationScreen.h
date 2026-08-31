#ifndef INFORMATIONSCREEN_H
#define INFORMATIONSCREEN_H

#include "EventUnit.h"
#include <string>

/**
 * @class InformationScreen
 * @brief Represents an information display screen at the SkyPulse event.
 *
 * InformationScreen is a concrete Leaf in the Composite pattern and a
 * concrete Observer in the Observer pattern. It receives event notices
 * and presents relevant messages to attendees.
 *
 * The screen stores the message that is currently being displayed and
 * updates that message when new event information is received.
 */
class InformationScreen : public EventUnit
{
private:
    std::string displayedMessage;

public:

    /**
     * @brief Constructs an InformationScreen.
     *
     * Creates an information screen with the specified identifying name.
     *
     * @param name Name used to identify the information screen.
     */
    InformationScreen(const std::string &name);

    /**
     * @brief Reacts to an event notification.
     *
     * Implements the Observer update operation. The InformationScreen
     * uses the supplied Notice to update the information displayed to
     * event attendees.
     *
     * @param notice Notice pushed to the information screen by its Subject.
     */
    void update(const Notice &notice) override;

    /**
     * @brief Displays the specified message on the information screen.
     *
     * Replaces the currently displayed message with the supplied text.
     *
     * @param message Message to display on the screen.
     */
    void displayMessage(const std::string &message);

    /**
     * @brief Reports the current status of the information screen.
     *
     * Displays information about the screen together with the message
     * that is currently being shown.
     */
    virtual void reportStatus() const override;

    /**
     * @brief Destroys the InformationScreen.
     *
     * The InformationScreen does not own the Subject objects that may
     * notify it. If it is registered as an Observer, that registration
     * must be removed before the screen is destroyed.
     *
     * If the screen is owned by an EventGroup, the owning Composite is
     * responsible for deleting it.
     */
    virtual ~InformationScreen();
};

#endif