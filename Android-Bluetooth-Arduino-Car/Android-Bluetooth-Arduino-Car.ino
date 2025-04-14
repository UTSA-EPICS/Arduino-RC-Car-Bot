#include <AFMotor.h>
#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(A1, A0);  // RX, TX

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

Servo servo1;
Servo servo2;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);

  servo1.attach(9);
  servo2.attach(10);

  Serial.println("Send: f (forward), b (back), l (left), r (right), s (stop)");
}

void loop() {
  char cmd = 0;

  // Check Bluetooth
  if (BT.available()) {
    cmd = BT.read();
    Serial.print("BT Command: ");
    Serial.println(cmd);
  }

  // Check Serial Monitor
  else if (Serial.available()) {
    cmd = Serial.read();
    Serial.print("Serial Command: ");
    Serial.println(cmd);
  }

  cmd = tolower(cmd);

  switch (cmd) {
    case 'f':
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);
      break;

    case 'b':
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
      break;

    case 'l':
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);
      break;

    case 'r':
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
      break;

    case '0':
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
      break;
  }
}