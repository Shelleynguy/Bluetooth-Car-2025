#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

// Right motor direction pins
int rightMotorPin1 = 7;
int rightMotorPin2 = 8;

// Left motor direction pins
int leftMotorPin1 = 9;
int leftMotorPin2 = 10;

void setup()
{
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  stopMotors();

  Dabble.begin(9600, 2, 3);  // RX = 2, TX = 3
}

void loop()
{
  Dabble.processInput();

  if (GamePad.isUpPressed())
  {
    moveForward();
  }
  else if (GamePad.isDownPressed())
  {
    moveBackward();
  }
  else if (GamePad.isLeftPressed())
  {
    turnLeft();
  }
  else if (GamePad.isRightPressed())
  {
    turnRight();
  }
  else
  {
    stopMotors();
  }
}

// function to move forward
void moveForward()
{
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);

  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
}

// function to move backward
void moveBackward()
{
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, HIGH);

  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, HIGH);
}

// function to turn left
void turnLeft()
{
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);

  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);  // left motor off
}

// function to turn right
void turnRight()
{
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);  // right motor off

  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
}

// stop both motors
void stopMotors()
{
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);

  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);
}
}
"}
