/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
   Serial.begin(9600);
   Serial.println("Servo Sweep Test!");
   myservo.attach(8);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  
  for (pos = 0; pos <= 171; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Serial.println("Pos: ");
    Serial.println(pos);
    myservo.write(pos); // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  delay(500);
  for (pos = 172; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    Serial.println("Pos: ");
    Serial.println(pos);
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    delay(500);
}
