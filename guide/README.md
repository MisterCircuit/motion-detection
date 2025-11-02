## 🔁 How to Reproduce This Project

Follow the steps below to rebuild and run this project on your hardware:

### 1️⃣ Required Components
Make sure you have all components listed in the **Components Used** section.

### 2️⃣ Circuit Wiring
Wire the system according to the circuit diagram:
- PIR OUT → Arduino D6
- LED → Arduino D4 (through 1kΩ resistor)
- Buzzer → Arduino D5
- Relay IN → Arduino D7
- Buck converter output +5V → PIR VCC, LED, Buzzer 
- External supply (+12V) → Solenoid Lock (through relay)

📌 *A full schematic image is included in `/guide/` folder.*

### 3️⃣ Upload the Code
1. Connect Arduino Nano to PC using USB
2. Open **Arduino IDE**
3. Select:
   - Board: **Arduino Nano**
   - Processor: **ATmega328P (Old Bootloader)** if new boards fail
4. Upload the sketch from code/motion_detection.ino


### 4️⃣ Power System
- USB powers Arduino
- External supply powers solenoid (do **not** power solenoid from Arduino)

### 5️⃣ Testing the System
1. Wait 5–10 seconds for PIR to calibrate
2. Walk in front of the PIR sensor
3. You should see:
- LED ON
- Buzzer alarm
- Solenoid lock activated
4. After no movement → everything turns OFF automatically

✅ If everything matches, your build is complete!

