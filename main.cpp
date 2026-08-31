#include "EventComponent.h"
#include "EventGroup.h"
#include "EventControl.h"
#include "Notice.h"

//conc classes
#include "AirDisplayStage.h"
#include "Gate.h"
#include "FireResponseTeam.h"
#include "DroneDisplayUnit.h"
#include "InformationScreen.h"
#include "MedicalPost.h"
#include "ShuttleStop.h"
#include "VendorStall.h"

#include <iostream>
#include <string>

using namespace std; 

// Forward declarations
EventGroup *buildDefaultEvent();
void printMenu();
void issueNoticeMenu(EventControl &control);
void capacityDemo(EventGroup *root);
void transferDemo(EventGroup *root);
void fullDemo(EventControl &control, EventGroup *root);
void registerCascade(EventGroup *root, EventControl &control);

EventGroup *buildDefaultEvent()
{
  //FOR TEAM: add any other concrete EventUnit types/ EventGroups you implement to the default event tree here:
  EventGroup *root = new EventGroup("SkyPulse Airshow");

  EventGroup *airside = new EventGroup("Airside Zone");
  EventGroup *publicZone = new EventGroup("Public Zone");
  EventGroup *expoZone = new EventGroup("Expo Zone");

  EventGroup *runway = new EventGroup("Runway Sector");
  EventGroup *droneSector = new EventGroup("Drone Sector");

  runway->add(new AirDisplayStage("Main Air Display", 80, "Slot A"));
  runway->add(new Gate("Airside Gate", 150));
  runway->add(new FireResponseTeam("Airside Fire Team", 12));

  droneSector->add(new DroneDisplayUnit("Drone Swarm Unit", 8));
  droneSector->add(new InformationScreen("Drone Info Screen"));

  airside->add(runway);
  airside->add(droneSector);

  EventGroup *grandstand = new EventGroup("Grandstand Sector");
  grandstand->add(new Gate("Admission Gate", 400));
  grandstand->add(new MedicalPost("Grandstand Medical", 25));
  grandstand->add(new InformationScreen("Grandstand Screen"));

  EventGroup *transport = new EventGroup("Transport Sector");
  transport->add(new ShuttleStop("Main Shuttle Stop", 50, "Main Loop"));

  publicZone->add(grandstand);
  publicZone->add(transport);

  EventGroup *hangar = new EventGroup("Exhibition Hangar");
  hangar->add(new VendorStall("Aero Merchandise", 20, true));
  hangar->add(new VendorStall("Food Court Stall", 30, false));
  hangar->add(new InformationScreen("Hangar Display"));

  expoZone->add(hangar);

  root->add(airside);
  root->add(publicZone);
  root->add(expoZone);

  return root;
}

//Attach zones/sectors/units so notices cascade Control -> Zone -> Sector -> Leaf 
void registerCascade(EventGroup *root, EventControl &control)
{
  for (size_t i = 0; i < root->childCount(); ++i)
  {
    EventComponent *zoneComp = root->getChild(i);
    control.attach(zoneComp);
    EventGroup *zone = dynamic_cast<EventGroup *>(zoneComp);
    if (!zone)
      continue;
    for (size_t j = 0; j < zone->childCount(); ++j)
    {
      EventComponent *secComp = zone->getChild(j);
      zone->attach(secComp);
      EventGroup *sec = dynamic_cast<EventGroup *>(secComp);
      if (!sec)
        continue;
      for (size_t k = 0; k < sec->childCount(); ++k)
        sec->attach(sec->getChild(k));
    }
  }
}

void printMenu()
{
  cout << "\n========== SkyPulse EventFlow Interactive ==========\n"
            << " 1. Print event tree\n"
            << " 2. Open entire event\n"
            << " 3. Close entire event\n"
            << " 4. Report status of entire event\n"
            << " 5. Issue notice from Control (cascading)\n"
            << " 6. Attach / Detach observers\n"
            << " 7. Transfer a unit between groups\n"
            << " 8. Capacity check & conditional alert\n"
            << " 9. Run full demonstration sequence\n"
            << " 0. Quit (clean destruction)\n"
            << "====================================================\n"
            << "Choice: ";
}

void issueNoticeMenu(EventControl &control)
{
  cout << "\nSelect notice type:\n"
            << " 1. OPEN_NOTICE\n"
            << " 2. CLOSE_NOTICE\n"
            << " 3. SCHEDULE_CHANGE\n"
            << " 4. CAPACITY_ALERT\n"
            << " 5. WEATHER_ALERT\n"
            << " 6. EVACUATE\n"
            << " 7. RESUME\n"
            << " 8. TRANSPORT_DELAY\n"
            << " 9. RUNWAY_ACTIVE\n"
            << " Choice: ";
  int c;
  cin >> c;
  string msg;
  cout << "Optional message: ";
  cin.ignore(10000, '\n');
  getline(cin, msg);

  int sev = 1;
  if (c == 5)
  {
    cout << "Severity (1-5): ";
    cin >> sev;
  }

  Noticetype t = OPEN_NOTICE;
  switch (c)
  {
  case 1: t = OPEN_NOTICE; break;
  case 2: t = CLOSE_NOTICE; break;
  case 3: t = SCHEDULE_CHANGE; break;
  case 4: t = CAPACITY_ALERT; break;
  case 5: t = WEATHER_ALERT; break;
  case 6: t = EVACUATE; break;
  case 7: t = RESUME; break;
  case 8: t = TRANSPORT_DELAY; break;
  case 9: t = RUNWAY_ACTIVE; break;
  default:
    cout << "Invalid.\n";
    return;
  }
  if (msg.empty())
    msg = "Control notice";
  control.issueNotice(Notice(t, msg, sev));
}

void capacityDemo(EventGroup *root)
{
  cout << "\n---Capacity Conditional Demo---\n";
  EventGroup *publicZone = nullptr;
  EventGroup *grandstand = nullptr;

  for (size_t i = 0; i < root->childCount(); ++i)
  {
    EventComponent *c = root->getChild(i);
    if (c && c->getName() == "Public Zone")
    {
      publicZone = dynamic_cast<EventGroup *>(c);
      break;
    }
  }
  if (!publicZone)
  {
    cout << "Public Zone not found.\n";
    return;
  }
  for (size_t i = 0; i < publicZone->childCount(); ++i)
  {
    EventComponent *c = publicZone->getChild(i);
    if (c && c->getName() == "Grandstand Sector")
    {
      grandstand = dynamic_cast<EventGroup *>(c);
      break;
    }
  }
  if (!grandstand)
  {
    cout << "Grandstand not found.\n";
    return;
  }

  int maxCap = grandstand->getCapacity();
  cout << "Grandstand capacity = " << maxCap << "\n";
  cout << "Enter current occupancy: ";
  int occ;
  cin >> occ;

  if (occ >= maxCap)
  {
    cout << "[CONDITION] occupancy >= capacity  --> CAPACITY_ALERT\n";
    Notice alert(CAPACITY_ALERT, "Grandstand at maximum capacity", 4);
    grandstand->update(alert);
  }
  else
  {
    cout << "[CONDITION] occupancy < capacity  --> continue admitting\n";
    cout << "No alert issued. Gates remain open.\n";
  }
}

void transferDemo(EventGroup *root)
{
  cout << "\n---Runtime Reorganisation (Transfer)---\n";
  EventGroup *runway = nullptr;
  EventGroup *grandstand = nullptr;
  EventComponent *fireTeam = nullptr;

  for (size_t i = 0; i < root->childCount(); ++i)
  {
    EventGroup *zone = dynamic_cast<EventGroup *>(root->getChild(i));
    if (!zone) continue;
    if (zone->getName() == "Airside Zone")
    {
      for (size_t j = 0; j < zone->childCount(); ++j)
      {
        EventGroup *sec = dynamic_cast<EventGroup *>(zone->getChild(j));
        if (sec && sec->getName() == "Runway Sector")
        {
          runway = sec;
          for (size_t k = 0; k < sec->childCount(); ++k)
          {
            if (sec->getChild(k)->getName() == "Airside Fire Team")
              fireTeam = sec->getChild(k);
          }
        }
      }
    }
    if (zone->getName() == "Public Zone")
    {
      for (size_t j = 0; j < zone->childCount(); ++j)
      {
        EventGroup *sec = dynamic_cast<EventGroup *>(zone->getChild(j));
        if (sec && sec->getName() == "Grandstand Sector")
          grandstand = sec;
      }
    }
  }

  if (runway && grandstand && fireTeam)
  {
    cout << "Before transfer (Runway Sector):\n";
    runway->printTree("  ");
    runway->transferChild(fireTeam, grandstand);
    cout << "After transfer (Grandstand Sector):\n";
    grandstand->printTree("  ");
  }
  else
  {
    cout << "Could not locate units for transfer demo.\n";
  }
}

void fullDemo(EventControl &control, EventGroup *root)
{
  cout << "\n===FULL AUTO DEMONSTRATION SEQUENCE===\n";

  registerCascade(root, control);
  cout << "Observers registered (cascading hierarchy).\n";

  control.issueNotice(Notice(OPEN_NOTICE, "Gates open – welcome to SkyPulse!", 1));
  control.issueNotice(Notice(SCHEDULE_CHANGE, "Air display delayed 15 min", 1));
  control.issueNotice(Notice(WEATHER_ALERT, "Strong cross-winds on runway", 4));
  control.issueNotice(Notice(RUNWAY_ACTIVE, "Main runway now active", 2));

  cout << "\n(Capacity demo uses occupancy input)\n";
  capacityDemo(root);

  transferDemo(root);

  control.issueNotice(Notice(EVACUATE, "Immediate evacuation of airside", 5));
  control.issueNotice(Notice(RESUME, "All clear – operations resume", 1));

  if (root->childCount() > 0)
  {
    EventComponent *first = root->getChild(0);
    control.detach(first);
    cout << "Detached " << first->getName() << " from Control.\n";
    control.issueNotice(Notice(CLOSE_NOTICE, "Closing for the day", 1));
  }

  cout << "\n===END OF DEMONSTRATION===\n";
}

int main()
{
  cout << "SkyPulse Airshow & Aviation Expo – EventFlow Engine\n";

  EventGroup *root = buildDefaultEvent();
  EventControl control("SkyPulse Control Centre");

  registerCascade(root, control);

  bool running = true;
  while (running)
  {
    printMenu();
    int choice;
    if (!(cin >> choice))
    {
      cin.clear();
      cin.ignore(10000, '\n');
      continue;
    }

    switch (choice)
    {
    case 1:
      cout << "\n---Event Tree---\n";
      root->printTree();
      break;
    case 2:
      root->open();
      break;
    case 3:
      root->close();
      break;
    case 4:
      root->reportStatus();
      break;
    case 5:
      issueNoticeMenu(control);
      break;
    case 6:
    {
      cout << "Currently " << control.observerCount() << " observers attached to Control.\n";
      cout << "1 = re-attach cascade, 2 = detach all top zones: ";
      int sub;
      cin >> sub;
      if (sub == 1)
      {
        registerCascade(root, control);
        cout << "Re-attached cascade.\n";
      }
      else if (sub == 2)
      {
        for (size_t i = 0; i < root->childCount(); ++i)
          control.detach(root->getChild(i));
        cout << "Detached top zones.\n";
      }
      break;
    }
    case 7:
      transferDemo(root);
      break;
    case 8:
      capacityDemo(root);
      break;
    case 9:
      fullDemo(control, root);
      break;
    case 0:
      running = false;
      break;
    default:
      cout << "Unknown option.\n";
    }
  }

  cout << "\nShutting down – destroying ownership tree...\n";
  delete root;
  cout << "All owned components released. Goodbye.\n";
  return 0;
}