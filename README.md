
# Smart Traffic Signal System with Vehicle Movement Monitoring

## Overview

This project simulates a **smart traffic signal system** that monitors vehicle behavior during different traffic light signals (green, yellow, and red). The system uses an ultrasonic sensor to detect vehicle movement and a buzzer to provide warning or danger alerts based on the signal light. Additionally, a servo motor simulates the opening and closing of a toll gate when vehicles attempt to move during red light.

The project was developed as part of a two-day workshop on **Embedded Software Development**, conducted by the **CSE Department of SSN College of Engineering**.

## Components Used

- Arduino Uno
- 3 LEDs (Green, Yellow, Red)
- Ultrasonic Sensor (HC-SR04)
- Servo Motor
- Buzzer
- Connecting Wires
- Resistors
- Breadboard

## Features

1. **Green Light**: Vehicles are allowed to move without any warning.
2. **Yellow Light**: The system provides a warning sound through the buzzer if movement is detected within a certain range.
3. **Red Light**: The system produces a danger alert through the buzzer if movement is detected, and the toll gate closes (controlled by a servo motor).

## How It Works

- The traffic light system operates in a loop with each light (green, yellow, red) being active for a fixed period.
- An **ultrasonic sensor** monitors the distance of an object (vehicle). If a vehicle moves during a yellow or red light, the system triggers the buzzer to provide a warning or danger sound.
- A **servo motor** controls the toll gate, which closes when the red light is active and movement is detected.

## Installation and Setup

1. **Hardware Setup**:
    - Connect the **LEDs** (Green, Yellow, Red) to the appropriate digital pins of the Arduino.
    - Attach the **ultrasonic sensor** (HC-SR04) to the Arduino to detect distance.
    - Connect the **buzzer** to a digital pin to produce the sound.
    - Connect the **servo motor** to the designated pin to simulate the toll gate.
  
2. **Software Setup**:
    - Install the Arduino IDE from [here](https://www.arduino.cc/en/software).
    - Install the required **Servo** library (included with Arduino IDE).
  
3. **Code**:
    - Upload the `SmartTrafficSignal.ino` file to your Arduino Uno.
    - Make sure the pin connections in the code match your physical setup.

## Pin Configuration

- **Green LED**: Pin 2
- **Yellow LED**: Pin 3
- **Red LED**: Pin 7
- **Ultrasonic Sensor**: Echo Pin - Pin 9, Trig Pin - Pin 10
- **Buzzer**: Pin 8
- **Servo Motor**: Pin 6

## Usage

Once the hardware is set up and the code is uploaded:
1. The system will simulate a traffic light.
2. When the green light is on, vehicles can pass freely.
3. When the yellow light is on, the system checks if a vehicle is within a warning range and triggers a buzzer alert.
4. When the red light is on, the system closes the toll gate using the servo motor if a vehicle is detected and triggers a danger alert.
5. The cycle repeats automatically.

## Code Explanation

The project consists of several main functions:

1. **LED Control**: Controls the state of the traffic light (green, yellow, red).
2. **Distance Detection**: Uses the ultrasonic sensor to measure the distance between the vehicle and the sensor.
3. **Servo Motor Control**: Simulates a toll gate, opening and closing depending on the light and vehicle movement.
4. **Buzzer Alerts**: Generates warning and danger sounds based on the distance and current light status.

For detailed code, refer to the `SmartTrafficSignal.ino` file.

## Future Enhancements

- Implement a more advanced toll gate simulation with multiple lanes.
- Add vehicle counting and speed detection using additional sensors.
- Integrate IoT features to monitor traffic signal violations in real-time.

## Contributors

- **Prawin Kumar S**
- **Prem Shankar S**
- **Monish Kumar**

