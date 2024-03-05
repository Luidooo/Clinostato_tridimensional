#include <ESP_FlexyStepper.h>

// IO pin assignments
const int MOTOR_STEP_PIN = 26;
const int MOTOR_DIRECTION_PIN = 25;

// create the stepper motor object
ESP_FlexyStepper stepper;

void setup() 
{
  Serial.begin(115200);
  // connect and configure the stepper motor to its IO pins
  stepper.connectToPins(MOTOR_STEP_PIN, MOTOR_DIRECTION_PIN);
}

void loop() 
{

  stepper.setSpeedInStepsPerSecond(1000);
  stepper.setAccelerationInStepsPerSecondPerSecond(500);
  stepper.setDecelerationInStepsPerSecondPerSecond(500);

  // Rotate the motor in the forward direction one revolution (200 steps). 
  // This function call will not return until the motion is complete.
  stepper.moveRelativeInSteps(20000);
  delay(1000);
  // rotate backward 1 rotation, then wait 1 second
  stepper.moveRelativeInSteps(-20000);
  delay(1000);
}
