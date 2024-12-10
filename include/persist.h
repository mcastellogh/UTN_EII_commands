#ifndef _persist_h_
#define _persist_h_

#include <Preferences.h>
#include "config.h"
#include "commands.h"


//--Variables default values
#define DEFAULT_KP      1
#define DEFAULT_KI      1
#define DEFAULT_KD      1

//#define PERSIST_DEBUG  //uncomment for debug

void save_config(uint8_t name);
void load_config(void);



#endif