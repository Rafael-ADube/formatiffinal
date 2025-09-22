#include <Arduino.h>
#include <FastLED.h>
#include <MicroOscSlip.h>

#define MA_Lecture_BOUTON 39
#define MA_BROCHE_ANGLE 32
#define LED_PIN 27

CRGB couleur;

MicroOscSlip<128> monOsc(&Serial);

void setup() {
  Serial.begin(115200);
  pinMode(MA_Lecture_BOUTON, INPUT);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(&couleur, 1);


  couleur = CRGB(250, 250, 250);
  FastLED.show();
}

void loop() {
  int maLectureBouton = digitalRead(MA_Lecture_BOUTON);
  int mabrocheAngle = analogRead(MA_BROCHE_ANGLE);

 
  monOsc.sendInt("/but", maLectureBouton);
  monOsc.sendInt("/pot", mabrocheAngle);

  if (mabrocheAngle > 2048) {
    couleur = CRGB(0, 0, 255);     
  } else {
    couleur = CRGB(255, 255, 0);   
  }

  FastLED.show();
  delay(50);
}
