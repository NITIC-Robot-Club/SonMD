#include "mbed.h"
#include "sonMD.h"

sonMD::sonMD(
    PinName pin1,
    PinName pin2) : pwm1(pin1), pwm2(pin2)
{
  timer.reset();
};

void sonMD::move_p1(
    int type,
    float value,
    float target)
{
  if (value2 != 0.0)
  {
    stop();
  }
  else if (readTime() >= 100)
  {
    if (value1 > target)
    {
      if (value1 - target > value)
      {
        value1 = value1 - value;
      }
      else
      {
        value1 = target;
      }
    }
    else if (value1 < target)
    {
      if (target - value1 < value)
      {
        value1 = value1 + target;
      }
      else
      {
        value1 = target;
      }
    }
    pwm1 = value1;
    pwm2 = value2;
    timer.reset();
  }
};

void sonMD::move_p2(
    int type,
    float value,
    float target)
{
  if (value1 != 0.0)
  {
    stop();
  }
  else if (readTime() >= 1000)
  {
    if (value2 > target)
    {
      if (value2 - target > value)
      {
        value2 = value2 - value;
      }
      else
      {
        value2 = target;
      }
    }
    else if (value2 < target)
    {
      if (target - value2 < value)
      {
        value2 = value2 + target;
      }
      else
      {
        value2 = target;
      }
    }
    pwm1 = value1;
    pwm2 = value2;
    timer.reset();
  }
}

void sonMD::stop()
{
  if (readTime() >= 100)
  {
    if (value1 != 0.0)
    {
      value1 = value1 < 0.1 ? 0.0 : value1 - 0.1;
    }
    if (value2 != 0.0)
    {
      value2 = value2 < 0.1 ? 0.0 : value2 - 0.1;
    }

    pwm1 = value1;
    pwm2 = value2;
    timer.reset();
  }
}

unsigned long long int sonMD::readTime()
{
  return chrono::duration_cast<chrono::milliseconds>((timer).elapsed_time()).count();
}