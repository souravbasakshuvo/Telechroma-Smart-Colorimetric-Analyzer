// Bluetooth communication setup for Arduino and mobile app

#include <SoftwareSerial.h>

SoftwareSerial BTserial(10, 11); // RX, TX pins for Bluetooth module

void setup() {
  Serial.begin(9600);       // Serial monitor
  BTserial.begin(9600);     // Bluetooth communication setup
}

void loop() {
  if (BTserial.available()) {
    char receivedData = BTserial.read();
    Serial.print("Received: ");
    Serial.println(receivedData);
    // Process received data as needed
  }

  if (Serial.available()) {
    char dataToSend = Serial.read();
    BTserial.write(dataToSend);  // Send data to Bluetooth
  }
}
