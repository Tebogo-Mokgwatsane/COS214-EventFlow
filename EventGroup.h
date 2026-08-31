#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include "EventComponent.h"
#include "Subject.h"
#include <vector>
#include <string>

class EventGroup : public EventComponent,public Subject

{
private:
  std::vector<EventComponent *> children;

public:
  EventGroup(const std::string &name);
  void update(const Notice& notice) override;
  void add(EventComponent *child);
  EventComponent *remove(EventComponent *child);

  void open() override;
  void close() override;
  int getCapacity() const override;
  void reportStatus() const override;

  //Number of direct children.
  size_t childCount() const { return children.size(); }

  //Child at index, or nullptr if out of range.
  EventComponent *getChild(size_t index) const;

  //Pretty-print the ownership tree(To be used in main)
  void printTree(const std::string &indent = "") const;

  /**
   * Transfer ownership of child to newParent.
   * Detaches from this group's observer list, removes from children,
   * adds to newParent and attaches as observer of newParent.
   */
  bool transferChild(EventComponent *child, EventGroup *newParent);

  virtual ~EventGroup();
};

#endif