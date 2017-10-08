//Remote Control SCARA Cursive Plotter
// By Donovan Magryta 


#include <Servo.h>

Servo servoelbow;  // create servo object to control a servo
Servo servoshoulder;
int potpinelbow = 0;  // analog pin used to connect the potentiometer
int potpinshoulder = 1;
int val1;    // variable to read the value from the analog pin
int val2;
void setup() {
  servoelbow.attach(9);  // attaches the servo on pin 9 to the servo object
  servoshoulder.attach(10);
}

void loop() {
  val1= analogRead(potpinelbow);            // reads the value of the potentiometer (value between 0 and 1023)
  val1 = map(val1, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  servoelbow.write(val1);                  // sets the servo position according to the scaled value
  delay(15); 
  val2 = analogRead(potpinshoulder);            // reads the value of the potentiometer (value between 0 and 1023)
  val2 = map(val2, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  servoshoulder.write(val2);                  // sets the servo position according to the scaled value
  delay(15);
                             // waits for the servo to get there
}