//*******1*********2*********3*********4*********4*********5*********6*********7*********8
#include <Arduino.h>
#include "KmHcSr04.h"

KmHcSr04::KmHcSr04(int trig, int echo){
  PinTrig=trig; PinEcho=echo;
}

void KmHcSr04::begin(int debug){

  Debug=debug;
  pinMode(PinTrig,OUTPUT);
  pinMode(PinEcho,INPUT);

}

int KmHcSr04::observe(){
  int d;
  digitalWrite(PinTrig,LOW);
  delayMicroseconds(1);
  digitalWrite(PinTrig,HIGH);
  delayMicroseconds(11);
  digitalWrite(PinTrig,LOW);
  d=pulseIn(PinEcho, HIGH); if(Debug){Serial.println("Dulation:"+String(d)+"us");}
  return d;
}

float KmHcSr04::distance(){
  int d=KmHcSr04::observe();
  float rc;
  if(d>0){
    rc=d/2;
    rc=rc*340*100/1000000; // ultrasonic speed is 340m/s = 34000cm/s = 0.034cm/us
    if(Debug){Serial.println("Distance:"+String(rc)+"cm");}
    return rc;
  }
  return 0;
}
