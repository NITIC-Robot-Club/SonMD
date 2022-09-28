#include "sonMD.h"
#include "mbed.h"

sonMD::sonMD(
    PinName pin1,
    PinName pin2,
    float   period)
    : pwm1(pin1), pwm2(pin2) {
  pwm1.period(period);
  pwm2.period(period);
  timer.start();
};

void sonMD::move_p1(
    float displacement,
    float target) {
  if (value2 != 0.0) {
    stop();
  } else if (readTime() >= 100) {
    if (value1 > target) {
      value1 = value1 - target > displacement ? value1 - displacement : target;
    } else if (target > value1) {
      value1 = target - value1 > displacement ? value1 + displacement : target;
    }

    pwm1 = trueRate(value1);
    pwm2 = trueRate(value2);
    timer.reset();
  }
};

void sonMD::move_p2(
    float displacement,
    float target) {
  if (value1 != 0.0) {
    stop();
  } else if (readTime() >= 100) {
    if (value2 > target) {
      value2 = value2 - target > displacement ? value2 - displacement : target;
    } else if (target > value2) {
      value2 = target - value2 > displacement ? value2 + displacement : target;
    }
    pwm1 = trueRate(value1);
    pwm2 = trueRate(value2);
    timer.reset();
  }
}

void sonMD::stop() {
  if (readTime() >= 100) {
    value1 = value1 < 0.05 ? 0.0 : value1 - 0.05;
    value2 = value2 < 0.05 ? 0.0 : value2 - 0.05;

    pwm1 = trueRate(value1);
    pwm2 = trueRate(value2);
    timer.reset();
  }
}

unsigned long long int sonMD::readTime() {
  return chrono::duration_cast<chrono::milliseconds>((timer).elapsed_time()).count();
}

float sonMD::trueRate(float rate) {
  if (rate >= 0.538) {
    return float(0.1083 * (1 - rate));
  }
  return float(0.5 - 0.8357 * rate);
}