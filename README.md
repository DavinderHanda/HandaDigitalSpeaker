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

cmds are ""  
| Command | Description                                     |
| :-----: | ----------------------------------------------- |
|   `aa`  | Ascending arpeggio *(startup sound)*            |
|   `da`  | Descending arpeggio *(shutdown)*                |
|  `sdp`  | Short double ping *(success beep)*              |
|  `tdb`  | Triple descending beep *(error alert)*          |
|  `tct`  | Two-tone complete sound *(task done)*           |
|   `ud`  | Upward tone *(progress start)*                  |
|   `dd`  | Downward tone *(progress end)*                  |
|  `ursb` | USB-like quick repeat beeps *(connect sound)*   |
| `fahls` | Fast alternating high-low beeps *(alarm alert)* |
|  `lrs`  | Long rising sweep *(emergency / siren)*         |
|  `sllt` | Slow long tone *(door stuck or waiting)*        |
|   `sb`  | Short beep *(button press)*                     |
|  `slb`  | Slow long beep *(warning)*                      |
|  `vsc`  | Very short click *(touch feedback)*             |
|  `dbl`  | Double low beep *(info alert)*                  |
|  `bhi`  | Double high beep *(positive action)*            |
|  `chn`  | Three ascending chime tones *(welcome tone)*    |
|  `err`  | Triple buzz *(error or denied access)*          |
|   `ok`  | Success tone *(access granted)*                 |
|  `bsy`  | Busy tone *(processing)*                        |
|  `rst`  | Reset melody *(system reboot)*                  |
|  `wup`  | Wake-up tone *(ready state)*                    |
|  `slp`  | Sleep tone *(system idle)*                      |
|  `tmr`  | Timer alert *(timeout or delay)*                |
|  `att`  | Attention tone *(5 short beeps)*                |


| Command | Description                        |
| :-----: | ---------------------------------- |
|  `iph`  | iPhone-style alert tone            |
|  `pop`  | Soft pop sound *(UI tap)*          |
|  `bbl`  | Bubble rise tone *(bloop effect)*  |
|  `drp`  | Water drop tone                    |
|  `msg`  | Message notification               |
|  `noti` | Notification alert *(modern tone)* |
|  `clk`  | Click tick tone *(key press)*      |
|  `swp`  | Sweep upward *(open animation)*    |
|  `swd`  | Sweep downward *(close animation)* |
|  `wtr`  | Water drip bubbles *(fun effect)*  |
|  `brz`  | Breeze whoosh *(soft ambient)*     |
|  `zap`  | Electric zap *(power tone)*        |
|  `tch`  | Touch blip *(fast tap)*            |
