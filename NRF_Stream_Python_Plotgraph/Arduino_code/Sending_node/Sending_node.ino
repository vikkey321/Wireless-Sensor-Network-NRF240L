#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  Serial.begin(9600);
}
void loop() {
  int sensorValue = analogRead(A7);
  String valueSensor = String(sensorValue);
 // const char text[] = valueSensor;
 Serial.println(valueSensor);
 Serial.println(sensorValue);
  Serial.println(radio.write(&sensorValue, sizeof(sensorValue)));
  delay(5000);
}
