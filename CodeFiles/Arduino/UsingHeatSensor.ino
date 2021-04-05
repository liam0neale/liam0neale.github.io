const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // open serial port

  for(int pinNumber = 2; pinNumber<5; pinNumber++)
  {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  // Convert ADC reading to volts
  float voltage = (sensorVal / 1024.0) * 5.0;
  Serial.print("Voltage: ");
  Serial.print(voltage);

  Serial.print("Degrees : ");
  float temp = (voltage - 0.5) * 100;
  Serial.println(temp);

  if(temp < baselineTemp + 1)
  {
    Serial.print("NONE ON");
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(2, LOW);
  }
  else if(temp >= baselineTemp + 1 && temp < baselineTemp + 3)
  {
    Serial.print("ONE ON");
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(2, LOW);
  }
  else if(temp >= baselineTemp + 3 && temp < baselineTemp + 5)
  {
    Serial.print("TWO ON");
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(2, LOW);
  }
  else if(temp >= baselineTemp + 5 && temp < baselineTemp + 7)
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(2, HIGH);
  }
  else
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(2, HIGH);

    delay(250);

    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(2, LOW);

    delay(250);
  }

  delay(1);
}
