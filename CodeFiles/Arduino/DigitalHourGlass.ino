const int switchPin = 8;

unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState = 0;
int led = 2;
long interval = 1000;
bool isFlashing = false;

void setup() {
  // put your setup code here, to run once:
  for(int x=2;x<8;x++)
  {
    pinMode(x, OUTPUT);
  }

  Serial.begin(9600);
  
  pinMode(switchPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();
  if(!isFlashing)
  {
    if(currentTime - previousTime > interval)
    {
      Serial.println("ONE HIGH");
      previousTime = currentTime;
  
      digitalWrite(led, HIGH);
      led++;
    
      if(led == 9)
      {
        isFlashing = true;
      }
    }
  }
  else
  {
    flashAllLEDs();
  }

   switchState = digitalRead(switchPin);
  
    if(switchState != prevSwitchState)
    {
      Serial.println("ALL LOW");
      for(int x=2;x<8;x++)
      {
        digitalWrite(x, LOW);  
      }
      led = 2;
      previousTime = currentTime;
      isFlashing = false;
    }
  
    prevSwitchState = switchState;
}

void flashAllLEDs()
{
  for(int x=2;x<8;x++)
  {
    digitalWrite(x, LOW);  
  }
  delay(200);
  for(int x=2;x<8;x++)
  {
    digitalWrite(x, HIGH);  
  }
  delay(200);
}
