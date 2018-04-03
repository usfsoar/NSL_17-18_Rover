//Arduino UNO XBee Code

#include <SoftwareSerial.h>
#define RELAY1 4
#define RELAY2 5

//Global variables, sets up the serial to xbee

int led = 13;
SoftwareSerial xbee(2, 3);
String readString;


void deploy(){     //deployment test
  
  digitalWrite(RELAY2, HIGH);
  delay(1000);  
  digitalWrite(RELAY1, HIGH);
  delay(2200);
  digitalWrite(RELAY2, LOW);
  delay(14800);
  digitalWrite(RELAY1, LOW);
  }

//Setup code for the led, rX and Tx pins, and the xbee module

void setup() { 
  pinMode(led, OUTPUT);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);

  xbee.begin(9600);                              // bit rate
  xbee.println(" Deployment system is listening.");          //setup is done and lets the remote xbee know that it is ready to receive a message
}

//code to run continuously
 
void loop() {
  while (xbee.available()) {                     //as long as there is data on incoming serial buffer...

    //Characers are read from the serial buffer and concatinated 
    char c = xbee.read();
    readString += c;
    delay(2);
  }
  if (readString.length()>0){

      //determines if the received message is a valid deploy command, if so, sends deploy signal
      
      if(readString == "deploy"){
      xbee.print(" deploying rover..."); 
      deploy();
      xbee.print(" rover deployed."); 
      }
      else xbee.print(" Not recognized ");
      readString="";
    }
}
