#include <Servo.h>

Servo myServo;

int const potPin = A0;
int potVal;
int angle;

void setup() {
  // put your setup code here, to run once:
  //attach to in 9
  myServo.attach(9);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  Serial.println("");
  Serial.print("portval : ");
  Serial.print(potVal);

  // rescale numbers between 0-1023 to 0-179 so it can be between 0-180 degress
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.println("");
  Serial.print("angle : ");
  Serial.print(angle);

  myServo.write(angle);
  delay(15);
}
