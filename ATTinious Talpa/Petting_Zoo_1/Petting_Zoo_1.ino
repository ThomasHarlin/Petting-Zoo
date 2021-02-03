//Sensor: TMP36
//Output: Neopixel Strip

//The ATTinious Tulpa is an animal that prefers to stay hidden. Instead of cloaking itself in the visible light spectrum, it instead it mimics the 
//infrared wavelengths of Electromagnetic Radiation around it.

#include <Adafruit_NeoPixel.h>

//strip for the chameleon's camo
Adafruit_NeoPixel camo = Adafruit_NeoPixel(2, 2);

int tempVal;
int hotVal; //value mapped to temp reading, increases as temp goes up, decreases as it goes down
int coolVal; //inverse of above

//TMP36 Pin Variables
int tempPin = A2; //input pin for the tmp


void setup()
{
  //Serial.begin(9600);


  //prepares the Strip
  camo.begin();
  camo.setBrightness(60);
  camo.clear();
  camo.show();
}

void loop()                     // run over and over again
{
  //gets raw output from tmp
  int raw = analogRead(tempPin);

  // converts raw to voltage, use 3.3 when on coincell battery
  float volts = raw * 3.3;
  volts /= 1024.0;


  //converts the voltage to temp in celcius
  float tempC = (volts - 0.5) * 100 ;


  // converts to Fahrenheit
  float tempF = (tempC * 9.0 / 5.0) + 32.0;
  //Serial.println(tempF);

  Serial.println(raw);
  tempVal =  map(raw, 140, 170, 0, 2);

  if (tempVal == 0) {
    hotVal = 50;
    coolVal = 255;
  }

  if (tempVal == 1) {
    hotVal = 170;
    coolVal = 170;
  }

  if (tempVal == 2) {
    hotVal = 255;
    coolVal = 50;
  }



  for (int i = 0; i < 2; i++) {
    camo.setPixelColor(i, hotVal, 0, coolVal);
    camo.show();
  }
}
