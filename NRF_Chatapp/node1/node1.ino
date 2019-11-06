
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address_read[6] = "00002";
const byte address_write[6] = "00001";

String message;
char inByte;
String text;

void setup() {
  Serial.begin(9600);
  radio.begin();
    
    radio.openWritingPipe(address_write);

  radio.openReadingPipe(1, address_read);
  
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {

  if (radio.available()) {
    //Serial.println("Receiving some data..!");
    char text;
    radio.read(&text, sizeof(text));
   // Serial.println(text);
    message = message + text;
    if(text == 13){
      Serial.println("Beta: " + message);
      message = "";
    }
  }

  if (Serial.available() > 0) {
    radio.stopListening();
    radio.openWritingPipe(address_write);
    inByte = Serial.read();
    text = text + inByte;
    radio.write(&inByte, sizeof(inByte));
    //delay(100);
    if(inByte == 13){
      Serial.println("Alpha: " +text);
      text = "";
    }
  }
   radio.openReadingPipe(1, address_read);
   radio.startListening();
}
