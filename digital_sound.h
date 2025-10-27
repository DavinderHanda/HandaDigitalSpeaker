// ============================================================
// Digital Sound Library for ESP32
// Author: Davinder Handa
// ============================================================
#ifndef DIGITAL_SOUND_H
#define DIGITAL_SOUND_H


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
  if (f1 < f2) for (uint32_t f=f1; f<=f2; f+=step){ ledcWriteTone(_SPEAKER_PIN,f); delay(spd); }
  else for (uint32_t f=f1; f>=f2; f-=step){ ledcWriteTone(_SPEAKER_PIN,f); delay(spd); if (f<step) break; }
  ledcWriteTone(_SPEAKER_PIN,0);
}

// ---------- Basic / System Sounds ----------
inline void s_aa(){_tone(523,100);_tone(659,100);_tone(784,100);_tone(1046,180);}
inline void s_da(){_tone(1046,100);_tone(784,100);_tone(659,100);_tone(523,180);}
inline void s_sdp(){_tone(784,80);_tone(1046,120);}
inline void s_tdb(){_tone(600,120);_tone(480,120);_tone(360,180);}
inline void s_tct(){_tone(880,180);_tone(1046,240);}
inline void s_ud(){_tone(523,100);_tone(659,100);_tone(784,200);}
inline void s_dd(){_tone(784,100);_tone(659,100);_tone(523,200);}
inline void s_ursb(){for(int i=0;i<4;i++)_tone(800,80);}
inline void s_fahls(){for(int i=0;i<6;i++){_tone(800,120);_tone(1200,120);}}
inline void s_lrs(){for(int i=0;i<3;i++){_sweep(500,1500,50,6);}ledcWriteTone(_SPEAKER_PIN,0);}
inline void s_sllt(){_tone(400,700);}
inline void s_sb(){_tone(1000,80);}
inline void s_slb(){_tone(1000,400);}
inline void s_vsc(){_tone(1600,50);}
inline void s_dbl(){_tone(400,100);delay(100);_tone(400,100);}
inline void s_bhi(){_tone(1600,100);delay(50);_tone(1800,150);}
inline void s_chn(){_tone(1000,80);_tone(1200,80);_tone(1400,80);}
inline void s_err(){for(int i=0;i<3;i++){_tone(300,150);delay(50);}}
inline void s_ok(){_tone(1200,80);_tone(1500,120);}
inline void s_bsy(){for(int i=0;i<2;i++){_tone(600,120);delay(80);}}
inline void s_rst(){_tone(523,100);_tone(659,100);_tone(784,100);_tone(1046,100);_tone(784,150);}
inline void s_wup(){_tone(659,80);_tone(784,100);_tone(988,120);}
inline void s_slp(){_tone(523,200);_tone(392,200);}
inline void s_tmr(){_tone(1000,100);delay(100);_tone(1500,150);delay(100);_tone(2000,200);}
inline void s_att(){for(int i=0;i<5;i++){_tone(800,70);delay(70);}}

// ---------- Premium Digital / iPhone-like ----------
inline void s_iph(){_tone(1200,70);delay(30);_tone(1600,90);}
inline void s_pop(){_tone(700,40);delay(20);_tone(900,60);}
inline void s_bbl(){_sweep(600,900,40,10);}
inline void s_drp(){_sweep(1200,700,30,10);}
inline void s_msg(){_tone(880,80);delay(50);_tone(1320,120);}
inline void s_noti(){_tone(1000,70);delay(30);_tone(1500,90);}
inline void s_clk(){_tone(900,30);}
inline void s_swp(){_sweep(500,1500,80,6);}
inline void s_swd(){_sweep(1500,500,80,6);}
inline void s_wtr(){for(int i=0;i<3;i++){_sweep(600,900,20,8);delay(50);}}
inline void s_brz(){_sweep(300,600,10,12);}
inline void s_zap(){for(int i=0;i<3;i++){_sweep(1500,2500,100,4);delay(30);}}
inline void s_tch(){_tone(1200,30);delay(15);_tone(900,30);}

// ---------- Command Parser ----------
inline void playSound(const String &cmd){
  String s=cmd; s.toLowerCase();
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
  else Serial.println("Handa Digital Speakers | Unknown sound: " + cmd);
}

// ---------- Initialization ----------
inline void initSoundPlayer(int pin=25){
  _SPEAKER_PIN=pin;
  ledcAttach(_SPEAKER_PIN,2000,8);
  delay(10);
  Serial.println("Handa Digital Speaker- ready on pin " + String(_SPEAKER_PIN));
}

#endif
