![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# BarGraph Click

- **CIC Prefix**  : BARGRAPH
- **Author**      : MikroE Team
- **Verison**     : 1.0.1
- **Date**        : apr 2018.

---

### Software Support

We provide a library for the BarGraph Click on our [LibStock](https://libstock.mikroe.com/projects/view/631/bargraph-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library initializes and defines SPI bus driver and drivers that offer a choice for writting data in registers and reading data
from registers. Library includes functions for logging values on the BarGraph display.  
User can enable and disable the chip with the function bargraph_enable(), which is supported in the library. 

Key functions :

- ``` void bargraph_driverInit() ``` - Functions for initializes chip
- ``` void bargraph_display( uint8_t input ) ``` - Display functions
- ``` void bargraph_enable( uint8_t input ) ``` - Functions for enable the chip

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes SPI module and sets PWM pin, CS pin and RST pin as OUTPUT
- Application Initialization - Initializes driver init and BarGraph init
- Application Task - (code snippet) - Counter passes through the loop and logs the value of the counter on the bargraph display


```.c
void applicationTask()
{
    for (cnt = 0; cnt <= 10; cnt++)
    {
        bargraph_display( cnt );
        Delay_ms( 500 );
    }
}
```


The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/631/bargraph-click) page.

Other mikroE Libraries used in the example:

- SPI

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
