#include <SoftwareSerial.h>

SoftwareSerial BT(12, 13); // RX, TX

// Joystick analog pins
int joyX = A0;
int joyY = A1;
int btnZ = 8; // Joystick center button

// Joystick shield buttons
const int btnA = 2;
const int btnB = 3;
const int btnC = 4;
const int btnD = 5;
const int btnE = 6;
const int btnF = 7;

String lastJoystickCommand = "";
bool lastWasJoystick = false;

void setup() {
  // Button inputs
  pinMode(btnZ, INPUT_PULLUP);
  pinMode(btnA, INPUT_PULLUP);
  pinMode(btnB, INPUT_PULLUP);
  pinMode(btnC, INPUT_PULLUP);
  pinMode(btnD, INPUT_PULLUP);
  pinMode(btnE, INPUT_PULLUP);
  pinMode(btnF, INPUT_PULLUP);

  // Power HC-05
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);

  Serial.begin(9600);
  BT.begin(9600);

  Serial.println("Joystick + Button Control Ready!");
}

void loop() {
  int x = analogRead(joyX);
  int y = analogRead(joyY);

  // Read buttons
  bool zPressed = digitalRead(btnZ) == LOW;
  bool aPressed = digitalRead(btnA) == LOW;
  bool bPressed = digitalRead(btnB) == LOW;
  bool cPressed = digitalRead(btnC) == LOW;
  bool dPressed = digitalRead(btnD) == LOW;
  bool ePressed = digitalRead(btnE) == LOW;
  bool fPressed = digitalRead(btnF) == LOW;

  // --- BUTTONS with 100ms debounce ---
  if (aPressed) {
    BT.println("BTN_A");
    Serial.println("Sent: BTN_A");
    delay(100);
    while (digitalRead(btnA) == LOW); // Wait for release
    return;
  }
  if (bPressed) {
    BT.println("BTN_B");
    Serial.println("Sent: BTN_B");
    delay(100);
    while (digitalRead(btnB) == LOW);
    return;
  }
  if (cPressed) {
    BT.println("BTN_C");
    Serial.println("Sent: BTN_C");
    delay(100);
    while (digitalRead(btnC) == LOW);
    return;
  }
  if (dPressed) {
    BT.println("BTN_D");
    Serial.println("Sent: BTN_D");
    delay(100);
    while (digitalRead(btnD) == LOW);
    return;
  }
  if (ePressed) {
    BT.println("BTN_E");
    Serial.println("Sent: BTN_E");
    delay(100);
    while (digitalRead(btnE) == LOW);
    return;
  }
  if (fPressed) {
    BT.println("BTN_F");
    Serial.println("Sent: BTN_F");
    delay(100);
    while (digitalRead(btnF) == LOW);
    return;
  }
  if (zPressed) {
    BT.println("BTN_Z");
    Serial.println("Sent: BTN_Z");
    delay(100);
    while (digitalRead(btnZ) == LOW);
    return;
  }
  // --- JOYSTICK ---
  String command = "";

  if (y < 400) {
    command = "BACKWARD";
    lastWasJoystick = true;
  } else if (y > 600) {
    command = "FORWARD";
    lastWasJoystick = true;
  } else if (x < 400) {
    command = "LEFT";
    lastWasJoystick = true;
  } else if (x > 600) {
    command = "RIGHT";
    lastWasJoystick = true;
  } else if (zPressed) {
    command = "STOP";
    lastWasJoystick = false;
  } else if (lastWasJoystick) {
    // Joystick returned to center
    command = "STOP";
    lastWasJoystick = false;
  } else {
    command = "";
  }

  if (command != "" && command != lastJoystickCommand) {
    BT.println(command);
    Serial.println("Sent: " + command);
    lastJoystickCommand = command;
  }

  delay(100);
}
