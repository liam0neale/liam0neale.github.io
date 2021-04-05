int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  Serial.begin(9600);

  while(millis() < 5000)
  {
    sensorValue = analogRead(A0);
    if(sensorValue > sensorHigh)
    {
      sensorHigh = sensorValue;
    }
    if(sensorValue < sensorLow)
    {
      sensorLow = sensorValue;
    }
  }

  digitalWrite(ledPin,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(A0);
  Serial.println("");
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  Serial.println("");
  Serial.print("pitch : ");
  Serial.print(pitch);
  tone(8, pitch, 20);
  delay(10);

}