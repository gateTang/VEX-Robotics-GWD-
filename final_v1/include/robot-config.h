using namespace vex;

extern brain Brain;

// VEXcode devices
extern inertial inertial20;
extern controller Controller1;
extern motor intakeMotor;
extern motor wristMotor;
extern motor leftMotor1;
extern motor leftMotor2;
extern motor rightMotor1;
extern motor rightMotor2;
extern motor liftMotor1;
extern motor liftMotor2;
extern pot potSelection;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );