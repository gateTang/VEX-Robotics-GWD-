#pragma once
#ifndef guard
#include "vex.h"
#endif

///////////////////////////////////////////////////////////////
//Inertial Sensor Calibration Code
///////////////////////////////////////////////////////////////
void inertialCalibration(){
  inertial20.calibrate();
  while (inertial20.isCalibrating()){
    wait (100, msec);
  }
}