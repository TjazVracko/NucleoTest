#ifndef UNIT_TEST

#include "mbed.h"

#include "mod1.h"
 
DigitalOut led(LED1);
 
int main()
{
    while(1) {
        led = 1; // LED is ON
        wait(0.5); // 500 ms
        led = 0; // LED is OFF
        wait(0.5); // 500 ms
    }
}


#endif