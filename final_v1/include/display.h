#pragma once
#ifndef guard
#include "vex.h"
#include "motors.h"
#include "auton_drivePID.h"
#include "self_balancing.h"
#endif
///////////////////////////////////////////////////////////////
//Brain Display Function
///////////////////////////////////////////////////////////////
int displayTask(){
  while(1){
    Brain.Screen.setCursor(2,1);
    //Brain.Screen.print("  MotorLB     Speed: %4.0f     Position: %6.2f", motorL.velocity(percent), motorL.position(rev));
    //Brain.Screen.print("  MotorRB     Speed: %4.0f     Position: %6.2f", motorR.velocity(percent), motorR.position(rev));
    Brain.Screen.newLine();
    //printf("Pitch Value: %4.0f \n", inertialOrientation);
    /*if (selfBalanceState==true){
      printf("Self Balncing: ON");
    }
    if (selfBalanceState==false){
      printf("Self Balancing: OFF");
    }*/

    printf("%d \n", error);




    /*
    // motor group velocity and position is returned for the first motor in the group
    Brain.Screen.print( "  leftDrive  speed: %4.0f   position: %6.2f", leftDrive.velocity( percent ), leftDrive.position( rev ));
    printf("  leftDrive  speed: %4.0f   position: %6.2f\n", leftDrive.velocity( percent ), leftDrive.position( rev ));
    Brain.Screen.newLine();
    Brain.Screen.print( "  rightDrive speed: %4.0f   position: %6.2f", rightDrive.velocity( percent ), rightDrive.position( rev ));
    printf( "  rightDrive speed: %4.0f   position: %6.2f\n", rightDrive.velocity( percent ), rightDrive.position( rev ));
    Brain.Screen.newLine();
    Brain.Screen.newLine();

    // drivetrain velocity is the average of the motor velocities for left and right
    Brain.Screen.print( "  liftDrive position: %4.0f   liftMotor speed: %4.0f", liftDrive.position(degrees), liftMotor1.velocity(percent) );
    printf( "  liftDrive position: %4.0f   liftDrive speed: %4.0f\n", liftDrive.position(degrees), liftDrive.velocity(percent) );
    Brain.Screen.newLine();

    Brain.Screen.print("  Inertial Angle:   %4.0f   wristMotor speed:%4.0f", inertial20.rotation(degrees), wristMotor.velocity(percent));
    printf("  Inertial Angle:   %4.0f   wristMotor state:%4.0f\n", inertial20.rotation(degrees), wristMotor.velocity(percent));
    printf("\n");
    Brain.Screen.newLine();

    Brain.Screen.print( "  kP value: %4.0f", wristkP );
    printf( "  kP value: %4.0f\n", wristkP );
    printf( "  graduates with deficiency");
    Brain.Screen.newLine();

    printf("----------------------------------------------------------------------\n");
    */

    // no need to run this loop too quickly
    wait( 3000, timeUnits::msec );
  }
  return 0;
}