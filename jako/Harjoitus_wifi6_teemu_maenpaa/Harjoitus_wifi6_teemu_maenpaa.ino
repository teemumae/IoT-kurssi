#include <math.h>
 
const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k
const int pinTempSensor = A0;     // Grove - Temperature Sensor connect to A0
 
#if defined(ARDUINO_ARCH_AVR)
#define debug  Serial
#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
#define debug  SerialUSB
#else
#define debug  Serial
#endif
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

void setup()
{
     lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    Serial.begin(9600);
}
 
void loop()
{
    int a = analogRead(pinTempSensor);
     lcd.setCursor(0, 1);
    float R = 1023.0/a-1.0;
    R = R0*R;
 
    float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet
 
    Serial.print("temperature: ");
    Serial.println(temperature);
    lcd.print("temp: ");
    lcd.print(temperature);
     lcd.print(" C");
    delay(100);
}
