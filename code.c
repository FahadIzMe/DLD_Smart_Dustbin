#include <Servo.h>
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701
Servo servo;     
int trigPin = 5;    
int echoPin = 4;   
int servoPin = 0;
int trigPin2 = 2;
int echoPin2 = 14;
int buzzer = 12;
long duration, dist, average;   
long duration2, dist2, average2;   
long aver[3];
long aver2[3]; 

void setup() {       
    Serial.begin(9600);
    servo.attach(servoPin);  
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
    pinMode(trigPin2, OUTPUT);  
    pinMode(echoPin2, INPUT);  
    pinMode(buzzer, OUTPUT);
    servo.write(0);
    delay(100);
    servo.detach(); 
} 

void measure() {  
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
dist = (duration/2) * SOUND_VELOCITY;

digitalWrite(trigPin2, LOW);
delayMicroseconds(5);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin2, LOW);
pinMode(echoPin2, INPUT);
duration2 = pulseIn(echoPin2, HIGH);
dist2 = (duration2/2) * SOUND_VELOCITY; 
}

void loop() { 
  for (int i=0;i<=2;i++) {
    measure();               
   aver[i]=dist;    
      aver2[i] = dist2;    
    delay(10);
  }
 dist=(aver[0]+aver[1]+aver[2])/3;  
 dist2 = ((aver2[0]+aver2[1]+aver2[2])/3) * CM_TO_INCH;

if ( dist2 < 1.5 ) {
 tone(buzzer, 1000);
  delay(1000);
  noTone(buzzer);
  delay(1000);  
}

if ( dist<30 ) {
 servo.attach(servoPin);
  delay(1);
 servo.write(0);  
 delay(3000);       
 servo.write(150);    
 delay(1000);
 servo.detach();      
}

Serial.print(dist);
Serial.print(dist2);
}
