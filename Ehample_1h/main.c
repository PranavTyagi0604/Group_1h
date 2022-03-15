#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ch.h"
#include "hal.h"
#include "memory_protection.h"
#include <main.h>
#include "leds.h"
#include "spi_comm.h"
#include "sensors/proximity.h"
#include "epuck1x/uart/e_uart_char.h"
#include "stdio.h"
#include "serial_comm.h"

messagebus_t bus;
MUTEX_DECL(bus_lock);
CONDVAR_DECL(bus_condvar);


int main(void)
{

    halInit();
    chSysInit();
    mpu_init();

    clear_leds();
    spi_comm_start();
    set_led(LED1,2);
    messagebus_init(&bus, &bus_lock, &bus_condvar);
    proximity_start();
    calibrate_ir();

    int amb_light = get_ambient_light(0);

    serial_start();


    char str[100];
    int str_length;
    int prox;
    int cal_prox;
    int x;
    int y;
    /* Infinite loop. */
    while (1) {
    	//waits 1 second
        chThdSleepMilliseconds(1000);

        prox = get_prox(0);
        cal_prox = get_calibrated_prox(0);
        x = sprintf(str, "%d\n", prox);
        y = sprintf(str, "%d\n", cal_prox);


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
