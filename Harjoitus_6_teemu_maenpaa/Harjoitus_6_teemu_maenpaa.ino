/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/
const byte ledPin[] = {7,8,9,10,11,12,13}; // käytössä olevat pinnit
//const byte ledPin[] = {1,2,4,5,6,7,9,10}; // käytössä olevat pinnit

byte i = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
   for (i=0; i<7; i++)
     pinMode(ledPin[i],OUTPUT);
 // pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
for (i=0; i<7;i++)
  if (ledPin[i]==11 || ledPin[i]==8){
       digitalWrite(ledPin[i], LOW);
       }
        else{
        digitalWrite(ledPin[i], HIGH);}
  delay(500);            
  }
  
                   // wait for a second
//  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//  delay(1000);                       // wait for a second
