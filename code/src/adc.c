#include "adc.h"

#define ADC_CSR (*((volatile uint8_t*)0x005400))
#define ADC_CR1 (*((volatile uint8_t*)0x005401))
#define ADC_DRH (*((volatile uint8_t*)0x005404))
#define ADC_DRL (*((volatile uint8_t*)0x005405))

void adc_init()
{
    ADC_CSR = 0x23;
    ADC_CR1 = 0x72;
}

void adc_start()
{
    ADC_CR1 |= 0x01;
}

void adc_stop()
{
    ADC_CR1 &= ~0x01;
}

void adc_eoc_isr(void) __interrupt(22)
{
    const uint16_t adc_val = (ADC_DRH << 8) | ADC_DRL;
    const float current_vx = (3.3f * (adc_val / 1023.0f)) * (115.0e3f / 15.0e3f);

    const settings_t* settings = utils_get_settings();
    if (current_vx < settings->min_vx)
    {
        // TODO: adjust FB resistor
    }
    else if (current_vx > settings->max_vx)
    {
        // TODO: adjust FB resistor
    }

    ADC_CSR &= ~0x80;
}