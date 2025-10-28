# 🎵 HandaDigitalSpeaker — ESP32 Digital Sound Library

A lightweight, fast, and flexible digital sound library for **ESP32**, made for **SmartElex digital speaker modules**.  
It uses the ESP32’s built-in **LEDC PWM hardware** to generate clean tone-based sound effects — from system beeps to iPhone-like alerts.

---

## 📦 Features

✅ 35+ built-in sounds — system, alert, and digital styles  
✅ Simple one-line commands (`playSound("ok")`)  
✅ **Continuous loop mode** — play any sound repeatedly until stopped  
✅ No DAC or extra hardware required  
✅ Extremely low CPU usage using ESP32’s hardware PWM  
✅ Compact and dependency-free library

---

## 🛠️ Installation

### 🔹 Option 1 — Using Arduino Library Manager
1. Open **Arduino IDE**
2. Go to **Sketch → Include Library → Manage Libraries**
3. Search for **HandaDigitalSpeaker**
4. Click **Install**

### 🔹 Option 2 — Manual Installation
```bash
git clone https://github.com/DavinderHanda/HandaDigitalSpeaker.git

**Copy the folder to:**
Documents/Arduino/libraries/

**⚡ Quick Start Example**
#include <HandaDigitalSpeaker.h>

void setup() {
  Serial.begin(115200);
  initSoundPlayer(13);      // Initialize speaker on GPIO 13
  playSound("ok");          // Play simple OK sound
}

void loop() {
  // Nothing here — just one-time sound
}

🔁 **Continuous Sound Example**

You can now loop a sound indefinitely using playSoundLoop(), and stop it with stopSound().

#include <HandaDigitalSpeaker.h>

void setup() {
  Serial.begin(115200);
  initSoundPlayer(13);   // Speaker pin

  playSoundLoop("aa");   // Start looping "aa" sound
}

void loop() {
  delay(5000);
  stopSound();           // Stop after 5 seconds
  delay(2000);
}

🎚️ **Functions Overview**

| Function                   | Description                                   | Example                |
| -------------------------- | --------------------------------------------- | ---------------------- |
| `initSoundPlayer(pin)`     | Initialize the sound player on a specific pin | `initSoundPlayer(25);` |
| `playSound("name")`        | Play a one-time sound                         | `playSound("ok");`     |
| `playSoundLoop("name")`    | Play a sound continuously (loop)              | `playSoundLoop("aa");` |
| `stopSound()`              | Stop a continuous sound                       | `stopSound();`         |
| `ledcWriteTone(pin, freq)` | Underlying ESP32 LEDC tone generator          | —                      |

**🎵 Available Sounds**
| Type        | Command                                                        | Description                 |
| ----------- | -------------------------------------------------------------- | --------------------------- |
| **System**  | `aa`, `da`, `sdp`, `tdb`, `tct`, `ud`, `dd`                    | Simple up/down/alert tones  |
| **Alerts**  | `ok`, `err`, `bsy`, `rst`, `tmr`, `att`, `slp`                 | Status and warning tones    |
| **Digital** | `iph`, `pop`, `bbl`, `drp`, `msg`, `noti`, `clk`, `zap`, `tch` | New-style digital sounds    |
| **Utility** | `sb`, `slb`, `dbl`, `vsc`, `chn`, `fahls`, `wup`, `sllt`       | Miscellaneous effects       |
**
🧩 Example — Sound Command Test**

Control sounds dynamically via Serial Monitor commands:

#include <HandaDigitalSpeaker.h>

void setup() {
  Serial.begin(115200);
  initSoundPlayer(13);  // Speaker pin

  playSound("ok");    // OK tone
  delay(500);
  playSound("err");   // Error tone
  delay(500);
  playSound("iph");   // iPhone-style tone
}

****⚙️ Notes****
🧠 Works only on ESP32 (not ESP8266 or AVR)

🎚️ Uses LEDC hardware PWM (default: 2 kHz, 8-bit)

🔌 Default speaker pin: GPIO 25 (configurable)

✅ Tested on ESP32 DevKit, ESP32-S3, and SmartElex boards

📁 Supports loop and stop control for continuous sounds

🧑‍💻 Author

Davinder Handa
🔗 GitHub: @DavinderHanda


