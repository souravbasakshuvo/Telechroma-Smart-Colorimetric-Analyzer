// Arduino Nano Code for Telechroma Colorimetric Analyzer

#include <Wire.h>
#include <TCS3200.h>   // Color sensor library
#include <SoftwareSerial.h>

SoftwareSerial BTserial(10, 11); // RX, TX pins for Bluetooth module

TCS3200 colorSensor; // Create a color sensor object

void setup() {
  Serial.begin(9600);       // Begin Serial Monitor
  BTserial.begin(9600);     // Bluetooth communication
  colorSensor.begin();      // Initialize the color sensor
  
  pinMode(5, OUTPUT);       // Set pin 5 for power to sensor (if needed)
}

void loop() {
  int redValue = colorSensor.getRed();
  int greenValue = colorSensor.getGreen();
  int blueValue = colorSensor.getBlue();

  // Send values to Bluetooth
  BTserial.print("R: ");
  BTserial.print(redValue);
  BTserial.print(" G: ");
  BTserial.print(greenValue);
  BTserial.print(" B: ");
  BTserial.println(blueValue);

  delay(500); // Wait for 0.5s before next reading
}
