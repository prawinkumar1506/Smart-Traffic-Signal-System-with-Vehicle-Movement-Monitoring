#include <Servo.h>

#define echoPin 9  // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 10
#define buzzerPin 8  // attach a buzzer to pin 8
#define servoPin 6   // attach a servo motor to pin 6

// Define the pin numbers for the three LEDs
const int ledGreen = 2;  // Green LED connected to digital pin 2
const int ledYellow = 3; // Yellow LED connected to digital pin 3
const int ledRed = 7;    // Red LED connected to digital pin 7

Servo gateServo;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  // Initialize the digital pins as outputs
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(12,OUTPUT);

  gateServo.attach(servoPin); // Attach the servo motor
  gateServo.write(0);          // Ensure the gate is initially closed (0 degrees)
  Serial.begin(9600);          // Start serial communication for debugging
}

void loop() {
   gateServo.write(0);
  digitalWrite(12,HIGH);
  // Green Light
  digitalWrite(ledGreen, HIGH);
  Serial.println("Green Light: Vehicles can go");
  delay(5000);
  Serial.println("Only last 5 seconds left!");
  delay(5000);
  digitalWrite(ledGreen, LOW); // Turn off Green LED

  // Yellow Light
  digitalWrite(ledYellow, HIGH);
  Serial.println("Yellow Light: Prepare to stop");
  for (int i = 0; i < 50; i++) {
    detectDistanceYellow();
    delay(100); // Short delay to allow sensor to process
  }
  noTone(buzzerPin);           // Ensure buzzer stops after yellow light
  digitalWrite(ledYellow, LOW); // Turn off Yellow LED

  // Red Light
  digitalWrite(ledRed, HIGH);
  gateServo.write(90);
  Serial.println("Red Light: Vehicles must stop");
  for (int i = 0; i < 100; i++) {
    detectDistanceRed();
    delay(100); // Short delay to allow sensor to process
  }
  noTone(buzzerPin);           // Ensure buzzer stops after red light
           // Gate returns to closed position
  digitalWrite(ledRed, LOW);   // Turn off Red LED

  // Reset and start again
  Serial.println("Green Light: You can go now");
}

void detectDistanceYellow() {
  int distance = getDistance();

  if (distance < 15) {  // Adjusted range for Yellow light
    Serial.println("Warning! Object detected within 15 cm!");
    tone(buzzerPin, 1000); // Warning buzzer sound
  } else {
    noTone(buzzerPin); // Turn off buzzer if no object within 15 cm
  }
}

void detectDistanceRed() {
  int distance = getDistance();

  if (distance >= 5 && distance < 12) {  // Adjusted range for Red light
    Serial.println("Warning! Stay back!");
    tone(buzzerPin, 1000); // Warning buzzer sound
  } else if (distance < 5) {
    Serial.println("Danger! The  toll gate is closed!");
    tone(buzzerPin, 2000); // Danger buzzer sound
    gateServo.write(90);   // Rotate servo motor to open gate (90 degrees)
  } else {
    noTone(buzzerPin);     // Turn off buzzer if no danger
  }
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  int duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  int distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  return distance;
}
