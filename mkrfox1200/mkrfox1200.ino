#include <ArduinoLowPower.h>
#include <SigFox.h>
#include <DHT.h>;
#include "conversions.h"

// Set oneshot to false to trigger continuous mode when you finisched setting up the whole flow
int oneshot = true;

#define DHTPIN 6     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

int sensorPin1 = A0; 
const int trigPin = 1;
const int echoPin = 2;
int temperature = A1;
const int trigPin1 = 3;
const int echoPin1 = 4;
int sensor=5;
int gas_value;
long duration;
int distance;
int temperatureS;
long duration1;
int distance1;
float hum;


typedef struct __attribute__ ((packed)) sigfox_message {
  uint8_t status;
  int16_t data1;
  int16_t data2;
  int16_t data3;
  int16_t data4;
  int16_t data5;
  int16_t data6;
  int16_t data7;
  uint8_t lastMessageStatus;
} SigfoxMessage;

// stub for message which will be sent
SigfoxMessage msg;

void setup() {

  if (oneshot == true) {
    // Wait for the serial
    Serial.begin(115200);
    while (!Serial) {}
  }

  if (!SigFox.begin()) {
    // Something is really wrong, try rebooting
    // Reboot is useful if we are powering the board using an unreliable power source
    // (eg. solar panels or other energy harvesting methods)
    reboot();
  }

  //Send module to standby until we need to send a message
  SigFox.end();

  if (oneshot == true) {
    // Enable debug prints and LED indication if we are testing
    SigFox.debug();
  }

  dht.begin();
  pinMode(sensorPin1,INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(temperature, INPUT);
  pinMode(trigPin1, OUTPUT); 
  pinMode(echoPin1, INPUT); 
  pinMode(sensor,INPUT);
 
}

void loop() {
  // Every 15 minutes, read all the sensors and send them
  // Let's try to optimize the data format
  // Only use floats as intermediate representaion, don't send them directly

  //Soil Moisture (Make it more for same another sensor)
  float sensorData1 = analogRead(sensorPin1); 
  msg.data1 = convertoFloatToUInt16(sensorData1, 200000);

  //Parking Status (Make it more for same another sensor)
  int statusP;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  // set value
  if(distance < 10)
  {
    //Parking slot is not empty
    statusP = 1;
    msg.data2 = convertoFloatToUInt16(statusP, 2000);
  }
  else
  {
    //Parking slot is empty
    statusP = 0;
    msg.data2 = convertoFloatToUInt16(statusP, 2000);
  }

  //HVAC Monitor (Make it more for same another sensor)
  temperatureS = analogRead(temperature);
  float mv1 = ( temperatureS/1024.0)*5000;
  float cel1 = mv1/10;
  float farh1 = (cel1*9)/5 + 32;
  msg.data3 = convertoFloatToUInt16(cel1, 2000);
  msg.data4 = convertoFloatToUInt16(farh1, 2000);

  //Water level of tank (Make it more for same another sensor)
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance1);
  // set value
  if(distance1 < 1000)
  {
    msg.data5 = convertoFloatToUInt16(distance1, 2000);
    Serial.println(distance1);
  }

  //Fire Detection (Make it more for same another sensor)
  gas_value=digitalRead(sensor);
  if(gas_value == 0)
  {
    //Gas detect
    msg.data6 = convertoFloatToUInt16(gas_value, 2000);
    Serial.println("Gas Leakage");
  }

  //Humidity (Make it more for same another sensor)
  hum = dht.readHumidity();
  msg.data7 = convertoFloatToUInt16(hum, 2000);

  
  // Start the module
  SigFox.begin();
  // Wait at least 30ms after first configuration (100ms before)
  delay(100);

  // Clears all pending interrupts
  SigFox.status();
  delay(1);

  SigFox.beginPacket();
  SigFox.write((uint8_t*)&msg, 12);

  msg.lastMessageStatus = SigFox.endPacket();

  if (oneshot == true) {
    Serial.println("Status: " + String(msg.lastMessageStatus));
  }

  SigFox.end();

  if (oneshot == true) {
    // spin forever, so we can test that the backend is behaving correctly
    while (1) {}
  }

  //Sleep for 15 minutes
  LowPower.sleep(15 * 60 * 1000);
}

void reboot() {
  NVIC_SystemReset();
  while (1);
}