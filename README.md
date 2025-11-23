# IoT-Based-Flood-Monitoring-and-Alert-System-Using-ESP32
A real-time flood monitoring system using ESP32 and an ultrasonic sensor to track rising water levels. It triggers SAFE/WARNING/DANGER alerts via LEDs, LCD, buzzer, and servo-based floodgate action. With Wi-Fi support, the system can also send SMS alerts for early evacuation and disaster response

## 📌 Overview
Flooding is one of the most destructive natural disasters, often resulting in heavy damage to infrastructure and loss of life. Traditional monitoring methods are either manual or delayed, reducing the ability to respond quickly.  

This project aims to solve that problem by building an **IoT-based real-time flood monitoring and alert system** using an **ESP32 microcontroller**, **ultrasonic water-level sensing**, **LED indicators**, **LCD display**, **buzzer alarm**, **servo-controlled floodgate simulation**, and **SMS alert notifications** using Wi-Fi connectivity and services such as Twilio/Blynk/Firebase.

The system detects rising water levels and triggers alerts based on predefined thresholds (SAFE → WARNING → DANGER), and in critical cases, sends **SMS alerts to authorities or residents**.

---

## 🎯 Objectives
- Monitor water levels continuously in real time using ultrasonic sensors.
- Trigger visual and audio alerts based on severity levels.
- Send SMS warnings when water exceeds critical danger level.
- Control a servo motor to simulate automatic floodgate action.
- Provide expandable IoT capabilities for cloud dashboards and remote access.
- Implement a low-cost, scalable solution suitable for flood-prone regions.

---

## 🧠 System Architecture & Workflow

### **Block Diagram**
[ Ultrasonic Sensor ] ---> [ ESP32 ] ---> LEDs + Buzzer + LCD + Servo
|
| Wi-Fi
↓
IoT Platform / SMS Service


### **Data Flow**
1. HC-SR04 ultrasonic sensor measures distance from the water surface.
2. ESP32 calculates level and compares values against preset thresholds.
3. Mode changes occur depending on detected level:
   - SAFE → Green LED + LCD update
   - WARNING → Yellow LED + LCD update
   - DANGER → Red LED + Buzzer + Servo + SMS alert
4. Optional cloud dashboard displays real-time monitoring data.

---

## 🛠 Hardware Components
| Component | Model | Purpose |
|-----------|-------|----------|
| ESP32 | DevKit V1 | Controller + Wi-Fi IoT support |
| Ultrasonic Sensor | HC-SR04 | Water-level measurement |
| LCD Display | 16×2 | Status display |
| LEDs | R/Y/G | Visual risk indication |
| Buzzer | 5V | Audible emergency alert |
| Servo Motor | SG90 | Floodgate simulation |
| Resistors & Jumper Wires | – | Circuit connections |
| Power Supply | USB 5V | System power |

---

## 💡 Water-Level Threshold Logic
| Condition | Distance Value | System Behavior |
|-----------|----------------|-----------------|
| SAFE | > 20cm | Green LED + LCD “SAFE” |
| WARNING | 10cm–20cm | Yellow LED + LCD “WARNING” |
| DANGER | < 10cm | Red LED + Buzzer + Servo + SMS |

---

## 🔔 SMS Alert System
### **How SMS alert is triggered**
When the ultrasonic reading reaches **danger level**, ESP32 uses Wi-Fi to contact an SMS platform (Twilio, Blynk, Firebase + IFTTT, Fast2SMS India API, etc).

### **Example SMS Message**


⚠ URGENT: Flood Alert! Water level has crossed the DANGER threshold.
Immediate action is required. Location: [Area Name]

| Test Activity          | Expected Output          | Achieved |
| ---------------------- | ------------------------ | -------- |
| Initial power up       | LCD ON, LED safe mode    | ✔        |
| Increasing water level | LED safe → warning       | ✔        |
| Crossing danger level  | Red LED & buzzer         | ✔        |
| Servo gate movement    | 0° → 90° or 180°         | ✔        |
| SMS transmission       | Display message on phone | ✔        |
