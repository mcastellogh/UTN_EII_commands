#ifndef _config_h_
#define _config_h_

//--Includes
#include <Arduino.h>

//--Hardware PINS definitions
#define ONBOARD_LED_PIN             23

//--Software constants
#define SERIAL_BAUDRATE             19200

//--Structures
struct Config {
  float kp;
  float ki;
  float kd;
};

#endif