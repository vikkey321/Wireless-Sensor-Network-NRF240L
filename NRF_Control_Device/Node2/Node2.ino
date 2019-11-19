#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN

const int button_1 = 2;
const int button_2 = 3;

bool b1 = true;
bool b2 = true;

int buttonState_1 = 0; 
int buttonState_2 = 0; 

String send_command = "";
const byte address[6] = "00001";
void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  pinMode(button_1, INPUT);
  pinMode(button_2, INPUT);

  Serial.begin(9600);
}
void loop() {
 // const char text[] = valueSensor;
 buttonState_1 = digitalRead(button_1);
  buttonState_2 = digitalRead(button_2);
  
int buttonValue = 0;
  if (buttonState_1 == HIGH) {
    Serial.println("b1");
    delay(100); 
    if(b1 == true){
      buttonValue = 1;
      send_command = "B1_ON";
      b1 = false;
    }
    else{
      buttonValue = 2;
       b1 = true;
    }
    Serial.println(buttonValue);
   radio.write(&buttonValue, sizeof(buttonValue));
  } 
  
  if(buttonState_2 == HIGH) {
    // turn LED on:
    
    Serial.println("b2");
    delay(100); 
    if(b2 == true){
      buttonValue = 11;
      b2 = false;
    }
    else{
      buttonValue = 12;
       b2 = true;
    }
    delay(100); 
   radio.write(&buttonValue, sizeof(buttonValue));
  }
  delay(500);
}
