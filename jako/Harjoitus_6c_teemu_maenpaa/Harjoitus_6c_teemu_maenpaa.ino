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
const byte interruptPin = 0;
volatile byte output = LOW;
//const byte ledPin[] = {1,2,4,5,6,7,9,10}; // käytössä olevat pinnit

byte i = 0;

  
// the setup function runs once when you press reset or power the board
void setup() {
   pinMode(interruptPin, INPUT_PULLUP);
  // initialize digital pin LED_BUILTIN as an output.
   for (i=0; i<7; i++)
     pinMode(ledPin[i],OUTPUT);
 // pinMode(LED_BUILTIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), buttonPressed, CHANGE);
}

// the loop function runs over and over again forever
void loop() {
/*for (i=0; i<7;i++)
        //delay(500); 
        digitalWre(ledPin[i], HIGH);*/
       
        
        digitalWrite(ledPin[1], HIGH);
        delay(100);
        digitalWrite(ledPin[1], LOW);
       
        digitalWrite(ledPin[2], HIGH);
        delay(100); 
        digitalWrite(ledPin[2], LOW);

        digitalWrite(ledPin[3], HIGH);
        delay(100);
        digitalWrite(ledPin[3], LOW);

        digitalWrite(ledPin[6], HIGH);
        delay(100);
        digitalWrite(ledPin[6], LOW);   
        
        digitalWrite(ledPin[5], HIGH);
        delay(100);
        digitalWrite(ledPin[5], LOW);
  
        
        
        digitalWrite(ledPin[4], HIGH);
        delay(100);
        digitalWrite(ledPin[4], LOW);
        Serial.println(output);
        /*digitalWrite(ledPin[0], HIGH);
        delay(1000);
        digitalWrite(ledPin[0], LOW);*/
        
       
        
        
        
        
     
       // delay(100);                                                                     
  }
void buttonPressed()
{
  Serial.println("Keskeytysfunktio käynnistyi");
  output= !output;
  if (output==HIGH)
  {
    Serial.println("Outputin tila on HIGH");
  }
  if (output == LOW)
  {
    Serial.println("Outputin tila on LOW");
  }
}  
                   // wait for a second
//  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//  delay(1000);                       // wait for a second
