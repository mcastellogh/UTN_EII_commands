//=======================================================================
// File:                persist.cpp
// Author:              Marcelo Castello (https://github.com/mcastellogh)
// Licence:             GPLV3+
// Version:             1.0.0
// Date:                Diciembre 2024
// Info:                Part of project for Electrónica II
//=======================================================================

#include "persist.h"

Preferences persist;

extern Config config;

void save_config(uint8_t name){
    persist.begin("pid_config");    //--Open storage area
    switch(name){
        case PID_CONFIG_KP:
            persist.putFloat("kp",config.kp);
            break;
        case PID_CONFIG_KI:
            persist.putFloat("ki",config.ki);
            break;
        case PID_CONFIG_KD:
            persist.putFloat("kd",config.kd);
            break;
    }
    persist.end();                  //--Close storage area
    //--Verify results
    #ifdef PERSIST_DEBUG
    Serial.println("PID config saved:");
    Serial.println(config.kp);
    Serial.println(config.ki);
    Serial.println(config.kd);
    #endif
}

void load_config(void){
    //--Open storage area
    persist.begin("pid_config");
    config.kp=persist.getFloat("kp",DEFAULT_KP);
    config.ki=persist.getFloat("ki",DEFAULT_KI);
    config.kd=persist.getFloat("kd",DEFAULT_KD);
    //--Close storage area
    persist.end();

    //--Print config values
    Serial.println("Config readed:");
    Serial.print("Kp: ");
    Serial.println(config.kp);
    Serial.print("Ki: ");
    Serial.println(config.ki);
    Serial.print("Kd: ");
    Serial.println(config.kd);
}