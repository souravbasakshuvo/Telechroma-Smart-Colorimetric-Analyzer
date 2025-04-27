
# Telechroma: Smart Colorimetric Analyzer - Design Documentation

## Introduction

This document outlines the technical design of the **Telechroma** system, a portable, affordable, and user-friendly colorimetric analyzer aimed at enabling remote medical diagnostics via telemedicine applications. The system integrates hardware and software components, utilizing colorimetric analysis to determine the concentration of biological analytes like glucose in urine samples.

## System Overview

The **Telechroma** system consists of the following major components:
- **Hardware**: Arduino Nano microcontroller, TCS3200 color sensor, Bluetooth HC-05 module, breadboard, and wires.
- **Software**: Arduino code for controlling hardware, a mobile application built using MIT App Inventor for data display and communication.

## Architecture

The system architecture includes the following main subsystems:

### 1. **Hardware Subsystem**
   - **Arduino Nano**: This microcontroller processes data from the color sensor and handles Bluetooth communication.
   - **TCS3200 Color Sensor**: Detects color changes in urine samples. The sensor outputs RGB values that are correlated with analyte concentration.
   - **Bluetooth HC-05 Module**: Enables wireless communication between the device and the mobile application. It transmits the color sensor data to the app in real-time.

### 2. **Software Subsystem**
   - **Arduino IDE**: Used to program the Arduino Nano to read sensor data and send it to the Bluetooth module.
   - **MIT App Inventor**: The mobile application that interfaces with the Telechroma device. The app collects sensor data via Bluetooth and displays the analyte concentration on a smartphone in real-time.

## System Flow

### 1. **Data Collection**
   - The user places a urine sample in the test tube, and the system adds Benedict's reagent.
   - The TCS3200 sensor detects the color change and reads the RGB values.
   
### 2. **Data Transmission**
   - The RGB data is sent wirelessly from the Arduino Nano to the mobile application via the HC-05 Bluetooth module.

### 3. **Data Processing and Display**
   - The app receives the RGB values and compares them to predefined color mappings.
   - The analyte concentration (e.g., glucose) is displayed to the user, with a visual representation of the color change.

### 4. **User Interface**
   - **Main Screen**: The user can select either "Using Device" (with sensor) or "Using Camera" (with mobile phone camera) mode.
   - **Device Mode**: The app connects to the Bluetooth module, receives data, and displays results.
   - **Camera Mode**: The app allows the user to capture an image of the sample, process the RGB values, and display the results.

## Design Decisions

### 1. **Choice of Colorimetric Analysis**
   - The system uses **Benedict's Test** for glucose detection, which provides distinct color changes depending on glucose concentration in the urine sample.
   - The colorimetric approach allows for a non-invasive, cost-effective diagnostic method.

### 2. **Bluetooth Communication**
   - We chose the **HC-05 Bluetooth module** for communication because of its wide compatibility and ease of use with Arduino.
   - Data is transmitted in real-time to the mobile app to ensure fast and efficient diagnostics.

### 3. **Mobile Application**
   - **MIT App Inventor** was selected due to its user-friendly interface and drag-and-drop environment, making it easy to develop a cross-platform application.
   - The app supports two modes: device mode (with the color sensor) and camera mode (using the phone's camera to detect colors).

## Hardware Design

### Circuit Diagram
   - The circuit connects the Arduino Nano to the TCS3200 sensor and the HC-05 Bluetooth module. The diagram illustrates how each component is wired and powered.

![Circuit Diagram](assets/diagrams/circuit_diagram.png)

### 3D Model
   - The housing for the device was designed using **SolidWorks** to ensure the components are securely placed and easy to assemble.
   
![Device 3D Model](assets/diagrams/device_model.png)

## Software Design

### Arduino Code Structure

The Arduino code includes the following key functions:
1. **Setup**: Initializes the TCS3200 sensor and Bluetooth module.
2. **Loop**: Reads color data from the sensor and sends it over Bluetooth.
3. **Bluetooth Communication**: Handles data transmission between the Arduino and the mobile app.

### Mobile App Design

The app was created using **MIT App Inventor**, and it includes:
- **Blocks for Bluetooth communication**: These blocks allow the app to pair with the Arduino and receive data.
- **Color Mapping**: The app uses a color map to determine the concentration of analytes based on RGB values.
- **UI/UX Design**: The app has a simple interface that displays real-time results and offers user-friendly navigation.

## Future Enhancements

1. **Advanced Sensors**: Integration with more advanced sensors, such as a spectrometer, for better accuracy and precision in analyzing a wider range of analytes.
2. **Hardware Improvements**: The design can be further optimized for durability and portability, especially for field testing in remote areas.
3. **App Features**: Adding more analytes for detection and improving the UI/UX to make it more intuitive for non-expert users.

## Conclusion

The Telechroma project demonstrates a feasible, cost-effective approach to telemedicine, providing accessible diagnostic solutions for remote healthcare. The integration of colorimetric analysis with telemedicine platforms holds the potential to revolutionize healthcare accessibility, especially in under-served areas.

---

**References**:
1. Dae-Sik Lee, Byoung Goo Jeon, Chunhwa Ihm, Je-Kyun Park, Mun Yeon Jung, "A simple and smart telemedicine device for developing regions: a pocket-sized colorimetric reader," Lab on a Chip, 2011.
2. Deepak Pathania et al., "Telemedicine," Springer Handbook of Medical Technology, 2022.
