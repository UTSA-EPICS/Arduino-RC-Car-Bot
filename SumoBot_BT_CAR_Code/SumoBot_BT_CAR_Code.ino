#include <AFMotor.h>
#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(A1, A0);

// Motors
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

// Servos on D9 and D10
Servo servo1;
Servo servo2;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);

  servo1.attach(9);   // D9
  servo2.attach(10);  // D10

  // LED pins setup
  pinMode(A2, OUTPUT);  // Button A LED
  pinMode(A3, OUTPUT);  // Button B LED
  pinMode(A4, OUTPUT);  // Button C LED
  pinMode(A5, OUTPUT);  // Button D LED

  Serial.println("Motor + Servo + LED controller ready!");
}

void loop() {
  if (BT.available()) {
    String command = BT.readStringUntil('\n');
    command.trim();
    Serial.println("Received: " + command);

    if (command == "FORWARD") {
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);
    } else if (command == "BACKWARD") {
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
    } else if (command == "LEFT") {
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);
    } else if (command == "RIGHT") {
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
    } else if (command == "STOP") {
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
    } else if (command == "BTN_F") {
      Serial.println("Rotating Servo 1 to 180°");
      servo1.write(180);
      delay(500);
      servo1.write(0);
    } else if (command == "BTN_E") {
      Serial.println("Rotating Servo 2 to 180°");
      servo2.write(180);
      delay(500);
      servo2.write(0);
    } else if (command == "BTN_A") {
      digitalWrite(A2, HIGH);
      delay(300);
      digitalWrite(A2, LOW);
    } else if (command == "BTN_B") {
      digitalWrite(A3, HIGH);
      delay(300);
      digitalWrite(A3, LOW);
    } else if (command == "BTN_C") {
      digitalWrite(A4, HIGH);
      delay(300);
      digitalWrite(A4, LOW);
    } else if (command == "BTN_D") {
      digitalWrite(A5, HIGH);
      delay(300);
      digitalWrite(A5, LOW);
    } else {
      Serial.println("Unknown command");
    }
  }
}
