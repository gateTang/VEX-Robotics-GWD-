/*#pragma once
#ifndef guard
#include "vex.h"
#include "motors.h"
#include "map.h"
#endif
void autonomous(void){
    wristMotor.setVelocity(80,percent);
    wristMotor.spinTo(-660, degrees);
    //vex::task autoDrive(drivePID);
    //resetDriveSensors = true;
    int straightDrive = 4100;
    leftMotor1.setVelocity(90, percent); 
    leftMotor2.setVelocity(90, percent); 
    rightMotor1.setVelocity(90, percent);
    rightMotor2.setVelocity(90, percent);
    leftMotor1.startRotateFor(forward, straightDrive, vex::rotationUnits::deg);
    leftMotor2.startRotateFor(forward, straightDrive, vex::rotationUnits::deg);
    rightMotor1.startRotateFor(reverse, straightDrive, vex::rotationUnits::deg);
    rightMotor2.rotateFor(reverse, straightDrive, vex::rotationUnits::deg);
    //desiredValue = 50; //In degrees
    //desiredTurnValue = 0;

    wristMotor.spinTo(-70, degrees);

    leftMotor1.startRotateFor(reverse, straightDrive, vex::rotationUnits::deg);
    leftMotor2.startRotateFor(reverse, straightDrive, vex::rotationUnits::deg);
    rightMotor1.startRotateFor(forward, straightDrive, vex::rotationUnits::deg);
    rightMotor2.rotateFor(forward, straightDrive, vex::rotationUnits::deg);

    wristMotor.spinTo(-660, degrees);
    
    leftMotor1.setVelocity(100, percent); 
    leftMotor2.setVelocity(100, percent); 
    rightMotor1.setVelocity(100, percent);
    rightMotor2.setVelocity(100, percent);
    leftMotor1.startRotateFor(reverse, 50, vex::rotationUnits::deg);
    leftMotor2.startRotateFor(reverse, 50, vex::rotationUnits::deg);
    rightMotor1.startRotateFor(forward, 50, vex::rotationUnits::deg);
    rightMotor2.rotateFor(forward, 50, vex::rotationUnits::deg);
    //resetDriveSensors=true;
    //vex::task::sleep(3000);
    
    
    //vex::task::sleep(1000);
}*/