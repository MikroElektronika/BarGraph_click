/*
Example for BarGraph Click

    Date          : apr 2018.
    Author        : MikroE Team

Test configuration STM32 :
    
    MCU              : STM32F107VCT6
    Dev. Board       : EasyMx PRO v7 for STM32
    ARM Compiler ver : vCANT_FIND_VERSION

---

Description :

The application is composed of three sections :

- System Initialization - Initializes SPI module and sets PWM pin, CS pin and RST pin as OUTPUT
- Application Initialization - Initializes driver init and BarGraph init
- Application Task - (code snippet) - Counter passes through the loop and logs the value of the counter on the bargraph display

*/

#include "Click_BarGraph_types.h"
#include "Click_BarGraph_config.h"

#include "__bargraph_driver.h"

uint8_t cnt = 0;

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
    mikrobus_spiInit( _MIKROBUS1, &_BARGRAPH_SPI_CFG[0] );
    Delay_ms( 100 );
}

void applicationInit()
{
    bargraph_spiDriverInit( (T_BARGRAPH_P)&_MIKROBUS1_GPIO, (T_BARGRAPH_P)&_MIKROBUS1_SPI );
    bargraph_driverInit();
}

void applicationTask()
{

        bargraph_display( 5 );
        //bargraph3_display(1, 1, 2);
        Delay_ms( 500 );

}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}