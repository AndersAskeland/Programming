// Include servo library
#include <Servo.h>


// Create servo object
Servo myServo;

// Constants
int const potPin = A0; // Potentiomiter

// Variables
int potVal;
int angle;



void setup() {
  // ATtach servo to digital output
  myServo.attach(9);

  // Begin analog stuff
  Serial.begin(9600);
}

void loop() {
  // Read and print potentiomiter position
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);

  // Change analog input (0 - 1023) to angle on servo (0 - 179) using the map function.
  angle = map(potVal, 0, 1023, 0, 179);

  Serial.print(", angle: ");
  Serial.println(angle);

  // Rotate servo
  myServo.write(angle);
  delay(15);
    
}
