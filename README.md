# Parking System Project

---

## Description:
This project implements a parking system using an Arduino Nano or Arduino Uno. The system manages parking slots, detects vehicles entering and exiting using IR sensors, and controls a servo motor acting as a barrier. The system also displays the number of available parking slots on an LCD screen.

---

## Components:
1. **Arduino Nano/Uno**
2. **IR Sensors** (2 units):
   - IR1: Detects vehicle entry.
   - IR2: Detects vehicle exit.
3. **Servo Motor**:
   - Controls the barrier gate.
4. **16x2 LCD Display with I2C Module**:
   - Displays the number of available parking slots.
5. **Resistors** (as needed for IR sensors).

---

## Features:
- Detects vehicle entry and exit.
- Updates and displays the number of available parking slots.
- Controls a servo motor to open and close a barrier.
- Displays messages for full parking and welcomes users.

---

## Arduino Pins:
| Component        | Arduino Pin |
|------------------|-------------|
| IR1 (Entry)      | 3           |
| IR2 (Exit)       | 4           |
| Servo Motor      | 2           |
| LCD (I2C)        | SDA, SCL    |

---

## Setup Instructions:
1. **Wiring**:
   - Connect IR sensors to pins 3 and 4 of the Arduino.
   - Connect the servo motor to pin 2.
   - Connect the LCD to the I2C pins (SDA, SCL).

2. **Upload the Code**:
   - Open the Arduino IDE.
   - Copy the provided code into the editor.
   - Connect the Arduino to your computer.
   - Select the correct board and port.
   - Upload the code.

3. **Power the Circuit**:
   - Use a 5V power supply or connect the Arduino to your computer for power.

---

## Operation:
1. **Startup**:
   - The LCD will display a welcome message.
2. **Vehicle Entry**:
   - If the parking slots are available:
     - IR1 detects the vehicle.
     - The barrier opens.
     - Slot count decreases.
     - The barrier closes.
   - If no slots are available:
     - The LCD displays a "Parking Full" message.
3. **Vehicle Exit**:
   - IR2 detects the vehicle.
   - The barrier opens.
   - Slot count increases.
   - The barrier closes.

---

## Code Highlights:
- **IR Sensor Detection**:
  - Uses `digitalRead()` to monitor IR sensors.
- **Servo Motor Control**:
  - Positions the servo to open and close the barrier.
- **LCD Updates**:
  - Displays slot availability and messages using `LiquidCrystal_I2C`.

---

## Schematics:
- Include connection diagrams and wiring images.

Google Docs link: https://docs.google.com/document/d/1yokDnAyzRpDVad2LHwOgKiYGoIawJgvR3s_5FT8ctug/edit?usp=sharing

---

## Future Improvements:
- Also I am going to include the Google Driver Link to upload a video later.
- Add a real-time clock module to track parking duration.
- Implement an RFID system for automatic vehicle identification.
- Add a buzzer to alert when the parking is full.
