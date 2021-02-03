//Sensor: Resistive Touch Pad
//Output: Vibration Motor

int pot = A1;
int potVal;

int motor = 4;

int petVal;

int timerStart;
int timerCall;
int interval = 10000;

void setup() {
  // put your setup code here, to run once:

  //Serial.begin(9600);
  pinMode(pot, INPUT);
  pinMode(motor, OUTPUT);

  timerStart = millis();

}

void loop() {
  // put your main code here, to run repeatedly:
  timerCall = millis();

  potVal = analogRead(pot);
  //Serial.println(potVal);

  petVal = map (potVal, 0, 1023, 0, 255);

  if (potVal >= 10) {
    analogWrite(motor, petVal);
  }
  else if (timerCall - timerStart > interval) {
      digitalWrite(motor, HIGH); delay(1000);
      digitalWrite(motor, LOW); delay (500);
      digitalWrite(motor, HIGH); delay(1000);
      digitalWrite(motor, LOW); delay (500);
      timerStart = millis();
    } 
  }
