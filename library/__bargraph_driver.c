/*
    __bargraph_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__bargraph_driver.h"
#include "__bargraph_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __BARGRAPH_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __BARGRAPH_DRV_SPI__

void bargraph_spiDriverInit(T_BARGRAPH_P gpioObj, T_BARGRAPH_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    hal_gpio_csSet(1);
}

#endif
#ifdef   __BARGRAPH_DRV_I2C__

void bargraph_i2cDriverInit(T_BARGRAPH_P gpioObj, T_BARGRAPH_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __BARGRAPH_DRV_UART__

void bargraph_uartDriverInit(T_BARGRAPH_P gpioObj, T_BARGRAPH_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif


/* ----------------------------------------------------------- IMPLEMENTATION */

void bargraph_driverInit()
{
    hal_gpio_rstSet(1);
    hal_gpio_csSet(1);
    hal_gpio_pwmSet(1);
}

void bargraph_reset()
{
    hal_gpio_rstSet(0);
    Delay_1ms();
    hal_gpio_rstSet(1);
}

void bargraph_display( uint8_t input )
{
    uint16_t convert;
    uint8_t tmp[2];
  
    convert  = (uint16_t)((1 << input) - 1);
    tmp[1] = convert ^ 0xFF;
    tmp[0] = 0x00;
  
    hal_gpio_csSet(0);
    hal_spiWrite(tmp, 2);
    hal_gpio_csSet(1);
}

void bargraph_enable( uint8_t input )
{
    hal_gpio_pwmSet(input);
}


/* -------------------------------------------------------------------------- */
/*
  __bargraph_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */