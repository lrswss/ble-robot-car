/*
 * Sketch to control a 4WD robot car with a smartphone
 * using Bluetooth 4.0 (BLE)
 * 
 * Copyright (c) 2020 software@bytebox.org
 * published under the MIT License
 * https://opensource.org/licenses/MIT
 * 
 * Parts:
 * - Kit "4WD Smart Car" (chassis, 4 motors, battery holder)
 * - Arduino Uno
 * - Arduino motor shield (e.g. Deek-Robot Motor shield)
 * - BLE Bluetooth Module (AT-09)
 * - 1k and 2k resistors for 3.3v voltage divider on BLE RX line
 * - few cables
 * 
 * The Arduino motor shield drives two pairs of DC motors 
 * (channel A left, channel B right). A BLE bluetooth module
 * (AT-09) connected via SoftSerial is used to control the
 * car using simple serial commands.
 * 
 * Free App used on iOS to control the car: "BLEJoyStick"
 * 
 * Pinout motor shield:
 * Function     ChA  ChB
 * Direction    D12  D1
 * Speed (PWM)  D3   D11
 * Brake        D9   D8
 * Current      A0   A1
 * 
 */

#include <SoftwareSerial.h>
SoftwareSerial softSerial(5, 4);  // RX, TX


void brakesOn() {
  Serial.println("Stopping!");
  analogWrite(3, 0);
  digitalWrite(9, HIGH);
  analogWrite(11, 0);
  digitalWrite(8, HIGH);
}


void brakesOff() {
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
}


void turnLeft() {
  Serial.println("Turning left...");
  brakesOff();
  digitalWrite(12, LOW); // right motors backwards
  analogWrite(3, 240);
  digitalWrite(13, HIGH); // left motors forwards
  analogWrite(11, 240);
}


void turnRight() {
  Serial.println("Turning right...");
  brakesOff();
  digitalWrite(12, HIGH); // right motors forwards
  analogWrite(3, 240);
  digitalWrite(13, LOW); // left motors backwards
  analogWrite(11, 240);
}


void moveForward() {
  Serial.println("Moving forwards...");
  brakesOff();
  // left
  digitalWrite(12, HIGH);  // set forward direction
  analogWrite(3, 255);  // full speed
  // right
  digitalWrite(13, HIGH);
  analogWrite(11, 255);
}


void moveBackward() {
  Serial.println("Moving backwards...");
  brakesOff();
  // left
  digitalWrite(12, LOW);  // set backward direction
  analogWrite(3, 255);  // full speed
  // right
  digitalWrite(13, LOW);
  analogWrite(11, 255);
}


void setup() {
  Serial.begin(9600); // serial monitor
  softSerial.begin(9600);  // serial connection to BLE module
  Serial.println("Ready to rumble...");
  
  // controls for two right motors (channel A)
  pinMode(12, OUTPUT); // motor direction
  pinMode(9, OUTPUT);  // brakes

  // controls for two left motors (channel B)
  pinMode(13, OUTPUT); // motor direction
  pinMode(8, OUTPUT);  // brakes

  brakesOn();
}


// main control loop
void loop() {
  char cmd;

  while (softSerial.available()) {
    cmd = softSerial.read();
    switch (cmd) {
      case 'a':
        moveBackward();
        break;
      case 'c': 
        moveForward();
        break;
      case 'd':
        turnRight();
        break;
      case 'b':
        turnLeft();
        break;
      default:
        brakesOn();
        break;
    }
  }
}
