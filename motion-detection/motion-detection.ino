/*
 * PIR Motion Detection Security System
 * Components: PIR Sensor, Solenoid Lock (via Relay), LED, Buzzer
 * 
 * Functionality:
 * - PIR detects motion → Solenoid unlocks, LED on, Buzzer beeps
 * - No motion detected → Solenoid locks, LED off, Buzzer off
 */

// Pin Definitions
const int PIR_PIN = 6;        // PIR sensor output pin
const int RELAY_PIN = 7;      // Relay controlling solenoid lock
const int LED_PIN = 4;       // LED indicator
const int BUZZER_PIN = 5;     // Buzzer

// Timing Constants
const unsigned long LOCK_DELAY = 3000;  // Time to keep lock open after motion stops (ms)
const int BEEP_DURATION = 200;          // Buzzer beep duration (ms)

// Variables
int pirState = LOW;                     // Current PIR state
int lastPirState = LOW;                 // Previous PIR state
unsigned long motionEndTime = 0;        // Time when motion last detected
bool lockOpen = false;                  // Current lock state

void setup() {
  // Initialize pins
  pinMode(PIR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Set initial states (lock closed)
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  
  // Initialize serial monitor
  Serial.begin(9600);
  Serial.println("PIR Motion Detection System Initialized");
  Serial.println("Waiting for PIR sensor to stabilize...");
  
  // Give PIR sensor time to stabilize (30-60 seconds recommended)
  delay(2000);  // Reduced for testing, increase to 30000 for production
  Serial.println("System Ready!");
}

void loop() {
  // Read PIR sensor
  pirState = digitalRead(PIR_PIN);
  
  // Motion detected
  if (pirState == HIGH) {
    motionEndTime = millis();  // Update the last motion time
    
    // If this is new motion detection
    if (!lockOpen) {
      Serial.println("Motion Detected!");
      openLock();
    }
  }
  
  // Check if it's time to close the lock
  if (lockOpen && (millis() - motionEndTime > LOCK_DELAY)) {
    Serial.println("No motion - Closing lock");
    closeLock();
  }
  
  // Small delay for stability
  delay(100);
}

void openLock() {
  lockOpen = true;
  
  // Activate solenoid lock (unlock)
  digitalWrite(RELAY_PIN, HIGH);
  
  // Turn on LED
  digitalWrite(LED_PIN, HIGH);
  
  // Sound buzzer (short beep pattern)
  for (int i = 0; i < 2; i++) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(BEEP_DURATION);
    digitalWrite(BUZZER_PIN, LOW);
    delay(100);
  }
  
  Serial.println("Lock OPENED");
}

void closeLock() {
  lockOpen = false;
  
  // Deactivate solenoid lock (lock)
  digitalWrite(RELAY_PIN, LOW);
  
  // Turn off LED
  digitalWrite(LED_PIN, LOW);
  
  // Sound buzzer (single long beep)
  digitalWrite(BUZZER_PIN, HIGH);
  delay(BEEP_DURATION * 2);
  digitalWrite(BUZZER_PIN, LOW);
  
  Serial.println("Lock CLOSED");
}
