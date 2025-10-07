#define trigPin1 3
#define echoPin1 2
#define trigPin2 6
#define echoPin2 7
#define trigPin3 5
#define echoPin3 4

#define RED_LIGHT 10
#define YELLOW_LIGHT 12
#define GREEN_LIGHT 11

void setup() {
  Serial.begin(9600);

  // Sensors
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  // Traffic Lights
  pinMode(RED_LIGHT, OUTPUT);
  pinMode(YELLOW_LIGHT, OUTPUT);
  pinMode(GREEN_LIGHT, OUTPUT);
}

void loop() {
  long duration1, distance1;
  long duration2, distance2;
  long duration3, distance3;

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

  // Sensor 3
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = (duration3 / 2) / 29.1;

  Serial.print("S1: "); Serial.print(distance1);
  Serial.print(" cm | S2: "); Serial.print(distance2);
  Serial.print(" cm | S3: "); Serial.println(distance3);

  // Traffic light logic
  if (distance1 < 7) {           // Train arrived
    digitalWrite(RED_LIGHT, HIGH);
    digitalWrite(YELLOW_LIGHT, LOW);
    digitalWrite(GREEN_LIGHT, LOW);
  } 
  else if (distance3 < 7) {      // Train approaching gate
    digitalWrite(RED_LIGHT, LOW);
    digitalWrite(YELLOW_LIGHT, HIGH);
    digitalWrite(GREEN_LIGHT, LOW);
  } 
  else if (distance2 < 7) {      // Train departed
    digitalWrite(RED_LIGHT, LOW);
    digitalWrite(YELLOW_LIGHT, LOW);
    digitalWrite(GREEN_LIGHT, HIGH);
  } 
  else {                          // Default state
    digitalWrite(RED_LIGHT, LOW);
    digitalWrite(YELLOW_LIGHT, LOW);
    digitalWrite(GREEN_LIGHT, HIGH);
  }

  delay(200);
}
