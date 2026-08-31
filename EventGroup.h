#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include "EventComponent.h"
#include "subject.h"
#include <vector>

/**
 * @class EventGroup
 * @brief Represents a composite grouping of event components.
 *
 * EventGroup is the Composite participant in the Composite design pattern.
 * It can contain both individual EventUnit objects and other EventGroup
 * objects, allowing the SkyPulse event to be organised into a nested
 * part-whole structure.
 *
 * EventGroup also participates in the Observer pattern as both an Observer
 * and a Subject. It can receive a Notice from a Subject above it through
 * update(), then propagate that Notice to its own registered observers
 * using notify().
 *
 * The EventGroup owns all EventComponent pointers stored in its children
 * collection. Registered Observer pointers inherited from Subject are
 * non-owning and are not deleted by EventGroup.
 */
class EventGroup : public EventComponent, public Subject
{
private:
    std::vector<EventComponent *> children;

public:

    /**
     * @brief Constructs an EventGroup with the specified name.
     *
     * Creates an empty composite group that can later be populated with
     * EventComponent children.
     *
     * @param name Name used to identify the event group.
     */
    EventGroup(const std::string &name);

    /**
     * @brief Receives a Notice and propagates it to registered observers.
     *
     * EventGroup acts as both an Observer and a Subject. When it receives
     * a Notice through update(), it forwards the Notice to observers
     * registered with this group, allowing notifications to cascade
     * through multiple levels of the event hierarchy.
     *
     * @param notice Notice received from a Subject above this group.
     */
    void update(const Notice &notice) override;

    /**
     * @brief Adds a child component to this EventGroup.
     *
     * Ownership of the supplied child is transferred to this EventGroup.
     * Once added, the group is responsible for eventually deleting the
     * child unless ownership is released using remove().
     *
     * Adding a child establishes Composite ownership only. It does not
     * automatically register the child as an Observer.
     *
     * @param child Pointer to the EventComponent to add.
     *              The pointer must remain valid and must not be nullptr.
     */
    void add(EventComponent *child);

    /**
     * @brief Removes a child from this EventGroup without deleting it.
     *
     * This operation releases Composite ownership of the specified child.
     * The returned pointer may then be transferred to another EventGroup
     * or deleted by the caller.
     *
     * Removing a child from the Composite does not automatically remove
     * its Observer registration. If the child is registered as an Observer,
     * detach() should be called before or as part of the transfer process.
     *
     * @param child Pointer to the child component to remove.
     *
     * @return Pointer to the removed child if found, otherwise nullptr.
     */
    EventComponent *remove(EventComponent *child);

    /**
     * @brief Opens this EventGroup and its contained components.
     *
     * Applies the open operation recursively to the children of the group,
     * demonstrating uniform treatment of Leaves and nested Composites.
     */
    virtual void open();

    /**
     * @brief Closes this EventGroup and its contained components.
     *
     * Applies the close operation recursively to the children of the group.
     */
    virtual void close();

    /**
     * @brief Calculates the total capacity of this EventGroup.
     *
     * The capacity is obtained recursively from the capacities of all
     * contained child components.
     *
     * @return Total capacity of this group and its descendants.
     */
    virtual int getCapacity() const;

    /**
     * @brief Reports the current status of this EventGroup.
     *
     * Reports the group's own state together with relevant status
     * information from its contained child components.
     */
    void reportStatus() const;
    /**
     * @brief Returns the number of direct children owned by this EventGroup.
     *
     * Only direct children are counted. Descendants contained inside nested
     * EventGroup objects are not included in this value.
     *
     * @return Number of direct EventComponent children.
     */
    size_t childCount() const { return children.size(); }
    
    /**
     * @brief Returns the child at the specified position.
     *
     * The returned pointer is non-owning. Ownership remains with this
     * EventGroup and the caller must not delete the returned child.
     *
     * @param index Zero-based index of the child to retrieve.
     *
     * @return Pointer to the requested child if the index is valid;
     *         otherwise nullptr.
     */
    EventComponent *getChild(size_t index) const;

    /**
     * @brief Prints the Composite ownership tree rooted at this EventGroup.
     *
     * Displays this group and recursively displays nested EventGroup objects.
     * Leaf components are displayed using their component names.
     *
     * @param indent Prefix used to indent the current level of the tree.
     *               The default empty string is suitable for the root group.
     */
    void printTree(const std::string &indent = "") const;

    /**
     * @brief Transfers a child component to another EventGroup.
     *
     * Releases this group's ownership of the child, removes its Observer
     * registration from this group, transfers Composite ownership to the
     * new parent, and registers the child as an Observer of the new parent.
     *
     * The child is not deleted during the transfer. On successful completion,
     * newParent becomes responsible for the lifetime and eventual deletion
     * of the transferred child.
     *
     * @param child Pointer to the child component to transfer.
     *              Must not be nullptr and must currently belong to this group.
     * @param newParent Pointer to the EventGroup that will receive ownership.
     *                  Must not be nullptr and must not be this group.
     *
     * @return true if the transfer succeeds; otherwise false.
     */
    bool transferChild(EventComponent *child, EventGroup *newParent);
    
    /**
     * @brief Destroys this EventGroup and all children it owns.
     *
     * Before deleting an owned child, the group removes that child from
     * its Observer registration list if it is currently registered.
     *
     * EventGroup deletes only the EventComponent objects stored in its
     * children collection. It does not delete Observer pointers that are
     * merely registered through Subject.
     */
    virtual ~EventGroup();
};

#endif