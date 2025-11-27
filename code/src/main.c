#include "utils.h"
#include "clock.h"
#include "comm.h"
#include "adc.h"

int main()
{
    // select HSE and enable adc and i2c peripherals
    if (!clock_init())
        return 1;

    adc_init();
    comm_init();

    // enable interrupts
    __asm__("rim");

    while (true)
    {
        // wait for interrupts
        __asm__("wfi");
    }

    return 0;
}