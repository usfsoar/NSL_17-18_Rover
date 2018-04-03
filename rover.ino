
#include <SoftwareSerial.h>
//SoftwareSerial xbee(1,0);
String readString;


void setup()
{
  Serial.begin(9600);
  Serial.println("rover is ready");

 
}

void loop() {

  while (Serial.available()) {                     //as long as there is data on incoming serial buffer...


    //Characers are read from the serial buffer and concatinated 
    char c = Serial.read();
    readString += c;
    delay(2);
  }
  
  if(readString ==" rover deployed."){
      Serial.print("Rover is roving..."); 
      }

      else Serial.print(readString);
      readString="";
    
}
