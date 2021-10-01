// Constants
const int sensorPin = A0;
const float baselineLight = 250;

void setup() {
  // Open serial
  Serial.begin(9600); // Open serial port

  // Loop to set pinmode and settings
  for (int pinNumber = 2; pinNumber < 5; pinNumber++)
  {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
 
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value:");
  Serial.print(sensorVal);
  Serial.print("\n");

  // Check if increased light
  if (sensorVal > baselineLight)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);

  }
  else if (sensorVal > (baselineLight - 50))
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (sensorVal > (baselineLight - 100))
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else
    {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
}
