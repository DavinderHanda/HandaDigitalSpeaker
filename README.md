**🎵 HandaDigitalSpeaker —  ESP32 Digital Sound Library**

A lightweight, fast, and flexible digital sound library for ESP32, made for SmartElex digital speaker modules.
It uses the ESP32’s built-in LEDC PWM hardware to generate clear tone-based sound effects — from system beeps to iPhone-like digital alerts.

**📦 Features******

✅ Over 35 built-in sounds (system + digital + iPhone-style)
✅ One-line play commands (e.g. playSound("ok"))
✅ Continuous play mode — loop a sound until stopped
✅ Simple LED PWM (LEDC) based implementation — no DAC or extra hardware needed
✅ Extremely low CPU usage and non-blocking loop mode

**🛠️ Installation**

Open Arduino IDE → Sketch → Include Library → Manage Libraries

**Search for HandaDigitalSpeaker**

**Click Install**

**or manually:

git clone https://github.com/DavinderHanda/HandaDigitalSpeaker.git**


Copy the folder to:

**Documents/Arduino/libraries/**

**⚡ Quick Start Example**
**#include <HandaDigitalSpeaker.h>**

void setup() {
  Serial.begin(115200);
  initSoundPlayer(13);      // Initialize speaker on GPIO 13
  playSound("ok");          // Play simple OK sound
}

void loop() {
  // Nothing here — just one-time sound
}

**🔁 Continuous Sound Example**

You can now loop a sound indefinitely using playSoundLoop(), and stop it using stopSound().

#include <HandaDigitalSpeaker.h>

void setup() {
  Serial.begin(115200);
  initSoundPlayer(13);

  playSoundLoop("aa");   // Start looping sound (aa pattern)
}

void loop() {
  delay(5000);
  stopSound();           // Stop after 5 seconds
  delay(2000);
}

**🎚️ Functions Overview
Function	Description	Example**
initSoundPlayer(pin)	Initialize sound player on a specific pin	initSoundPlayer(25);
playSound("name")	Play a one-time sound	playSound("ok");
playSoundLoop("name")	Play sound continuously (loop)	playSoundLoop("aa");
stopSound()	Stop continuous sound	stopSound();
ledcWriteTone(pin, freq)	Underlying ESP32 LEDC function	—

**🎵 Available Sounds
Type	Command	Description**
System	aa, da, sdp, tdb, tct, ud, dd	Simple up/down/alert tones
Alerts	ok, err, bsy, rst, tmr, att, slp	Status and warning sounds
Digital	iph, pop, bbl, drp, msg, noti, clk, zap, tch	iPhone-like notification sounds
Utility	sb, slb, dbl, vsc, chn, fahls, wup, sllt	Miscellaneous effects


**🧩 Example — Sound Command Test**
#include <HandaDigitalSpeaker.h>

void setup() {
  Serial.begin(115200);
  initSoundPlayer(25);

  playSound("ok");    // OK tone
  delay(500);
  playSound("err");   // Error tone
  delay(500);
  playSound("iph");   // iPhone-like tone
}

**⚙️ Notes**

Works only on ESP32 (not ESP8266 or AVR).

Uses LEDC channel auto-attach (default 2 kHz, 8-bit resolution).

Speaker pin is configurable; default is GPIO 25.

Tested on ESP32 DevKit, ESP32-S3, and SmartElex boards.

