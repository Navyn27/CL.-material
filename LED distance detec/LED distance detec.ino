const int trigPin = 6;
const int echoPin = 5;

const int greenLED = 7;
const int redLED = 12;
const int blueLED = 13;

long duration, distance;

void setup(){
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(greenLED,OUTPUT);
  pinMode(redLED,OUTPUT);
  pinMode(blueLED,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  Serial.print(distance);
  Serial.println(" cm");
  
  if(distance<15){
    //Red goes on
    digitalWrite(redLED,HIGH);
    digitalWrite(blueLED,LOW);
    digitalWrite(greenLED,LOW);
  }
  else if(distance>100){ 
  //Green goes on
   digitalWrite(greenLED,HIGH); 
   digitalWrite(redLED,LOW);
   digitalWrite(blueLED,LOW);
  }
  else{
    //Blue goes on
    digitalWrite(redLED,LOW);
    digitalWrite(greenLED,LOW);
    digitalWrite(blueLED,HIGH);
  }
  
  delay(500);
}
