#pragma once
#ifndef guard
#include "vex.h"
#include "motors.h"
#include "signum_c.h"
#endif

//Settings
double kP = 0.05; //#1 around 0.1 - set integral and derivative to 0, then slowly increase kP. https://www.thorlabs.com/newgrouppage9.cfm?objectgroup_id=9013#:~:text=To%20tune%20your%20PID%20controller,to%20roughly%20half%20this%20value. 
double kI = 0.0; //Avoid using.
double kD = 0.0; //#2
double turnkP = 0.0;
double turnkI = 0.0;
double turnkD = 0.0;
int maxTurnIntegral = 300; // These cap the integrals
int maxIntegral = 300;
int integralBound = 3; //If error is outside the bounds, then apply the integral. This is a buffer with +-integralBound degrees

//Autonomous PID Settings
int desiredValue = 0;
int desiredTurnValue = 0;

int error; //SensorValue - DesiredValue : Position
int prevError = 0; //Position 20 miliseconds ago
int derivative; // error - prevError : Speed
int totalError = 0; //totalError = totalError + error

int turnError; //SensorValue - DesiredValue : Position
int turnPrevError = 0; //Position 20 miliseconds ago
int turnDerivative; // error - prevError : Speed
int turnTotalError = 0; //totalError = totalError + error

bool resetDriveSensors = false;

//Variables modified for use
bool enableDrivePID = true;

int drivePID(){
  
  while(enableDrivePID){

    if (resetDriveSensors) {
      resetDriveSensors = false;
      leftDrive.setPosition(0, degrees);
      rightDrive.setPosition(0,degrees);
    }


    //Get the position of both motors
    int leftMotorPosition = leftDrive.position(degrees);
    int rightMotorPosition = rightDrive.position(degrees);

    int topLeftMotorPosition = leftMotor2.position(degrees);
    int bottomLeftMotorPosition = leftMotor1.position(degrees);
    int topRightMotorPosition = rightMotor2.position(degrees);
    int bottomRightMotorPosition = rightMotor1.position(degrees);
    ///////////////////////////////////////////
    //Lateral movement PID
    /////////////////////////////////////////////////////////////////////
    //Get average of the two motors
    int averagePosition = (topLeftMotorPosition + bottomLeftMotorPosition + topRightMotorPosition + bottomRightMotorPosition)/4;
    //int averagePosition = (leftMotorPosition + rightMotorPosition)/2;

    //Potential
    error = averagePosition - desiredValue;

    //Derivative
    derivative = error - prevError;

    //Integral
    if(abs(error) < integralBound){
    totalError+=error; 
    }  else {
    totalError = 0; 
    }
    //totalError += error;

    //This would cap the integral
    totalError = abs(totalError) > maxIntegral ? signnum_c(totalError) * maxIntegral : totalError;

    double lateralMotorPower = error * kP + derivative * kD;
    /////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////
    //Turning movement PID
    /////////////////////////////////////////////////////////////////////
    //Get average of the two motors
    int turnDifference = leftMotorPosition - rightMotorPosition;

    //Potential
    turnError = turnDifference - desiredTurnValue;

    //Derivative
    turnDerivative = turnError - turnPrevError;

    //Integral
    /*if(abs(error) < integralBound){
    turnTotalError+=turnError; 
    }  else {
    turnTotalError = 0; 
    }*/
    turnTotalError += turnError;

    //This would cap the integral
    //turnTotalError = abs(turnTotalError) > maxIntegral ? signnum_c(turnTotalError) * maxIntegral : turnTotalError;

    double turnMotorPower = turnError * turnkP + turnDerivative * turnkD; //+ turnTotalError * turnkI;
    /////////////////////////////////////////////////////////////////////
    leftDrive.setTimeout(2,vex::timeUnits::sec);
    rightDrive.setTimeout(2, vex::timeUnits::sec); //Check if the setTimeout works or not?
    leftDrive.spin(reverse, lateralMotorPower + turnMotorPower, voltageUnits::volt);
    rightDrive.spin(forward, lateralMotorPower - turnMotorPower, voltageUnits::volt);


    prevError = error;
    turnPrevError = turnError;
    vex::task::sleep(20);

  }
  return 1;
}