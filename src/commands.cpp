//=======================================================================
// File:                commands.cpp
// Author:              Marcelo Castello (https://github.com/mcastellogh)
// Licence:             GPLV3+
// Version:             1.0.0
// Date:                Diciembre 2024
// Info:                Part of project for Electrónica II
//=======================================================================

#include "commands.h"

String command;
String parameter;
String value;
bool command_serial;

extern Config config;


void read_serial(void){
    StaticJsonDocument<1024> parse_comm;
    const char* comm_;
    const char* param;
    int ind1;
    
    if (Serial.available()>0){
      String comm = Serial.readStringUntil('\n');
      //Serial.println(comm); //echo
      DeserializationError error = deserializeJson(parse_comm, comm);
      if (error) {
          Serial.print(F("Faill to parse Json file. "));
          Serial.println(error.f_str());
          return;
      }
      comm_=parse_comm["method"];
      command=(String)comm_;
      param=parse_comm["params"];
      //--parametos y valores
    
      ind1=((String)param).indexOf(" ");
      parameter=((String)param).substring(0,ind1);
      value=((String)param).substring(ind1+1);
      #ifdef debug_serial_comm
      Serial.print("Serial input:");Serial.println(comm);
      Serial.print("Comando:");Serial.println(comando);
      Serial.print("Parametro:");Serial.println(parametro);
      Serial.print("Valor:");Serial.println(valor);
      #endif
      command_serial=1;
      comm_process();
    }
}


void comm_process(void){
    if (command=="?"){
        Serial.println("Available commands");
        Serial.println("kp <value>");
        Serial.println("ki <value>");
        Serial.println("kd <value>");
        Serial.println("led <on|off>");
    }
    else if (command=="read"){
        Serial.print("kp:");
        Serial.println(config.kp);
        Serial.print("ki:");
        Serial.println(config.kd);
        Serial.print("kd:");
        Serial.println(config.ki);
    }
    else if(command=="kp"){
        config.kp=parameter.toFloat();
        save_config(PID_CONFIG_KP);
        Serial.println("kp:");
        Serial.println(config.kp);
    }
    else if(command=="kd"){
        config.kd=parameter.toFloat();
        save_config(PID_CONFIG_KD);
        Serial.println("kd:");
        Serial.println(config.kd);
    }
    else if(command=="ki"){
        config.ki=parameter.toFloat();
        save_config(PID_CONFIG_KI);
        Serial.println("kd:");
        Serial.println(config.ki);
    }
    else if (command=="led"){
        if(parameter=="on"){
            digitalWrite(ONBOARD_LED_PIN,HIGH);
            Serial.println("Led on");
        }
        if(parameter=="off"){
            digitalWrite(ONBOARD_LED_PIN,LOW);
            Serial.println("Led off");
        }
    }

}