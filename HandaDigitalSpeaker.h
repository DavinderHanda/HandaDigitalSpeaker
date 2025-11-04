// ============================================================
// Digital Sound Library for ESP32
// Author: Davinder Handa
// ============================================================
#ifndef HandaDigitalSpeaker_H
#define HandaDigitalSpeaker_H

#include <Arduino.h>
#include "esp32-hal-ledc.h"

static int _SPEAKER_PIN = -1;

// ---------- Base Tone Helpers ----------
inline void _tone(uint32_t freq, uint32_t ms) {
  if (_SPEAKER_PIN < 0) return;
  ledcWriteTone(_SPEAKER_PIN, freq);
  delay(ms);
  ledcWriteTone(_SPEAKER_PIN, 0);
  delay(12);
}

inline void _sweep(uint32_t f1, uint32_t f2, uint16_t step, uint16_t spd) {
  if (_SPEAKER_PIN < 0) return;
  if (f1 < f2)
    for (uint32_t f = f1; f <= f2; f += step) {
      ledcWriteTone(_SPEAKER_PIN, f);
      delay(spd);
    }
  else
    for (uint32_t f = f1; f >= f2; f -= step) {
      ledcWriteTone(_SPEAKER_PIN, f);
      delay(spd);
      if (f < step) break;
    }
  ledcWriteTone(_SPEAKER_PIN, 0);
}

// ---------- Basic / System Sounds ----------
inline void s_aa() { _tone(523,100); _tone(659,100); _tone(784,100); _tone(1046,180); }
inline void s_da() { _tone(1046,100); _tone(784,100); _tone(659,100); _tone(523,180); }
inline void s_sdp() { _tone(784,80); _tone(1046,120); }
inline void s_tdb() { _tone(600,120); _tone(480,120); _tone(360,180); }
inline void s_tct() { _tone(880,180); _tone(1046,240); }
inline void s_ud() { _tone(523,100); _tone(659,100); _tone(784,200); }
inline void s_dd() { _tone(784,100); _tone(659,100); _tone(523,200); }
inline void s_ursb() { for(int i=0;i<4;i++) _tone(800,80); }
inline void s_fahls() { for(int i=0;i<6;i++){ _tone(800,120); _tone(1200,120);} }
inline void s_lrs() { for(int i=0;i<3;i++){ _sweep(500,1500,50,6);} ledcWriteTone(_SPEAKER_PIN,0); }
inline void s_sllt() { _tone(400,700); }
inline void s_sb() { _tone(1000,80); }
inline void s_slb() { _tone(1000,400); }
inline void s_vsc() { _tone(1600,50); }
inline void s_dbl() { _tone(400,100); delay(100); _tone(400,100); }
inline void s_bhi() { _tone(1600,100); delay(50); _tone(1800,150); }
inline void s_chn() { _tone(1000,80); _tone(1200,80); _tone(1400,80); }
inline void s_err() { for(int i=0;i<3;i++){ _tone(300,150); delay(50);} }
inline void s_ok() { _tone(1200,80); _tone(1500,120); }
inline void s_bsy() { for(int i=0;i<2;i++){ _tone(600,120); delay(80);} }
inline void s_rst() { _tone(523,100); _tone(659,100); _tone(784,100); _tone(1046,100); _tone(784,150); }
inline void s_wup() { _tone(659,80); _tone(784,100); _tone(988,120); }
inline void s_slp() { _tone(523,200); _tone(392,200); }
inline void s_tmr() { _tone(1000,100); delay(100); _tone(1500,150); delay(100); _tone(2000,200); }
inline void s_att() { for(int i=0;i<5;i++){ _tone(800,70); delay(70);} }

// ---------- Premium Digital / iPhone-like ----------
inline void s_iph() { _tone(1200,70); delay(30); _tone(1600,90); }
inline void s_pop() { _tone(700,40); delay(20); _tone(900,60); }
inline void s_bbl() { _sweep(600,900,40,10); }
inline void s_drp() { _sweep(1200,700,30,10); }
inline void s_msg() { _tone(880,80); delay(50); _tone(1320,120); }
inline void s_noti() { _tone(1000,70); delay(30); _tone(1500,90); }
inline void s_clk() { _tone(900,30); }
inline void s_swp() { _sweep(500,1500,80,6); }
inline void s_swd() { _sweep(1500,500,80,6); }
inline void s_wtr() { for(int i=0;i<3;i++){ _sweep(600,900,20,8); delay(50);} }
inline void s_brz() { _sweep(300,600,10,12); }
inline void s_zap() { for(int i=0;i<3;i++){ _sweep(1500,2500,100,4); delay(30);} }
inline void s_tch() { _tone(1200,30); delay(15); _tone(900,30); }

// ---------- Melodic / Musical Sequences (20 New Tunes) ----------

// --- Short System Melodies ---
inline void s_jingle1() { _tone(523,100); _tone(659,100); _tone(784,150); _tone(1046,200); }
inline void s_jingle2() { _tone(784,100); _tone(988,100); _tone(1175,150); _tone(1568,200); }
inline void s_jingle3() { _tone(392,100); _tone(440,100); _tone(494,150); _tone(523,200); }
inline void s_start1() { _tone(523,100); delay(40); _tone(659,100); delay(40); _tone(784,150); delay(60); _tone(1046,200); }
inline void s_start2() { _tone(659,100); delay(40); _tone(784,100); delay(40); _tone(988,150); delay(40); _tone(1319,200); }
inline void s_end1() { _tone(1319,100); delay(40); _tone(988,100); delay(40); _tone(784,120); delay(40); _tone(523,150); }
inline void s_end2() { _tone(880,100); delay(40); _tone(698,100); delay(40); _tone(587,120); delay(40); _tone(440,150); }
inline void s_ready1() { _tone(523,80); delay(30); _tone(659,80); delay(30); _tone(880,120); delay(30); _tone(1046,150); }
inline void s_ready2() { _tone(440,100); delay(20); _tone(554,100); delay(20); _tone(659,150); delay(20); _tone(880,180); }

// --- Success / Notification ---
inline void s_success1() { _tone(784,100); _tone(988,100); _tone(1319,150); _tone(1760,180); }
inline void s_success2() { _tone(660,80); delay(30); _tone(880,100); delay(30); _tone(990,150); delay(30); _tone(1320,180); }
inline void s_notify1() { _tone(988,80); delay(40); _tone(1319,120); delay(40); _tone(1760,150); }
inline void s_notify2() { _tone(659,60); delay(30); _tone(880,100); delay(30); _tone(1046,150); delay(30); _tone(1319,180); }
inline void s_ok1() { _tone(1000,80); delay(30); _tone(1300,100); delay(30); _tone(1600,150); }
inline void s_ok2() { _tone(600,80); delay(30); _tone(900,100); delay(30); _tone(1200,150); delay(30); _tone(1600,180); }

// --- Fun / Classic Game Tunes ---
inline void s_coin1() { _tone(1046,100); delay(20); _tone(1568,100); delay(20); _tone(2093,150); }
inline void s_coin2() { _tone(880,80); delay(20); _tone(1319,100); delay(20); _tone(1760,120); }
inline void s_win1() { _tone(523,100); delay(40); _tone(659,100); delay(40); _tone(784,120); delay(40); _tone(1046,160); delay(40); _tone(1319,180); }
inline void s_win2() { _tone(392,80); delay(40); _tone(494,100); delay(40); _tone(587,100); delay(40); _tone(784,120); delay(40); _tone(988,150); }
inline void s_fail1() { _tone(784,120); delay(40); _tone(659,120); delay(40); _tone(523,180); delay(40); _tone(392,200); }
// ---------- Short, Crisp Sound Effects (20 Total) ----------

// --- System / Startup ---
inline void s_sound1() { _tone(523,80); _tone(659,100); _tone(784,120); }        // Power-on
inline void s_sound2() { _tone(440,80); _tone(554,80); _tone(880,120); }         // Boot OK
inline void s_sound3() { _tone(784,80); delay(50); _tone(1046,100); }            // Ready
inline void s_sound4() { _tone(1046,80); _tone(880,80); _tone(784,100); }        // Shutdown

// --- Success / Confirm ---
inline void s_sound5() { _tone(880,80); _tone(1046,100); }                       // Success
inline void s_sound6() { _tone(784,80); delay(40); _tone(988,120); }             // Confirm
inline void s_sound7() { _tone(1046,60); _tone(1318,80); _tone(1568,100); }      // Task Done
inline void s_sound8() { _tone(988,100); delay(30); _tone(1318,100); }           // Complete

// --- Warning / Error ---
inline void s_sound9() { _tone(523,150); delay(50); _tone(330,180); }            // Error
inline void s_sound10(){ for(int i=0;i<2;i++){ _tone(600,80); delay(60); _tone(400,80); delay(60);} } // Warning
inline void s_sound11(){ _tone(784,120); delay(40); _tone(440,150); }            // Alert Drop
inline void s_sound12(){ _sweep(2000,600,10,6); }                                // Danger sweep

// --- Key / Click / Touch ---
inline void s_sound13(){ _tone(880,30); delay(30); _tone(988,40); }              // Button tap
inline void s_sound14(){ _tone(988,40); delay(20); _tone(1318,40); }             // Key press
inline void s_sound15(){ _tone(659,40); delay(20); _tone(784,50); }              // Short blip
inline void s_sound16(){ _tone(1046,40); delay(20); _tone(1318,50); }            // Fast tick

// --- Door / Lock / Motion ---
inline void s_sound17(){ _tone(659,80); delay(40); _tone(523,100); }             // Lock
inline void s_sound18(){ _tone(440,80); delay(40); _tone(659,120); }             // Unlock
inline void s_sound19(){ _sweep(300,1200,10,5); }                                // Door motion
inline void s_sound20(){ _sweep(1200,400,10,5); }                                // Reverse motion


// ---------- Command Parser ----------
inline void playSound(const String &cmd) {
  String s = cmd; s.toLowerCase();
  if(s=="aa")s_aa();else if(s=="da")s_da();else if(s=="sdp")s_sdp();else if(s=="tdb")s_tdb();
  else if(s=="tct")s_tct();else if(s=="ud")s_ud();else if(s=="dd")s_dd();else if(s=="ursb")s_ursb();
  else if(s=="fahls")s_fahls();else if(s=="lrs")s_lrs();else if(s=="sllt")s_sllt();else if(s=="sb")s_sb();
  else if(s=="slb")s_slb();else if(s=="vsc")s_vsc();else if(s=="dbl")s_dbl();else if(s=="bhi")s_bhi();
  else if(s=="chn")s_chn();else if(s=="err")s_err();else if(s=="ok")s_ok();else if(s=="bsy")s_bsy();
  else if(s=="rst")s_rst();else if(s=="wup")s_wup();else if(s=="slp")s_slp();else if(s=="tmr")s_tmr();
  else if(s=="att")s_att();else if(s=="iph")s_iph();else if(s=="pop")s_pop();else if(s=="bbl")s_bbl();
  else if(s=="drp")s_drp();else if(s=="msg")s_msg();else if(s=="noti")s_noti();else if(s=="clk")s_clk();
  else if(s=="swp")s_swp();else if(s=="swd")s_swd();else if(s=="wtr")s_wtr();else if(s=="brz")s_brz();
  else if(s=="zap")s_zap();else if(s=="tch")s_tch();
  else if(s=="jingle1")s_jingle1();else if(s=="jingle2")s_jingle2();else if(s=="jingle3")s_jingle3();
  else if(s=="start1")s_start1();else if(s=="start2")s_start2();else if(s=="end1")s_end1();else if(s=="end2")s_end2();
  else if(s=="ready1")s_ready1();else if(s=="ready2")s_ready2();else if(s=="success1")s_success1();else if(s=="success2")s_success2();
  else if(s=="notify1")s_notify1();else if(s=="notify2")s_notify2();else if(s=="ok1")s_ok1();else if(s=="ok2")s_ok2();
  else if(s=="coin1")s_coin1();else if(s=="coin2")s_coin2();else if(s=="win1")s_win1();else if(s=="win2")s_win2();
  else if(s=="fail1")s_fail1();
  else if(s=="sound1")s_sound1();else if(s=="sound2")s_sound2();else if(s=="sound3")s_sound3();else if(s=="sound4")s_sound4();
  else if(s=="sound5")s_sound5();else if(s=="sound6")s_sound6();else if(s=="sound7")s_sound7();else if(s=="sound8")s_sound8();
  else if(s=="sound9")s_sound9();else if(s=="sound10")s_sound10();else if(s=="sound11")s_sound11();else if(s=="sound12")s_sound12();
  else if(s=="sound13")s_sound13();else if(s=="sound14")s_sound14();else if(s=="sound15")s_sound15();else if(s=="sound16")s_sound16();
  else if(s=="sound17")s_sound17();else if(s=="sound18")s_sound18();else if(s=="sound19")s_sound19();else if(s=="sound20")s_sound20();
  else Serial.println("Handa Digital Speakers | Unknown sound: " + cmd);
}

// ---------- Continuous Sound Play Control ----------
volatile bool _isPlaying = false;
TaskHandle_t _soundTask = NULL;
String _currentSound = "";

// Background task for looping sound
void _soundLoopTask(void *param) {
  String cmd = *((String *)param);
  delete (String *)param;
  while (_isPlaying) {
    playSound(cmd);
    delay(100); // small gap between loops
  }
  vTaskDelete(NULL);
}

// Start continuous playback
inline void playSoundLoop(const String &cmd) {
  if (_isPlaying) return; // already playing
  _isPlaying = true;
  _currentSound = cmd;
  String *param = new String(cmd);
  xTaskCreatePinnedToCore(_soundLoopTask, "SoundLoopTask", 4096, param, 1, &_soundTask, 1);
  //Serial.println("Looping sound: " + cmd);
}

// Stop continuous playback
inline void stopSound() {
  _isPlaying = false;
  if (_soundTask != NULL) {
    vTaskDelete(_soundTask);
    _soundTask = NULL;
  }
  ledcWriteTone(_SPEAKER_PIN, 0);
  //Serial.println("Sound stopped.");
}

// ---------- Initialization ----------
inline void initSoundPlayer(int pin = 25) {
  _SPEAKER_PIN = pin;
  ledcAttach(_SPEAKER_PIN, 2000, 8);
  delay(10);
  Serial.println("Handa Digital Speaker - ready on pin " + String(_SPEAKER_PIN));
}

#endif
