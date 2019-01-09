/*
    __bargraph_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __bargraph_driver.h
@brief    BarGraph Driver
@mainpage BarGraph Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   BARGRAPH
@brief      BarGraph Click Driver
@{

| Global Library Prefix | **BARGRAPH** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **apr 2018.**      |
| Developer             | **MikroE Team**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _BARGRAPH_H_
#define _BARGRAPH_H_

/** 
 * @macro T_BARGRAPH_P
 * @brief Driver Abstract type 
 */
#define T_BARGRAPH_P    const uint8_t*

/** @defgroup BARGRAPH_COMPILE Compilation Config */              /** @{ */

   #define   __BARGRAPH_DRV_SPI__                            /**<     @macro __BARGRAPH_DRV_SPI__  @brief SPI driver selector */
//  #define   __BARGRAPH_DRV_I2C__                            /**<     @macro __BARGRAPH_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __BARGRAPH_DRV_UART__                           /**<     @macro __BARGRAPH_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup BARGRAPH_INIT Driver Initialization */              /** @{ */

#ifdef   __BARGRAPH_DRV_SPI__
void bargraph_spiDriverInit(T_BARGRAPH_P gpioObj, T_BARGRAPH_P spiObj);
#endif
#ifdef   __BARGRAPH_DRV_I2C__
void bargraph_i2cDriverInit(T_BARGRAPH_P gpioObj, T_BARGRAPH_P i2cObj, uint8_t slave);
#endif
#ifdef   __BARGRAPH_DRV_UART__
void bargraph_uartDriverInit(T_BARGRAPH_P gpioObj, T_BARGRAPH_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void bargraph_gpioDriverInit(T_BARGRAPH_P gpioObj);
                                                                       /** @} */
/** @defgroup BARGRAPH_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Functions for initializes the chip
 */
void bargraph_driverInit();

/**
 * @brief Functions for reset the chip
 */
void bargraph_reset();

/**
 * @brief Displays function
 *
 * @param[in] input  Value to be logs on the BarGraph display
 */
void bargraph_display( uint8_t input );

/**
 * @brief Functions for enable the chip
 */
void bargraph_enable( uint8_t input );

void bargraph3_display(uint8_t ctrl, uint8_t dir, uint8_t counter);

                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_BarGraph_STM.c
    @example Click_BarGraph_TIVA.c
    @example Click_BarGraph_CEC.c
    @example Click_BarGraph_KINETIS.c
    @example Click_BarGraph_MSP.c
    @example Click_BarGraph_PIC.c
    @example Click_BarGraph_PIC32.c
    @example Click_BarGraph_DSPIC.c
    @example Click_BarGraph_AVR.c
    @example Click_BarGraph_FT90x.c
    @example Click_BarGraph_STM.mbas
    @example Click_BarGraph_TIVA.mbas
    @example Click_BarGraph_CEC.mbas
    @example Click_BarGraph_KINETIS.mbas
    @example Click_BarGraph_MSP.mbas
    @example Click_BarGraph_PIC.mbas
    @example Click_BarGraph_PIC32.mbas
    @example Click_BarGraph_DSPIC.mbas
    @example Click_BarGraph_AVR.mbas
    @example Click_BarGraph_FT90x.mbas
    @example Click_BarGraph_STM.mpas
    @example Click_BarGraph_TIVA.mpas
    @example Click_BarGraph_CEC.mpas
    @example Click_BarGraph_KINETIS.mpas
    @example Click_BarGraph_MSP.mpas
    @example Click_BarGraph_PIC.mpas
    @example Click_BarGraph_PIC32.mpas
    @example Click_BarGraph_DSPIC.mpas
    @example Click_BarGraph_AVR.mpas
    @example Click_BarGraph_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __bargraph_driver.h

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