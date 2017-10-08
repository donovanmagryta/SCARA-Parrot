//Remote Control SCARA Cursive Plotter
// By Donovan Magryta 
// composed of two scara arms
// small arm for control input, and a larger arm for moving a marker which mimics the small arm movement


#include <Servo.h>

Servo servoelbow;  // create servo object to control the elbow servo
Servo servoshoulder; // create servo object to control the shoulder servo
int potpinelbow = 0;  // analog pin used to connect the elbow potentiometer
int potpinshoulder = 1; // analog pin used to connect the shoulder potentiometer
int val1;    // variable to read the value from the first analog pin
int val2;    // variable to read the value from the second anaog pin
void setup() { // setup runs only once on startup
  servoelbow.attach(9);  // attaches the servo on pin 9 to the servo object
  servoshoulder.attach(10);    // attached the servo on pin 19 to the servo object
}

void loop() {    // loop runs over an over again
  val1= analogRead(potpinelbow);            // reads the value of the elbow potentiometer (value between 0 and 1023)
  val1 = map(val1, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  servoelbow.write(val1);                  // sets the elbow servo position according to the scaled value
  delay(15);  // waits for the servo to get there
  val2 = analogRead(potpinshoulder);            // reads the value of the shoulder potentiometer (value between 0 and 1023)
  val2 = map(val2, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  servoshoulder.write(val2);                  // sets the shoulder servo position according to the scaled value
  delay(15);
                             // waits for the servo to get there
}
