void rove(){

  digitalWrite(23, HIGH);
  digitalWrite(22, LOW);
  analogWrite(8, 255);
  
  digitalWrite(24, LOW);
  digitalWrite(25, HIGH);
  analogWrite(9, 255);

  delay(4000);
   digitalWrite(23, LOW);
  digitalWrite(22, LOW);

  
  digitalWrite(24, LOW);
  digitalWrite(25, LOW);
  return;
  }



void setup() {

  pinMode(8, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);

  pinMode(9, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
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

      rove();

      Serial.print( "Hope its 5 feet");
      return;
-*      
      }

      else Serial.print(readString);
      readString="";
    
}
