#ifndef SONMD_H
#define SONMD_H

#include "mbed.h"

class sonMD {
private:
  Timer     timer;
  PwmOut    pwm1, pwm2;
  float     value1 = 0.0, value2 = 0.0;
  int       hote;
  const int STOP = 2;

  unsigned long long int readTime();
  float                  trueRate(float rate);

public:
  const int   CW = 0, CCW = 1;
  const float one_second = 0.1;
  const float five_secound = 0.02;

  sonMD(
      PinName pin1,
      PinName pin2,
      float   period);

  void move_p1(
      float displacement,
      float target);

  void move_p2(
      float displacement,
      float target);

  void stop();
};

#endif