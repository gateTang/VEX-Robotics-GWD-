#pragma once
#ifndef guard
#include "vex.h"
#include "motors.h"
#endif
void inertialBalancing(bool inertialState){
  if (inertialState==true){
    printf("%4.0f\n", inertial20.yaw(degrees));
  }
}