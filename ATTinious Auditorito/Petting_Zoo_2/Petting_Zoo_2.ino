//Sensor: Capacitive Touch
//Output: Piezo

#include <CapacitiveSensor.h>
CapacitiveSensor   cs_4_2 = CapacitiveSensor(0, 1);

int buzz = 2;

int buzzTone = 500;
//pinMode (buzz, OUTPUT);


int timeStart;
int countStart;

int timeEnd;

int interval = 15000;
int otherInt = 20;

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);

  timeStart = millis();
  countStart = millis();


}

void loop() {
  // put your main code here, to run repeatedly:
  long touch =  cs_4_2.capacitiveSensor(30);
  //Serial.println(touch);                  // print sensor output 1
  timeEnd = millis();

  if (touch > 50) {
    tone(buzz, buzzTone); delay (20);

    if(timeEnd - countStart >= otherInt){
      buzzTone += 20;
      countStart = millis();
    }
    if(buzzTone> 1000){
      buzzTone=500;
    }
  }
  else {
    if (timeEnd - timeStart >= interval) {
      buzzTone = 500;
      noTone(buzz);
      tone (buzz, 180); delay (250);
      tone (buzz, 220); delay (60);
      noTone(buzz); delay (300);
      tone (buzz, 180); delay (250);
      tone (buzz, 220); delay (60);
      noTone(buzz);
      timeStart = millis();
    }
  }


}
