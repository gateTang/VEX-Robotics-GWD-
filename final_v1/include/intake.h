#pragma once
#ifndef guard
#include "vex.h"
#include "motors.h"
#endif

bool intakeState = false;
///////////////////////////////////////////////////////////////
//Intake Mechanism
///////////////////////////////////////////////////////////////
void _intake(bool toggleButton){
  //Intake System Toggle - Button R1
  intakeMotor.setVelocity(100,percent);
  if (toggleButton == true){
      intakeState = !intakeState;
      if (intakeState == true){
        intakeMotor.spin(forward);
      }
      else{
        intakeMotor.stop();
      }
  }
}