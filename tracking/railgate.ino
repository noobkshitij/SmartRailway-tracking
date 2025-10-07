#define trigPin1 3
#define echoPin1 2
#define trigPin2 6
#define echoPin2 7
#define sound A0

#include <Servo.h>

Servo myservo;   // for one gate arm
Servo myservo1;  // for the other gate arm

bool gateOpen = true; // to keep track of gate state

void setup() {
myservo.attach(9);   // attaches the servo on pin 9
myservo1.attach(8);  // attaches the servo on pin 8
Serial.begin(9600);

pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(13, OUTPUT); // LED or indicator
}

void loop() {
long duration1, distance1;
long duration2, distance2;

// Sensor 1
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH);
distance1 = (duration1 / 2) / 29.1;

// Sensor 2
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
duration2 = pulseIn(echoPin2, HIGH);
distance2 = (duration2 / 2) / 29.1;

Serial.print("Sensor1 Distance: ");
Serial.print(distance1);
Serial.print(" cm  |  Sensor2 Distance: ");
Serial.println(distance2);

// Gate control logic
if (distance1 < 7 || distance2 < 7) {   // Object detected
if (gateOpen) {
gateOpen = false;
myservo1.write(55);
myservo.write(144);
digitalWrite(13, HIGH);
delay(750);
}
} else {                                // No object
if (!gateOpen) {
gateOpen = true;
myservo1.write(135);
myservo.write(55);
digitalWrite(13, HIGH);
delay(750);
}
}

digitalWrite(13, LOW);
delay(200);
}

Is it working code?

