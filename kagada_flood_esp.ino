#include <ESP32Servo.h>
#include <LiquidCrystal_I2C.h> // New library for I2C

#define TRIG_PIN 19
#define ECHO_PIN 18
#define GREEN_LED_PIN 25
#define YELLOW_LED_PIN 26
#define RED_LED_PIN 27
#define BUZZER_PIN 23
#define SERVO_PIN 13

// I2C LCD Initialization: (I2C Address, Columns, Rows)
// 0x27 is a common address, but check your module; 0x3F is another possibility.
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Servo object
Servo floodGateServo;

void setup() {
  Serial.begin(115200);
  Serial.println("Flood Warning System Starting...");
    
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Attach servo motor to pin
  floodGateServo.attach(SERVO_PIN);
  floodGateServo.write(180);

  // Initialize 16x2 I2C LCD display
  lcd.init(); // Initialize the I2C LCD
  lcd.backlight(); // Turn on the backlight
  
  lcd.print("System Init...");
  delay(2000);
  lcd.clear();
  lcd.print("Flood Detector");
  lcd.setCursor(0, 1);
  lcd.print("Ready!");
  delay(2000);
  lcd.clear();
}

void loop() {
  long duration;
  long distance;

  // Send pulse to trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure echo pulse width
  // pulseIn() timeout set to 30ms (for max distance approx 5m)
  duration = pulseIn(ECHO_PIN, HIGH, 30000); 
    
  // Convert pulse duration to distance in cm
  if (duration > 0) {
    distance = (duration / 2) / 29.1;
  } else {
    // If no echo is received, assume max distance (or error)
    distance = 500; 
  }

  lcd.clear();

  if (distance > 20) {
    // Normal State
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    floodGateServo.write(180); // Gate Closed (Safe)
    
    lcd.setCursor(0, 0);
    lcd.print("Status: SAFE");
    lcd.setCursor(0, 1);
    lcd.print("Water Level OK");
  }
  else if (distance > 10 && distance <=  15) {
    // Caution state
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    floodGateServo.write(180); // Gate Closed
    
    lcd.setCursor(0, 0);
    lcd.print("Caution! ");
    lcd.setCursor(0, 1);
    lcd.print("Level: ");
    lcd.print(distance);
    lcd.print("cm");
  }
  else if (distance >5 && distance <= 10) {
    // Gate activates (Pre-warning)
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    floodGateServo.write(90); // Gate Open (Barricade UP)
    
    lcd.setCursor(0, 0);
    lcd.print("Barricade UP!");
    lcd.setCursor(0, 1);
    lcd.print("Level: ");
    lcd.print(distance);
    lcd.print("cm");
  }
  else if (distance <= 5 ) {
    // Danger State (Flood)
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);
    floodGateServo.write(90); // Gate Open
    
    lcd.setCursor(0, 0);
    lcd.print("!!! FLOOD !!!");
    lcd.setCursor(0, 1);
    lcd.print("Evacuate Now!");
    
    // Flashing Red LED and Buzzer
    digitalWrite(BUZZER_PIN, HIGH);
    delay(250);
    digitalWrite(BUZZER_PIN, LOW);
    delay(100);
  }

  // Display distance for debugging in the serial monitor
  Serial.print("Distance (cm): ");
  Serial.println(distance);

  delay(350);
}