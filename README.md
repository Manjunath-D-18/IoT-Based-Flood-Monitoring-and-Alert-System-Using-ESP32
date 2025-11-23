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
