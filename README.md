# EventFlow – SkyPulse Airshow & Aviation Expo

**COS 214 Practical 3** – Live Event Coordination Engine  
C++11 | Observer + Composite patterns

## Event Concept

**SkyPulse Airshow & Aviation Expo** is a large-scale aviation event containing nested operational areas:

- **Airside Zone** (flying displays, runway, fire response)
- **Public Zone** (grandstands, admission gates, medical, transport)
- **Expo Zone** (exhibition hangars, vendor stalls)

Each zone contains sectors which in turn contain concrete operational units (leaves).  
A central **EventControl** issues notices (OPEN, CLOSE, WEATHER_ALERT, CAPACITY_ALERT, EVACUATE, …).  
Notices cascade through the Composite tree via the Observer pattern (push model).

### Concrete Leaf Types (≥ 5)

1. `AirDisplayStage` – pauses on weather / evacuation  
2. `Gate` – closes admissions on capacity alert  
3. `FireResponseTeam` – remains operational during alerts  
4. `DroneDisplayUnit` – grounded on weather / pause  
5. `InformationScreen` – updates displayed message  
6. `MedicalPost` – stays open for emergencies  
7. `ShuttleStop` – changes route on evacuation  
8. `VendorStall` – suspends outdoor service on severe weather  

### Composite Nesting (3+ levels)

```
SkyPulse Airshow
├── Airside Zone
│   ├── Runway Sector
│   │   ├── Main Air Display
│   │   ├── Airside Gate
│   │   └── Airside Fire Team
│   └── Drone Sector
│       ├── Drone Swarm Unit
│       └── Drone Info Screen
├── Public Zone
│   ├── Grandstand Sector
│   │   ├── Admission Gate
│   │   ├── Grandstand Medical
│   │   └── Grandstand Screen
│   └── Transport Sector
│       └── Main Shuttle Stop
└── Expo Zone
    └── Exhibition Hangar
        ├── Aero Merchandise
        ├── Food Court Stall
        └── Hangar Display
```

## Build Instructions

```bash
make          # or make all / make compile
make run      # interactive demo
make valgrind # memory-leak check
make clean
```

The executable is named **`eventflow`**.

## Interactive Features

1. Print the Composite tree  
2. Open / close the whole event  
3. Report status (recursive)  
4. Issue any of the 8 notice types from Control (cascading)  
5. Attach / detach observers at runtime  
6. Transfer a unit between groups (ownership + registration update)  
7. Capacity check that triggers a conditional CAPACITY_ALERT (SD3)  
8. Full demonstration sequence  

## Team Contribution (placeholder)

| Member | Main responsibility |
|--------|---------------------|
| Person 1 | |
| Person 2 | |
| Tebogo | |

## License / Academic Use

Submitted for COS 214 Practical 3 – University of Pretoria, 2026.
