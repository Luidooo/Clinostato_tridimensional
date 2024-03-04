#include <FlexyStepper.h>

// Define stepper motor pins
const int motor1_step_pin = 2;
const int motor1_direction_pin = 4;
const int motor2_step_pin = 15;
const int motor2_direction_pin = 16;
const int motor3_step_pin = 17;
const int motor3_direction_pin = 5;

FlexyStepper motor1;
FlexyStepper motor2;
FlexyStepper motor3;

void setup() {
  // Set up serial monitor
  Serial.begin(115200);

  // Set up stepper motor pins
  motor1.connectToPins(motor1_step_pin, motor1_direction_pin);
  motor2.connectToPins(motor2_step_pin, motor2_direction_pin);
  motor3.connectToPins(motor3_step_pin, motor3_direction_pin);

  // Set stepper motor speed and acceleration
  motor1.setSpeedInStepsPerSecond(100); // Adjust as needed
  motor1.setAccelerationInStepsPerSecondPerSecond(500); // Adjust as needed

  motor2.setSpeedInStepsPerSecond(100); // Adjust as needed
  motor2.setAccelerationInStepsPerSecondPerSecond(500); // Adjust as needed

  motor3.setSpeedInStepsPerSecond(100); // Adjust as needed
  motor3.setAccelerationInStepsPerSecondPerSecond(500); // Adjust as needed
}

void loop() {
  // Move motor 1 1000 steps forward
  Serial.println("Moving motor 1 forward");
  motor1.moveToPositionInSteps(1000);
  motor1.run();

  delay(1000);

  // Move motor 2 1000 steps forward
  Serial.println("Moving motor 2 forward");
  motor2.moveToPositionInSteps(1000);
  motor2.run();

  delay(1000);

  // Move motor 3 1000 steps forward
  Serial.println("Moving motor 3 forward");
  motor3.moveToPositionInSteps(1000);
  motor3.run();

  delay(1000);

  // Move all motors back to starting position
  Serial.println("Moving all motors back to starting position");
  motor1.moveToHomeInSteps();
  motor1.run();
  motor2.moveToHomeInSteps();
  motor2.run();
  motor3.moveToHomeInSteps();
  motor3.run();

  delay(1000);
}
}
