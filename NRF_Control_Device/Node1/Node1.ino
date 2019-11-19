#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";
const int led_1 =  2; 
const int led_2 =  3; 

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    Serial.println("Receiving some data");
    int buttonValue = 0;;
    radio.read(&buttonValue, sizeof(buttonValue));
    Serial.println(buttonValue);
    if(buttonValue == 1){
      digitalWrite(led_1, HIGH);
      
    }else if(buttonValue == 2){
          digitalWrite(led_1, LOW);

      }else if(buttonValue == 11){
     digitalWrite(led_2, HIGH);
    }else if(buttonValue == 12){
                digitalWrite(led_2, LOW);

      
      }
  }
}
