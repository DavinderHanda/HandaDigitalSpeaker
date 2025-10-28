#include <HandaDigitalSpeaker.h>

void setup() {
  Serial.begin(115200);
  initSoundPlayer(13);  // Initialize speaker pin (change pin if needed)
  delay(500);

  Serial.println("🔊 Handa Digital Sound Demo Ready...");

  // =====================================================
  // ✅ ACTUALLY PLAY THESE (for testing)
  // =====================================================
  playSound("aa");     // Ascending arpeggio (startup)
  delay(800);
  playSound("sdp");    // Short double ping (card scan success)
  delay(800);

  // =====================================================
  // 💡 AVAILABLE SOUND COMMANDS (commented — enable as needed)
  // =====================================================

  // playSound("da");     // Descending arpeggio (shutdown)
  // playSound("tdb");    // Three descending beeps (access denied)
  // playSound("tct");    // Two confirmation tones (admin mode enter/exit)
  // playSound("ud");     // Upward ding (door open)
  // playSound("dd");     // Downward dong (door close)
  // playSound("ursb");   // Urgent short beeps (door stuck)
  // playSound("fahls");  // Fast alternating high/low siren (emergency)
  // playSound("lrs");    // Long rising siren (fire alarm)
  // playSound("sllt");   // Single long low tone (delay warning)
  // playSound("sb");     // Short beep
  // playSound("slb");    // Long beep
  // playSound("vsc");    // Very short click (push button)
  // playSound("iph");    // iPhone-like ping tone
  // playSound("bbm");    // Bubble message tone
  // playSound("wdr");    // Water drop tone
  // playSound("ntf");    // Notification chime
  // playSound("err");    // Error tone
  // playSound("ok");     // Confirmation tone
  // playSound("pow");    // Power-up sequence
  // playSound("pof");    // Power-down sequence
  // playSound("mel");    // Short melody

  Serial.println("✅ Try uncommenting more playSound() lines to test other tones!");
}

void loop() {
  // Nothing here — just run setup once
}

