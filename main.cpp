#include "AirDisplayStage.h"
#include "Gate.h"
#include "VendorStall.h"
#include "MedicalPost.h"
#include "ShuttleStop.h"
#include "InformationScreen.h"
#include "DroneDisplayUnit.h"
#include "FireResponseTeam.h"

#include <iostream>

int main()
{
  AirDisplayStage stage(
      "Main Air Display",
      500,
      "10:00");

  Gate gate(
      "Airside Gate",
      300);

  VendorStall vendor(
      "Food Stall",
      40,
      true);

  MedicalPost medical(
      "Main Medical Post",
      50);

  ShuttleStop shuttle(
      "Main Shuttle Stop",
      100,
      "Route A");

  InformationScreen screen(
      "Main Information Screen");

  DroneDisplayUnit drone(
      "Drone Demo Unit",
      200);

  FireResponseTeam fireTeam(
      "Fire Response Team",
      20);

  stage.open();
  gate.open();
  vendor.open();
  medical.open();
  shuttle.open();
  screen.open();
  drone.open();
  fireTeam.open();

  stage.startPerformance();
  gate.startAdmitting();
  vendor.startServing();
  drone.startDemonstration();

  screen.displayMessage(
      "Welcome to SkyPulse Airshow");

  std::cout << "\n--- LEAF STATUS ---\n";

  stage.reportStatus();
  gate.reportStatus();
  vendor.reportStatus();
  medical.reportStatus();
  shuttle.reportStatus();
  screen.reportStatus();
  drone.reportStatus();
  fireTeam.reportStatus();

  return 0;
}