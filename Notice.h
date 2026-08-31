#ifndef NOTICE_H
#define NOTICE_H

#include <iostream>

using namespace std;

/**
 * @enum Noticetype
 * @brief Defines the different event notices that can be issued in SkyPulse.
 *
 * Notice types represent operational, capacity, safety and recovery
 * conditions that may be distributed through the Observer notification
 * system.
 */
enum Noticetype
{
    OPEN_NOTICE,        /**< Indicates that an event component should open. */
    CLOSE_NOTICE,       /**< Indicates that an event component should close. */
    SCHEDULE_CHANGE,    /**< Indicates that an event schedule has changed. */
    CAPACITY_ALERT,     /**< Indicates that a capacity-related condition exists. */
    WEATHER_ALERT,      /**< Indicates a weather-related operational warning. */
    TRANSPORT_DELAY,    /**< Indicates a delay affecting event transport services. */
    EVACUATE,           /**< Indicates that evacuation procedures should begin. */
    RESUME,             /**< Indicates that normal operations may resume. */
    RUNWAY_ACTIVE       /**< Indicates that the runway is active and aviation restrictions may apply. */
};

/**
 * @class Notice
 * @brief Encapsulates information about an event notification.
 *
 * Notice is the information object passed through the Observer system.
 * EventFlow uses the Push Observer approach, so a complete Notice object
 * containing its type, message and severity is passed directly to each
 * Observer through update().
 *
 * The severity value represents the importance of the notice and allows
 * concrete observers to determine the appropriate response.
 */
class Notice
{
public:

    /**
     * @brief Constructs a Notice with the supplied event information.
     *
     * @param type Type of event notice being created.
     * @param message Human-readable message describing the event condition.
     * @param severity Severity level associated with the notice.
     */
    Notice(Noticetype type, const string &message, int severity);

    /**
     * @brief Returns the type of this notice.
     *
     * @return Notice type represented by the Noticetype enumeration.
     */
    Noticetype getType() const;

    /**
     * @brief Returns the descriptive message associated with the notice.
     *
     * @return Message describing the event condition.
     */
    string getMessage() const;

    /**
     * @brief Returns the severity level of the notice.
     *
     * @return Severity level associated with the notice.
     */
    int getSeverity() const;

    /**
     * @brief Constructs a default Notice.
     *
     * Creates a Notice using the default values defined by the
     * implementation.
     */
    Notice();

private:
    Noticetype type;
    string message;
    int severity;
};

#endif /* NOTICE_H */