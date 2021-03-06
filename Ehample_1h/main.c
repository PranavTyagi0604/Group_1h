///*
//
//Pranav Tyagi and Tayeb Benjelloun
//ACS337 Robotics Systems, Group 1H
//Practical assignment
//
//Purpose:
//Task 1 - Implementing a test and control strategy for the robot:
//    1. To explore an environement with obstacles
//    2. To avoid any collissions with the environment boundry and obstacels
//
//
//
//*/
//
//
//// Relevant header files
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//#include "ch.h"
//#include "hal.h"
//#include "memory_protection.h"
//#include <main.h>
//#include <time.h>
//#include "chprintf.h"
//#include "usbcfg.h"
//
//// Motors
//#include "motors.h"
//
//// Proximity sensors
//#include "sensors/proximity.h"
//
//// Defining the interprocess communication for sensors
//messagebus_t bus;
//MUTEX_DECL(bus_lock);
//CONDVAR_DECL(bus_condvar);
//
//// UART
//#include "epuck1x/uart/e_uart_char.h"
//#include "stdio.h"
//#include "serial_comm.h"
//
///**************************************
//         Functions declaration
// **************************************/
//
//void Turn_right();        // Function to turn left
//void Turn_left();         // Function to turn right
//void reverse();           // Function to reverse
//void forward();           // Function to move forward
//void Around();            // Function to turn around
//void prox_vals();         // Function to get the proximity sensors data
////void Turn(int sensor);    // Function to determine the boundry or obstacle
//void turn_test(int Prox_thresh);
//void stop();              // Function to stop the robot
//
//// Array for storing proximity values
//int Prox_vals[8];
//
//int main(void)
//{
//
//    halInit();
//    chSysInit();
//    mpu_init();
//
//    usb_start();
//    // Iniatialising UART1 channel
//    serial_start();
//
//    // Initiating communication
//    messagebus_init(&bus, &bus_lock, &bus_condvar);
//
//    //Starting the proximity measurement module
//    proximity_start();
//
//    // Calibrating proximity sensors
//    calibrate_ir();
//
//    // Ambient light values
//    int amb_light = get_ambient_light(0);       /* Is this necessary???????? */
//
//    // Initialising motors
//    motors_init();
//
//    // Setting sensor threshold values
//    int Prox_thresh = 160;
//
//
//
//    // Time for spinning while loop
//   // time_t endwait;
// //   int seconds = 5;
//
////    endwait = time(NULL) + seconds;
////    // Spinning e-puck for a specefied amount of time
////    while (time(NULL) < endwait)
////    {
////    	left_motor_set_speed(-1000);
////    	right_motor_set_speed(1000);
////    }
//    left_motor_set_speed(-1000);
//   	right_motor_set_speed(1000);
//    chThdSleepMilliseconds(5000);
//    stop();
//
//    // char str[100];
//    // int str_length;
//    // int prox;
//    // int cal_prox;
//    // int x;
//    // int y;
//
//    // Infinite while loop
//    while (1) {
//
//    	//waits half a second
//        chThdSleepMilliseconds(500);
//
//        // Proximity sensor values
//
//        prox_vals();
//        //forward();
//        //chThdSleepMilliseconds(1000);
//        //Turn_right();
//        turn_test(Prox_thresh);
//
//        //str_length = sprintf(str, "Hello World\n");
//        //e_send_uart1_char(str, x);
//    }
//}
//
//
//
//#define STACK_CHK_GUARD 0xe2dee396
//uintptr_t __stack_chk_guard = STACK_CHK_GUARD;
//
//void __stack_chk_fail(void)
//{
//    chSysHalt("Stack smashing detected");
//}
//
//
//
///******************************************
//        Function definations
//*******************************************/
//
//void stop()
//{
//	left_motor_set_speed(0);
//	right_motor_set_speed(0);
//}
//
//void Turn_right()
//{
//	left_motor_set_speed(500);
//	right_motor_set_speed(-500);
//}
//
//void Turn_left()
//{
//	left_motor_set_speed(-500);
//	right_motor_set_speed(500);
//}
//
//void reverse()
//{
//	left_motor_set_speed(-600);
//	right_motor_set_speed(-600);
//}
//
//void forward()
//{
//	left_motor_set_speed(700);
//	right_motor_set_speed(700);
//}
//
//void Around()
//{
//	stop();
//	Turn_left();
//	stop();
//	Turn_left();
//	forward();
//}
//
//void prox_vals()
//{
//	// For loop to get the proximity of all sensors
//	for (int i = 0; i <= 7; i++)
//	{
//		//int prox = get_prox(i);
//		//int cal_prox = get_calibrated_prox(i);
//
//		// Passing the prox vals to array
//		Prox_vals[i] = get_prox(i);
////		if (SDU1.config->usbp->state == USB_ACTIVE) {
////		chprintf((BaseSequentialStream *)&SDU1, "%4d,", Prox_vals[i]);
//
//
//	}
//}
//
//
////void Turn(int sensor)
////{
////	switch(sensor)
////	{
////		case 0:
////		case 1:
////		case 2:
////		case 3:
////		case 4:
////		case 5:
////		case 6:
////		case 7:
////	}
////}
//
//
//
//// Test function
////void turn_test(int Prox_thresh)									// need to add thresh condition
////{
////	if((Prox_vals[0] <= Prox_thresh) && (Prox_vals[1] <= Prox_thresh) && (Prox_vals[2] <= Prox_thresh))
////	{
////		Turn_left();
////		forward();
////
////	}else if ((Prox_vals[5] <= Prox_thresh) || (Prox_vals[6] <= Prox_thresh) || (Prox_vals[7] <= Prox_thresh))
////	{
////		Turn_right();
////		forward();
////
////	}else if ((Prox_vals[0] <= Prox_thresh) && (Prox_vals[7] <= Prox_thresh))
////	{
////
////		Around();
////		forward();
////	}else{ forward(); }
////}
//
//
//
//void turn_test(int Prox_thresh)									// need to add thresh condition
//{
//	if((Prox_vals[0] >= Prox_thresh) && (Prox_vals[1] >= 80))
//	{
//		stop();
//		chThdSleepMilliseconds(500);
//		//reverse();
//		//stop();
//		Turn_left();
//		chThdSleepMilliseconds(500);
//		forward();
//
//	}else if ((Prox_vals[6] >= 400) && (Prox_vals[7] >= 160))
//	{
//		stop();
//		//chThdSleepMilliseconds(500);
//		//reverse();
//		//stop();
//		Turn_right();
//		chThdSleepMilliseconds(500);
//		forward();
//
//	}else if ((Prox_vals[0] >= Prox_thresh) && (Prox_vals[7] >= Prox_thresh))
//	{
//		stop();
//		chThdSleepMilliseconds(500);
//		reverse();
//		chThdSleepMilliseconds(500);
//		Turn_right();
//	}else if(Prox_vals[2] >= Prox_thresh)
//	{
//		//stop();
//		chThdSleepMilliseconds(500);
//		Turn_left();
//		chThdSleepMilliseconds(200);
//		forward();
//	}else if(Prox_vals[5] >= Prox_thresh)
//	{
//		//stop();
//		chThdSleepMilliseconds(500);
//		Turn_right();
//		chThdSleepMilliseconds(200);
//		forward();
//	}
//	else{ forward(); }
//}



























/******************************************************************************************************************
 *
 *
 *
 *
 *            TASK 2
 *
 *
 *
 *
 */
/*

Pranav Tyagi and Tayeb Benjelloun
ACS337 Robotics Systems, Group 1H
Practical assignment

Purpose:
Task 2 - Implementing a test and control strategy for the robot:
    1. To chase an object in an open environment
    2. to avoid any collisions with the object



*/

// Relavant header files
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ch.h"
#include "hal.h"
#include "memory_protection.h"
#include <main.h>
#include <time.h>
#include "chprintf.h"
#include "usbcfg.h"

// Motors
#include "motors.h"

// Distance sensors
#include "sensors/VL53L0X/VL53L0X.h"

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
void Around();            // Function to turn around
void stop();              // Function to stop the robot
void prox_vals();         // Function to get the proximity sensors data
void turn_test(int Prox_thresh);  // Function to set the threshold and determine distance
void dist_vals();          // Function to obtain distance sensor value

// Array for storing proximity values
int Prox_vals[8];

// Variable to store the distance sessor value
uint16_t Dist_val;

int main(void)
{
    halInit();
    chSysInit();
    mpu_init();

    usb_start();
    // Iniatialising UART1 channel
    serial_start();

    // Initiating communication
    messagebus_init(&bus, &bus_lock, &bus_condvar);

    //Starting the proximity measurement module
    proximity_start();

    // Calibrating proximity sensors
    calibrate_ir();

    // Initiating the distance sensor module
    VL53L0X_start();

    // Initialising motors
   motors_init();
   // Setting sensor threshold values
   int Prox_thresh = 200;

    // Infinite while loop
    while (1) {

        //waits half a second
        chThdSleepMilliseconds(500);

        // Proximity sensor values

        prox_vals();
        dist_vals();
        //forward();
        follow();
        //turn_test(Prox_thresh);

        //str_length = sprintf(str, "Hello World\n");
        //e_send_uart1_char(str, x);
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

void stop()
{
    left_motor_set_speed(0);
    right_motor_set_speed(0);
}

void Turn_right()
{
    left_motor_set_speed(400);
    right_motor_set_speed(-400);
}

void Turn_left()
{
    left_motor_set_speed(-400);
    right_motor_set_speed(400);
}

void reverse()
{
    left_motor_set_speed(-600);
    right_motor_set_speed(-600);
}

void forward()
{
    left_motor_set_speed(600);
    right_motor_set_speed(600);
}

void Around()
{
    stop();
    Turn_left();
    stop();
    Turn_left();
    forward();
}


void prox_vals()
{
    // For loop to get the proximity of all sensors
    for (int i = 0; i <= 7; i++)
    {
        // Passing the prox vals to array
        Prox_vals[i] = get_prox(i);

    }
}


void dist_vals()
{
    Dist_val = VL53L0X_get_dist_mm();
}

void turn_test(int Prox_thresh)                                 // need to add thresh condition
{
    if((Prox_vals[0] >= Prox_thresh) && (Prox_vals[1] >= 300))
    {
        stop();
        chThdSleepMilliseconds(500);
        Turn_right();
        chThdSleepMilliseconds(500);
        forward();

    }else if ((Prox_vals[6] >= 300) && (Prox_vals[7] >= Prox_thresh))
    {
        stop();
        //chThdSleepMilliseconds(500);
        //reverse();
        //stop();
        Turn_right();
        chThdSleepMilliseconds(500);
        forward();

    }else if ((Prox_vals[0] >= Prox_thresh) && (Prox_vals[7] >= Prox_thresh))
    {
        stop();
        chThdSleepMilliseconds(500);
        reverse();
        chThdSleepMilliseconds(500);
        Turn_right();
    }else if(Prox_vals[2] >= Prox_thresh)
    {
        //stop();
        chThdSleepMilliseconds(500);
        Turn_right();
        chThdSleepMilliseconds(200);
        forward();
    }else if(Prox_vals[5] >= Prox_thresh)
    {
        //stop();
        chThdSleepMilliseconds(500);
        Turn_left();
        chThdSleepMilliseconds(200);
        forward();
    }else if(Dist_val >= 50 && Dist_val <= 100)
    {
        forward();
    }else if (Dist_val <= 40)
    {
    	reverse();
    }
    else{ stop(); }
}



void follow()
{
	if (Dist_val >= 65 && Dist_val <= 200 )
	{
		forward();
	}else if(Dist_val <= 30)
	{
		reverse();
	}
	else if ( Prox_vals[1] >=120)
    {
		Turn_right();
		chThdSleepMilliseconds(300);

	}else if ( Prox_vals[6] >= 120)
	{
		Turn_left();
		chThdSleepMilliseconds(300);
	}else if(Prox_vals[2] >= 120)
	{
		left_motor_set_speed(350);
		right_motor_set_speed(-350);
	}else if(Prox_vals[3] >= 120)
	{
		left_motor_set_speed(500);
		right_motor_set_speed(-500);
	}else if(Prox_vals[4] >=120)
	{
		left_motor_set_speed(-500);
		right_motor_set_speed(500);
	}
	else{ stop();}
}

















