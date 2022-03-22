/*

Pranav Tyagi and Tayeb Benjelloun
ACS337 Robotics Systems, Group 1H
Practical assignment 

Purpose:
Task 1 - Implementing a test and control strategy for the robot:
    1. To explore an environement with obstacles 
    2. To avoid any collissions with the environment boundry and obstacels 



*/


// Relevant header files 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ch.h"
#include "hal.h"
#include "memory_protection.h"
#include <main.h>
#include <time.h>

// Motors 
#include "motors.h"

// Proximity sensors 
#include "sensors/proximity.h"

// Defining the interprocess communication for sensors 
messagebus_t bus;
MUTEX_DECL(bus_lock);
CONDVAR_DECL(bus_condvar);

// UART
#include "epuck1x/uart/e_uart_char.h"
#include "stdio.h"
#include "serial_comm.h"

/**************************************
         Functions declaration 
 **************************************/

void Turn_right();        // Function to turn left 
void Turn_left();         // Function to turn right 
void reverse();           // Function to reverse 
void forward();           // Function to move forward
void prox_vals();         // Function to get the proximity sensors data
void Turn(int sensor);    // Function to determine the boundry or obstacle 



int main(void)
{

    halInit();
    chSysInit();
    mpu_init();

    // Iniatialising UART1 channel 
    serial_start(); 

    // Initiating communication 
    messagebus_init(&bus, &bus_lock, &bus_condvar);

    //Starting the proximity measurement module 
    proximity_start();

    // Calibrating proximity sensors 
    calibrate_ir();

    // Ambient light values 
    int amb_light = get_ambient_light(0);       /* Is this necessary???????? */

    // Initialising motors 
    motors_init();

    // Setting sensor threshold values 
    int Prox_thresh = 1000; 

    // Time for spinning while loop 
    time_t endwait;
    int seconds = 5;

    endwait = time(NULL) + seconds;
    // Spinning e-puck for a specefied amount of time 
    while (time(NULL) < endwait)
    {
    	left_motor_set_speed(-1000);
    	right_motor_set_speed(1000);
    }


    // char str[100];
    // int str_length;
    // int prox;
    // int cal_prox;
    // int x;
    // int y;

    /* Infinite loop. */
    while (1) {
    	
    	//waits half a second
        chThdSleepMilliseconds(500);

        // Proximity sensor values 
        prox_vals();

        //str_length = sprintf(str, "Hello World\n");
        e_send_uart1_char(str, x);
    }
}



#define STACK_CHK_GUARD 0xe2dee396
uintptr_t __stack_chk_guard = STACK_CHK_GUARD;

void __stack_chk_fail(void)
{
    chSysHalt("Stack smashing detected");
}



/******************************************
        Function definations 
*******************************************/


void Turn_right()
{

}     

void Turn_left()
{

}   

void reverse()
{

}   

void forward()
{

}     

void prox_vals()
{
	// For loop to get the proximity of all sensors 
	for (int i = 0; i <= 7; i++)
	{
		int prox = get_prox(i);
		int cal_prox = get_calibrated_prox(i);
	}
} 


void Turn(int sensor)
{
	switch(sensor)
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
	}
}


 
// Test function 
void turn_test(int sensor, int cal_prox)
{
	if ()
	{
		
	}
}








