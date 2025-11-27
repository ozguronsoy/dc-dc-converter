#include "clock.h"

#define CLK_ICKR        (*((volatile uint8_t*)0x0050C0))
#define CLK_CMSR        (*((volatile uint8_t*)0x0050C3))
#define CLK_SWR         (*((volatile uint8_t*)0x0050C4))
#define CLK_SWCR        (*((volatile uint8_t*)0x0050C5))
#define CLK_PCKENR1     (*((volatile uint8_t*)0x0050C7))
#define CLK_PCKENR2     (*((volatile uint8_t*)0x0050CA))

bool clock_init()
{
    // select HSE as master clock
    CLK_SWR = 0xB4;
    CLK_SWCR = 0x02;

    // wait for clock switch
    int i = 0;
    while ((CLK_SWCR & 0x01) == 0x01 && i < MAX_LOOP_ITER)
    {
        i++;
    }

    CLK_SWCR = 0x00;
    if (CLK_CMSR != 0xB4) // clock switch failed
        return false;

    // switch HSI off
    CLK_ICKR = 0x00;

    // enable i2c and adc peripherals
    CLK_PCKENR1 = 0x01;
    CLK_PCKENR2 = 0x08;

    return true;
}