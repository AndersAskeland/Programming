// Constant for PWM and analog
const int greenLEDPin = 10;
const int redLEDPin = 11;
const int blueLEDPin = 9;


void setup() {
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop() {
  analogWrite(redLEDPin, 140);
  analogWrite(greenLEDPin, 0);
  analogWrite(blueLEDPin, 50);
}
