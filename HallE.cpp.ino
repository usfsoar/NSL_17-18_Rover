
int hallSensorPin = 2;
int state = 0;
int rotation = 0;
bool cont = true;

void setup() {
  Serial.begin(9600);
  pinMode(hallSensorPin, INPUT);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  state = analogRead(hallSensorPin);
 /* Serial.print("State: ");
  Serial.println(state);*/
  
  if(state == LOW && cont == true  ){
    
    rotation++;
  }
  Serial.println(rotation);


}
