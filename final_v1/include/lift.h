#pragma once
#ifndef guard
#include "vex.h"
#include "motors.h"
#endif

bool liftState = false;

///////////////////////////////////////////////////////////////
//Lift Mechanism
///////////////////////////////////////////////////////////////
void _lift(bool toggleButton){
  //Wrist Mechanism - Button R2
  liftDrive.setMaxTorque(90,percent);
  liftDrive.setTimeout(2,vex::timeUnits::sec); //Check if correct or not?
  //liftDrive.setStopping(brakeType::hold);
  if (toggleButton == true){
    liftState = !liftState;
    if (liftState == true){
      liftDrive.spinToPosition(260, degrees, false); //Set amount of degrees needed.
    }
    else{
      liftDrive.spinToPosition(0, degrees, false);
    }
  }
}