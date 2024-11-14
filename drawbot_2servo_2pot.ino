#include <Servo.h>

Servo servoBlue;  // blue servo object created
Servo servoBlack; // black servo object created

int potsilv = A5;  // analog pin 5 used to connect the silver potentiometer
int val;    // variable to read the value from the analog pin
int potblack = A4; // analog pin 4 used to connect the black potentiometer
int val2;

void setup() {
  servoBlack.attach(3);  // attaches the servo on pin 9 to the servo object
  servoBlue.attach(5);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(potsilv);            // reads the value of the silver potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it for use with the black servo (value between 0 and 180)
  servoBlack.write(val);                  // sets the black servo position according to the scaled value
  delay(15);                             // waits for the black servo to get there
  Serial.println("potsilv: ");        //serial monitor print for silv potentiomenter value
  Serial.println(val);                        

  val2 = analogRead(potblack);            // reads the value of the black potentiometer (value between 0 and 1023)
  val2 = map(val2, 0, 1023, 0, 180);      // scale it for use with the blue servo (value between 0 and 180)
  servoBlue.write(val2);                  // sets the blue servo position according to the scaled value
  delay(15);                           // waits for the blue servo to get there
  Serial.println("potblack: ");         // serial print for black potentiometer val
  Serial.println(val2);
}
