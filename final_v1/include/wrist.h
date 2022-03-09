#pragma once
#ifndef guard
#include "vex.h"
#include "motors.h"
#include "map.h"
#endif

///////////////////////////////////////////////////////////////
//Wrist Mechanism
///////////////////////////////////////////////////////////////
void _wrist(double controllerPercent){
  //Lift Mechanism
  //vex::task wristDrive(wristPID); //Check if work or not.
  double wristVal = controllerPercent;
  double wristPos = map(wristVal, -100, 0, -630, -120); //Enter amount of min and max degrees needed. 

  //enableWristPID = true;
  //wristDesiredValue = wristPos; 
  wristMotor.spinTo(wristPos,degrees, false); //Uncomment if previous way is wrong.
  wristMotor.setStopping(brakeType::hold);
  //wristMotor.setTimeout(2, timeUnits::sec);
}