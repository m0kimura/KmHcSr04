//*******1*********2*********3*********4*********4*********5*********6*********7*********8
/* KmHcSr04.h */
#ifndef KMHCSR04_H
#define KMHCSR04_H

#include <Arduino.h>

class KmHcSr04{
  public:
    KmHcSr04(int trig, int echo);
    void begin(int debug);
    int observe();
    float distance();
    bool sense();
    int Range;
    int Speed;
    
  private:
    int       PinTrig;
    int       PinEcho;
    int       Debug;

};

#endif

