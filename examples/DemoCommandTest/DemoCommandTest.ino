/*

  ---------------------------------------
  Test serial commands for HandaDigitalSpeaker library.
  You can control sounds using Serial Monitor commands:

  🔹 play <name>  → plays a sound once
  🔹 loop <name>  → continuously loops a sound
  🔹 stop         → stops any looping sound

  Example:
  > play ok
  > loop aa
  > stop

  Author: Davinder Handa
  
*/

#include <HandaDigitalSpeaker.h>

void setup() {
  Serial.begin(115200);
  Serial.println("\nHandaDigitalSpeaker Command Test Ready!");
  Serial.println("Commands:");
  Serial.println("  play <sound>");
  Serial.println("  loop <sound>");
  Serial.println("  stop");
  Serial.println("-------------------------------");

  // Initialize speaker pin (default 13)
  initSoundPlayer(13);
}

void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    cmd.toLowerCase();

    if (cmd.startsWith("play ")) {
      String soundName = cmd.substring(5);
      Serial.println("▶ Playing sound once: " + soundName);
      playSound(soundName);
    } 
    else if (cmd.startsWith("loop ")) {
      String soundName = cmd.substring(5);
      Serial.println("🔁 Looping sound: " + soundName);
      playSoundLoop(soundName);
    } 
    else if (cmd == "stop") {
      Serial.println("⏹ Stopping sound...");
      stopSound();
    } 
    else {
      Serial.println("❓ Unknown command. Try: play <name>, loop <name>, stop");
    }
  }

  // (Optional) Do other tasks here
}
