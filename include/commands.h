#ifndef _commands_h_
#define _commands_h_
#include <Arduino.h>
#include <ArduinoJson.h>
#include "config.h"
#include "persist.h"

void read_serial(void);
void comm_process(void);

enum pid_vars_pos{
    PID_CONFIG_KP=1,
    PID_CONFIG_KD,
    PID_CONFIG_KI
};




#endif