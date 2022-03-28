long randNumber;
const int led = 2;           // the PWM pin the LED is attached to
int brightness = 100;    // how bright the LED is
int fadeAmount = 0; 


void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);

  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));
}

void loop() {
  // print a random number from 0 to 299

  analogWrite(led, brightness);
    brightness = random(10,200);
     //brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
 /* if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }*/
  Serial.println(brightness);

 /* // print a random number from 10 to 19
  randNumber = random(10, 20);
  Serial.println(randNumber);*/

  delay(30);
}
