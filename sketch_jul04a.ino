//#include <Time.h>

int motor1pin1 = 8;
int motor1pin2 = 7;

int motor2pin1 = 9;
int motor2pin2 = 10;

int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;

#define echoPin 12 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 13 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  
  Serial.begin(9600);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  //sensor pins
  pinMode(A0, INPUT);
  pinMode(A5, INPUT);
  pinMode(A3, INPUT);

  pinMode(6, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
 
  analogWrite(6, 100); //ENA pin
  analogWrite(11, 100); //ENB pin
  int var1 = analogRead(A0);
  int var2 = analogRead(A5);
  int var3 = analogRead(A3);

  Serial.println(distance);
  
  if (var1<1000 && var2<1000 && distance>=5.08 ) {
    Serial.println("Detect");
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(50);

  digitalWrite(LED1, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  }
//else if (distance<=5.08) {
//  Serial.println("Ultrasonic Detect");
//digitalWrite(motor1pin1, HIGH);
//  digitalWrite(motor1pin2, LOW);
//
//  digitalWrite(motor2pin1, LOW);
//  digitalWrite(motor2pin2, HIGH);
//  delay(1000);
//}
 
  else {
  Serial.println("Doesn't Detect");

  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED1, LOW);
  digitalWrite(LED4, LOW);

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  //delay(1000);
 
  uint32_t time_start;
  time_start = millis();
  while(millis() - time_start < 1000 ) {
    int var3 = analogRead(A3);
    if(var3 > 1000) {
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);

      digitalWrite(motor2pin1, HIGH);
      digitalWrite(motor2pin2, LOW);
      //delay(1000);
      Serial.println("off the back");
      break;
    }

  }

 
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  time_start = millis();
  while(millis() - time_start < 1000 ) {
    int var3 = analogRead(A3);
    if(var3 > 1000) {
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);

      digitalWrite(motor2pin1, HIGH);
      digitalWrite(motor2pin2, LOW);
      Serial.println("off the back");
      break;
    }

  }
}

//
//  //Controlling speed (0 = off and 255 = max speed):
//  analogWrite(6, 100); //ENA pin
//  analogWrite(11, 100); //ENB pin
//  
//  // put your main code here, to run repeatedly:  
//  digitalWrite(motor1pin1, LOW);
//  digitalWrite(motor1pin2, HIGH);
//
//  digitalWrite(motor2pin1, HIGH);
//  digitalWrite(motor2pin2, LOW);
//  delay(1000);
}
