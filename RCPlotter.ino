//Remote Control Parallel SCARA Cursive Plotter
// By Donovan Magryta 
// composed of two SCARA arms
// small arm for control input, and a larger arm for moving a marker which mimics the small arm movement


#include <Servo.h> // pull in Servo library

Servo servoA; // create servo object to control the elbow servo
Servo servoB;  // create servo object to control the shoulder servo
int potpinA = 0;  // A0 analog pin used to connect the elbow potentiometer
int potpinB = 1; // A1 analog pin used to connect the shoulder potentiometer
int valA; // variable to read the value from the first analog pin
int valB; // variable to read the value from the second anaog pin

void setup() {  // setup runs only once on startup
  servoA.attach(9); // attaches the servo on pin D9 to the servo object
  servoB.attach(10); // attached the servo on pin D10 to the servo object
} //signify end of setup section

void loop() { // loop runs over an over again
  valA= analogRead(potpinA);  // reads the value of the elbow potentiometer (value between 0 and 1023)
  valA = map(valA, 0, 1023, 0, 180);  // scale it to use it with the servo (value between 0 and 180)
  servoA.write(valA); // sets the elbow servo position according to the scaled value
  delay(15);  // waits for the servo to get there
  valB = analogRead(potpinB);  // reads the value of the shoulder potentiometer (value between 0 and 1023)
  valB = map(valB, 0, 1023, 0, 180);  // scale it to use it with the servo (value between 0 and 180)
  servoB.write(valB);  // sets the shoulder servo position according to the scaled value
  delay(15);  // waits for the servo to get there
} //signify end of loop section
