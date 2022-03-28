void setup() {
 DDRB = B111111;

}

void loop() {
  PORTB=B100000;
  delay(100);
  PORTB=B010000;
  delay(100);
  PORTB=B001000;
  delay(100);
  PORTB=B000100;
  delay(100);
  PORTB=B000010;
  delay(100);
  PORTB=B000001;
  delay(100);
  PORTB=B000010;
  delay(100);
  PORTB=B000100;
  delay(300);
  PORTB=B001000;
  delay(100);
  PORTB=B010000;
  delay(100);
}
