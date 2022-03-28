byte siirros = 1;
void setup() {
 DDRB = B111111;
 PORTB = B000000;

}

void loop() {
  PORTB = siirros;
  siirros <<=1;
  delay(100);

  if(siirros > 32)
  {
    siirros = 1;
  }
}
