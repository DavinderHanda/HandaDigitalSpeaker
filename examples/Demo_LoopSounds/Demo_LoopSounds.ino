/*

  Example for HandaDigitalSpeaker Library
  ---------------------------------------
  Demonstrates continuous (looping) sound play
  using playSoundLoop() and stopSound() functions.

  Author: Davinder Handa

  Repository: https://github.com/DavinderHanda/HandaDigitalSpeaker
*/

#include <HandaDigitalSpeaker.h>

void setup() {
  Serial.begin(115200);
  Serial.println("HandaDigitalSpeaker - Continuous Sound Example");

  // Initialize speaker pin (GPIO 13 is default for SmartElex digital speaker)
  initSoundPlayer(13);

  Serial.println("Playing sound 'aa' in loop for 5 seconds...");
  playSoundLoop("aa");  // Start looping sound
}

void loop() {
  static unsigned long startMillis = millis();

  // Stop after 5 seconds
  if (millis() - startMillis >= 5000) {
    stopSound();
    Serial.println("Sound stopped.");
    delay(2000);

    // Restart with another sound
    Serial.println("Playing 'ok' sound once...");
    playSound("ok");
    delay(1000);

    // Loop again another tone
    Serial.println("Looping 'iph' sound...");
    playSoundLoop("iph");
    startMillis = millis(); // Reset timer
  }
}
