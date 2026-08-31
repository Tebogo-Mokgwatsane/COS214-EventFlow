#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H
#include <iostream>
#include "subject.h"
#include "Notice.h"

using namespace std;

/**
 * @class EventControl
 * @brief Central coordinator that issues event notices to registered observers.
 *
 * EventController is a Concrete Subject in the Observer design pattern.
 * It represents the central control point for the SkyPulse event and is
 * responsible for issuing notices to registered observers.
 *
 * The controller stores the most recently issued Notice as currentNotice.
 * When a new notice is issued, registered observers are notified through
 * the inherited Subject notification mechanism.
 *
 * Observer registrations inherited from Subject are non-owning.
 * EventController therefore does not delete registered Observer objects.
 * Observers must remain alive while registered and must be detached before
 * they are destroyed.
 */
class EventControl : public Subject
{
private:
    string name;
    Notice currentNotice;

public:

    /**
     * @brief Constructs an EventController using default initialization.
     *
     * Creates an event controller without explicitly supplying a name
     * or initial notice.
     */
    EventControl() {name="Control";};

    /**
     * @brief Constructs an EventControl with the specified name.
     *
     * Creates the central event controller with the supplied name and a
     * default-initialized current Notice.
     *
     * @param name Name used to identify the event controller.
     */
    EventControl(const string &name);
    /**
     * @brief Constructs an EventController with a name and initial notice.
     *
     * @param name Name used to identify the event controller.
     * @param intialNotice Initial Notice stored by the controller.
     */
    EventControl(const string &name, const Notice &intialNotice);

    /**
     * @brief Returns the most recently stored event notice.
     *
     * The returned reference refers to the Notice owned by this
     * EventController and remains valid while the controller and its
     * current notice remain alive.
     *
     * @return Const reference to the current Notice.
     */
    const Notice &getCurrentNotice() const;

    /**
     * @brief Issues a new notice to registered observers.
     *
     * Stores the supplied notice as the current notice and distributes
     * it to registered observers using the Subject notification mechanism.
     *
     * EventFlow uses the Push Observer approach, so the Notice is passed
     * directly to each Observer's update() operation.
     *
     * @param notice Notice to issue to registered observers.
     */
    void issueNotice(const Notice &notice);
    /**
     * @brief Returns the number of observers currently registered.
     *
     * The returned count represents non-owning Observer registrations
     * maintained by the inherited Subject.
     *
     * @return Number of currently registered observers.
     */
    size_t observerCount() const { return registered.size(); }
    };
#endif