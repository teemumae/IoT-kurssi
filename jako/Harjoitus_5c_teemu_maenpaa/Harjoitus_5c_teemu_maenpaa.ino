/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/
const int buttonPin = 7;
int buttonState = 0;
int led = 5;           // the PWM pin the LED is attached to
//int led2 = 4;
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
 // pinMode(led2, OUTPUT);
 pinMode(buttonPin, INPUT);
 Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  buttonState = digitalRead(buttonPin);
   if (buttonState == HIGH) {
  // set the brightness of pin 9:
    
    analogWrite(led, brightness);
 // analogWrite(led2, brightness);

  // change the brightness for next time through the loop:
     brightness = brightness + fadeAmount;}
    else{
  // reverse the direction of the fading at the ends of the fade:
      if (brightness <= 0 || brightness >= 255) {
       fadeAmount = -fadeAmount;
  }}
  // wait for 30 milliseconds to see the dimming effect
  
  // print out the value you read:
  Serial.println(brightness);
  delay(30);
}
