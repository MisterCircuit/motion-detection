# 🔐 Motion Detection Solenoid Lock System using PIR & Arduino Nano

This project uses a PIR motion sensor to detect human motion and trigger a solenoid lock. A buzzer and LED are used for alert indication. The system is designed for smart security applications such as door access control, safes, and restricted-zone entry.

---

## 🧠 Project Overview

When the PIR sensor detects movement:
- ✅ Solenoid lock activates (unlock/lock mechanism)
- 🔊 Buzzer alarm sounds
- 💡 LED indicator turns ON

When no motion is detected:
- ❌ Solenoid returns to default state
- 🔇 Buzzer OFF
- 🌑 LED OFF

---

## ✨ Features

- Real-time motion detection
- Automated locking mechanism
- Audible and visual alert system
- Low-power design with Arduino Nano
- Can be integrated into home & office security systems

---

## 🛠 Components Used

| Component | Qty |
|----------|----|
| Arduino Nano | 1 |
| PIR Motion Sensor (HC-SR501) | 1 |
| Solenoid Lock (12V recommended) | 1 |
| Relay module (to drive solenoid) | 1 |
| Buzzer | 1 |
| LED + Resistor | 1 |
| Jumper wires | As needed |
| External power supply for Solenoid | 1 |

---

## ⚙️ Circuit Diagram (to be added)

📌 *Wiring details will be included once schematic image is uploaded.*https://github.com/MisterCircuit/motion-detection/blob/main/image.png

---

## 🚀 How It Works

1. PIR detects infrared radiation change when a person enters its range  
2. Arduino processes the digital signal from the PIR  
3. Relay triggers the solenoid lock  
4. LED & buzzer provide motion alert feedback  

---

## 🧩 Arduino Sketch

```cpp
// Add your Arduino code here once completed


# 🚀 Project Title

A brief description of what this project does and who it's for.

## 📖 Table of Contents
- [About](#about)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Demo](#demo)
- [Technologies](#technologies)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)
- [Authors](#authors)

## 🧾 About
Explain what the project is for, the motivation, and what problem it solves.

## ✨ Features
- Feature 1
- Feature 2
- Feature 3

## 🛠 Installation
```bash
# clone the repo
git clone https://github.com/your-username/repo-name.git

# navigate to project
cd repo-name

# install dependencies
npm install





Circuit  diagram 
Download Fritzing app here https://arduinofactory.fr/en/download-fritzing-for-free/

![alt text](image.png)