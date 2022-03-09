#pragma once
#ifndef guard
#include "vex.h"
#endif

motor_group leftDrive(leftMotor1,leftMotor2);
motor_group rightDrive(rightMotor1, rightMotor2);
motor_group liftDrive(liftMotor1, liftMotor2);
smartdrive robotDrive(leftDrive, rightDrive, inertial20, 12.56, 16, 16, distanceUnits::in);