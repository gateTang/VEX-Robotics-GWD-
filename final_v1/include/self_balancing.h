#pragma once
#ifndef guard
#include "vex.h"
#include "motors.h"
#endif

bool selfBalanceState = false;
double inertialOrientation = inertial20.orientation(pitch, degrees);

void _selfBalancing (bool buttonInput){
  if(buttonInput==true){
    if(inertialOrientation<-3 && inertialOrientation ==3){
      leftDrive.spin(reverse);
      rightDrive.spin(forward);
    }
    if (inertialOrientation<2 && inertialOrientation>-2){
      leftDrive.stop();
      rightDrive.stop();
    }
    if (inertialOrientation>3 && inertialOrientation==3){
      leftDrive.spin(forward);
      rightDrive.spin(reverse);
    }
  }
  if (Controller1.ButtonY.pressing()){
    selfBalanceState = false;
  }  
}