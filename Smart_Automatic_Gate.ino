#include <Servo.h>

Servo gateServo;

const int trigPin = 7;
const int echoPin = 6;
const int servoPin = 9;

long duration;
int distance;
bool gateOpen = false;

void setup() {
gateServo.attach(servoPin);

pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

gateServo.write(0);

Serial.begin(9600);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = duration * 0.034 / 2;

Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");

if (distance < 100 && gateOpen == false) {
gateServo.write(90);
gateOpen = true;
Serial.println("Gate Opened");
delay(3000);
}

else if (distance >= 100 && gateOpen == true) {
gateServo.write(0);
gateOpen = false;
Serial.println("Gate Closed");
}

delay(200);
}
