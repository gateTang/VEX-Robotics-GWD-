#pragma once
#ifndef guard
#include "vex.h"
#include "motors.h"
#endif

///////////////////////////////////////////////////////////////
//Chassis Drive
///////////////////////////////////////////////////////////////
void _chassisDrive(){

    double turnVal = Controller1.Axis3.position(percent);
    double forwardVal = Controller1.Axis4.position(percent);
    
    double turnVolts = turnVal*0.12;
    double forwardVolts = forwardVal*0.12;

    //deadband
    if (fabs(turnVolts) < 1.5) turnVolts = 0;
    if (fabs(forwardVolts) < 1.5) forwardVolts = 0;

    leftDrive.setVelocity((forwardVal + turnVal),percent);
    rightDrive.setVelocity((forwardVal - turnVal),percent);
    
    leftDrive.spin(forward, (forwardVolts + turnVolts), voltageUnits::volt);
    rightDrive.spin(forward, (forwardVolts - turnVolts), voltageUnits::volt);
}