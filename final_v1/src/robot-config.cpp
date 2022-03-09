#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
inertial inertial20 = inertial(PORT20);
controller Controller1 = controller(primary);
motor intakeMotor = motor(PORT8, ratio6_1, false);
motor wristMotor = motor(PORT19, ratio18_1, false);
motor leftMotor1 = motor(PORT5, ratio6_1, true);
motor leftMotor2 = motor(PORT6, ratio6_1, true);
motor rightMotor1 = motor(PORT15, ratio6_1, true);
motor rightMotor2 = motor(PORT16, ratio6_1, true);
motor liftMotor1 = motor(PORT7, ratio18_1, false);
motor liftMotor2 = motor(PORT17, ratio18_1, true);
pot potSelection = pot(Brain.ThreeWirePort.A);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}