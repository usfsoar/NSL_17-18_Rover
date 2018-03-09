//Arduino UNO XBee Code

#include <SoftwareSerial.h>

//Global variables, sets up the serial to xbee

int led = 13;
SoftwareSerial xbee(2, 3);
String readString;

//Setup code for the led, rX and Tx pins, and the xbee module

void setup() { 
  pinMode(led, OUTPUT);
  pinMode(0, INPUT);                             //RX
  pinMode(1, OUTPUT);                            //TX
  xbee.begin(9600);                              //default bit rate is 9600
  xbee.println(" Rover is listening.");          //setup is done and lets the remote xbee know that it is ready to receive a message
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
      
      if(readString == "deploy")
      xbee.print(" deploying rover...");         //code will be added here to send a signal to deployment mechanism
      else xbee.print(" Not recognized ");
      readString="";
    }
}
