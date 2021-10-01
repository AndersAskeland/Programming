// Constant for PWM and analog
const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin = 10;

const int redSensorPin = A0;
const int greenSensorPin = A1;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int *blueSensorValue = &greenSensorValue;

void setup() {
  // Start serial communiation to 9600 pbs
  Serial.begin(9600); // Set serial mode

  // Set pin modes
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}



void loop() {
  redSensorValue = analogRead(redSensorPin);
  // Delay as adc takes some time.
  delay(5); 
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);

  // Debug prints
  Serial.print("Actual value \t Red: ");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.println(blueValue);

  // Set values - divided by 4 as analog is between 0 - 1023
  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = *blueSensorValue/4;

  // Debug prints
  Serial.print("Raw Value \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\t Green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue: ");
  Serial.println(*blueSensorValue);

  // Write new value/duty cycle
  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
  
}
