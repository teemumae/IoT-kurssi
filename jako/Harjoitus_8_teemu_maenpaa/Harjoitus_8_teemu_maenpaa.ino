void setup() {
 DDRB = B111111;

}

void loop() {
  PORTB = B010101;
  delay(1000);
  PORTB=B101010;
  delay(1000);
}
