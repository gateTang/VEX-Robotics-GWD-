/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Wen Wen                                          */
/*    Created:      Thu Nov 18 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// inertial20           inertial      20              
// Controller1          controller                    
// intakeMotor          motor         8               
// wristMotor           motor         19              
// leftMotor1           motor         5               
// leftMotor2           motor         6               
// rightMotor1          motor         15              
// rightMotor2          motor         16              
// liftMotor1           motor         7               
// liftMotor2           motor         17              
// potSelection         pot           A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "wait.h"
#include "motors.h"
#include "auton_drivePID.h"
#include "autonomous.h"
#include "inertial.h"
#include "chassisDrive.h"
#include "inertialStraightDrive.h"
#include "intake.h"
#include "wrist.h"
#include "lift.h"
#include "display.h"
#include "self_balancing.h"

using namespace vex;

competition Competition;

double potValue = 0.0;

void pre_auton(void){
  vexcodeInit();
  wristMotor.resetPosition();
  liftDrive.resetPosition();
}

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

    leftMotor1.startRotateFor(reverse, 2700, vex::rotationUnits::deg);
    leftMotor2.startRotateFor(reverse, 2700, vex::rotationUnits::deg);
    rightMotor1.startRotateFor(forward, 2700, vex::rotationUnits::deg);
    rightMotor2.rotateFor(forward, 2700, vex::rotationUnits::deg);

    wristMotor.spinTo(-660, degrees, true);
    
    leftMotor1.setVelocity(100, percent); 
    leftMotor2.setVelocity(100, percent); 
    rightMotor1.setVelocity(100, percent);
    rightMotor2.setVelocity(100, percent);
    leftMotor1.startRotateFor(reverse, 1700, vex::rotationUnits::deg);
    leftMotor2.startRotateFor(reverse, 1700, vex::rotationUnits::deg);
    rightMotor1.startRotateFor(forward, 1700, vex::rotationUnits::deg);
    rightMotor2.rotateFor(forward, 1700, vex::rotationUnits::deg);

    leftMotor1.startRotateFor(forward, 700, vex::rotationUnits::deg);
    leftMotor2.startRotateFor(forward, 700, vex::rotationUnits::deg);
    rightMotor1.startRotateFor(forward, 700, vex::rotationUnits::deg);
    rightMotor2.rotateFor(forward, 700, vex::rotationUnits::deg);

    leftMotor1.startRotateFor(forward, 1550, vex::rotationUnits::deg);
    leftMotor2.startRotateFor(forward, 1550, vex::rotationUnits::deg);
    rightMotor1.startRotateFor(reverse, 1550, vex::rotationUnits::deg);
    rightMotor2.rotateFor(reverse, 1550, vex::rotationUnits::deg); 

    wristMotor.spinTo(-70, degrees, true);
    
    //resetDriveSensors=true;
    //vex::task::sleep(3000);
    
    
    //vex::task::sleep(1000);
}


void usercontrol(void){
  while(1){
    _chassisDrive();
    _intake(Controller1.ButtonR1.pressing());
    _wrist(Controller1.Axis2.position(percent));
    _lift(Controller1.ButtonR2.pressing());
    _selfBalancing(Controller1.ButtonA.pressing());
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  inertialCalibration();
  Competition.autonomous(autonomous);

  pre_auton();

  inertialBalancing(true);

  task displayTaskInstance(displayTask);
  //leftDrive.spin(forward);
  Competition.drivercontrol(usercontrol);
 
}
