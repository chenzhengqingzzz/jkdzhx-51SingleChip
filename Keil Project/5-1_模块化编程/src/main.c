/**
 * *********************************************
 * 
 * 8051 blink demo
 * 
 * PIN: P11
 * 
 * *********************************************
*/

#include "REG52.H"

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;

typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int32_t;

#define EXT0_VECTOR 0  /* 0x03 external interrupt 0 */
#define TIM0_VECTOR 1  /* 0x0b timer 0 */
#define EXT1_VECTOR 2  /* 0x13 external interrupt 1 */
#define TIM1_VECTOR 3  /* 0x1b timer 1 */
#define UART0_VECTOR 4 /* 0x23 serial port 0 */

// LED pin define
sbit LED = P1 ^ 1;

void main()
{
    // set T0 1ms
    TMOD = 0x01;
    TH0 = 0xFC;
    TL0 = 0x18;

    // enable interrupt
    EA = 1;
    ET0 = 1;

    // led pin init
    LED = 1;

    // launch T0
    TR0 = 1;

    while (1)
    {
        // TODO
    }
}

void TIM0_Handler() interrupt TIM0_VECTOR
{
    static uint16_t count;

    TH0 = 0xFC;
    TL0 = 0x18;

    // 500 ms
    if (++count >= 500)
    {
        count = 0;
        LED = !LED;
    }
}
