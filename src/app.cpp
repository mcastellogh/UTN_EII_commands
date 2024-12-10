/*********************************************************************************
 * 
 *                       ELECTRONICA II UTN - FRRO                                *
 * 
 * *******************************************************************************/

//===================[File header]================================================
// File:                app.cpp
// Author:              Esp. Ing. Marcelo Castello (https://github.com/mcastellogh)
// Licence:             GPLV3+
// Version:             1.0.0
// Date:                Noviembre 2024
// Info:                Project 'command' for Electrónica II

//====================[Use & storage]============================================
// PCB:                 NodeMCU 
// Plataforma:          ESP32 
// Use:                 serial command
// Folder:              command
// Proyect name:        Command

//====================[ToDo]=====================================================     
//        
//
//
//====================[Bugs]=====================================================     
//     
//                   
//
//====================[Commits]==================================================     
//
// Last commit:
//
//===================[End file header]===========================================


//--Includes
#include "app.h"

//--Local variables


//--Main application (only read serial commands)
void App_loop(void){
    read_serial();
}