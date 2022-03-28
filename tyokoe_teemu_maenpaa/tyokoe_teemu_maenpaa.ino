const byte ledPin[] = {7,8,9,10,11,12,13};
long randNumber;
byte i = 0;
const int buttonPin = 2;
int buttonState = 0;   

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(0));
  pinMode(buttonPin, INPUT);
  for (i=0; i<7; i++)
     pinMode(ledPin[i],OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    number();
    delay(1000);
    }
    else{
      for (i=0; i<7;i++)
  
       digitalWrite(ledPin[i], LOW);
    }
}
void number()
 {    
 randNumber = random(1,7);
   
 /* for (i=0; i<7;i++)
  
       digitalWrite(ledPin[i], HIGH);*/
Serial.println(randNumber);

switch(randNumber)
{
  
  case 1:
    digitalWrite(ledPin[1],HIGH);
    digitalWrite(ledPin[2],HIGH);
    break;
    
  case 2:
    digitalWrite(ledPin[0],HIGH);
    digitalWrite(ledPin[1],HIGH);
    digitalWrite(ledPin[4],HIGH);
    digitalWrite(ledPin[6],HIGH);
    digitalWrite(ledPin[3],HIGH);
    break;
  
  case 3:
    digitalWrite(ledPin[0],HIGH);
    digitalWrite(ledPin[1],HIGH);
    digitalWrite(ledPin[2],HIGH);
    digitalWrite(ledPin[3],HIGH);
    digitalWrite(ledPin[6],HIGH);
    break;

  case 4:
    digitalWrite(ledPin[1],HIGH);
    digitalWrite(ledPin[2],HIGH);
    digitalWrite(ledPin[5],HIGH);
    digitalWrite(ledPin[6],HIGH);
    break;

  case 5:
    digitalWrite(ledPin[0],HIGH);
    digitalWrite(ledPin[2],HIGH);
    digitalWrite(ledPin[3],HIGH);
    digitalWrite(ledPin[5],HIGH);
    digitalWrite(ledPin[6],HIGH);
    break;

  case 6:
    digitalWrite(ledPin[0],HIGH);
    digitalWrite(ledPin[2],HIGH);
    digitalWrite(ledPin[3],HIGH);
    digitalWrite(ledPin[4],HIGH);
    digitalWrite(ledPin[5],HIGH);
    digitalWrite(ledPin[6],HIGH);
    break;
}

   
}
