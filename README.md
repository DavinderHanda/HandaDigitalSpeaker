# 🎵 Handa Digital Speaker for DigitalSound (v1.0.1)

A simple and fun sound library for **ESP32** that lets you play **pre-defined tones, alerts, and beeps** using the **SmartElex Digital Speaker** via the **LEDC hardware PWM driver**.

---

## 🔊 Features

- ✅ Simple **one-line playback** → `playSound("aa");`
- 🎶 Includes **20+ built-in sound effects**
- 🧠 Human-readable short aliases (like `"aa"` for ascending arpeggio)
- 🔧 Adjustable **speaker pin** using `initSoundPlayer(pin)`
- ⚙️ Works with **LEDC**, no DAC or I2S required
- ⚡ Lightweight and fast for embedded use (ESP32 / ESP32-S3)

---

## 📦 Installation

1. Download this library as a ZIP or from the Arduino Library Manager (search **SmartElexSound**).
2. In Arduino IDE → **Sketch → Include Library → Add .ZIP Library…**
3. Include in your sketch:
   
   #include <HandaDigitalSpeaker.h>

 

   setup(){
initSoundPlayer(13);  //13 is pin or use else.

 playSound("aa");       // Startup ascending arpeggio
  delay(1000);

  playSound("sdp");      // Short double ping
  delay(1000);
   }



cmds are ""  
| Command | Description / Event | Sound Pattern Description       |
| :------ | :------------------ | :------------------------------ |
| `aa`    | Startup             | Ascending arpeggio (C–E–G–C)    |
| `sdp`   | Card Scan Success   | Short double ping               |
| `tdb`   | Access Denied       | Three descending beeps          |
| `admE`  | Admin Mode Enter    | Two confirmation tones (A→C)    |
| `admX`  | Admin Mode Exit     | Two confirmation tones (C→A)    |
| `dO`    | Door Open           | Upward “ding”                   |
| `dC`    | Door Close          | Downward “dong”                 |
| `dS`    | Door Stuck          | Repeated urgent short beeps     |
| `emg`   | Emergency           | Fast alternating high/low siren |
| `fire`  | Fire Alarm          | Long repeating rising siren     |
| `ldw`   | Long Delay Warning  | Single long low tone            |
| `bp`    | Beep                | Single short beep               |
| `lbp`   | Long Beep           | Single long beep                |
| `pb`    | Push Button         | Very short click/beep           |
| `iph`   | iPhone-like Tone    | Soft melodic chime              |
| `bub`   | Bubble Message      | Water-drop bubble sound         |
| `drop`  | Water Drop          | Slow descending tone            |
| `ntf`   | Notification        | Ping-ping confirmation tone     |
| `err`   | Error Alert         | Low-high repeated tone          |
| `ok`    | Confirmation        | Bright double tone              |
| `rdy`   | Ready               | Rising ready tone               |
| `slp`   | Sleep Mode          | Descending fade tone            |
| `wup`   | Wake Up             | Fast ascending beeps            |

