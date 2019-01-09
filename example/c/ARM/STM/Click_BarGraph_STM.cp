#line 1 "D:/Clicks_git/B/BarGraph_Click/SW/example/c/ARM/STM/Click_BarGraph_STM.c"
#line 1 "d:/clicks_git/b/bargraph_click/sw/example/c/arm/stm/click_bargraph_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "d:/clicks_git/b/bargraph_click/sw/example/c/arm/stm/click_bargraph_config.h"
#line 1 "d:/clicks_git/b/bargraph_click/sw/example/c/arm/stm/click_bargraph_types.h"
#line 3 "d:/clicks_git/b/bargraph_click/sw/example/c/arm/stm/click_bargraph_config.h"
const uint32_t _BARGRAPH_SPI_CFG[ 2 ] =
{
 _SPI_FPCLK_DIV128,
 _SPI_SECOND_CLK_EDGE_TRANSITION |
 _SPI_CLK_IDLE_HIGH |
 _SPI_MASTER |
 _SPI_MSB_FIRST |
 _SPI_8_BIT |
 _SPI_SSM_ENABLE |
 _SPI_SS_DISABLE |
 _SPI_SSI_1
};
#line 1 "d:/clicks_git/b/bargraph_click/sw/library/__bargraph_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 63 "d:/clicks_git/b/bargraph_click/sw/library/__bargraph_driver.h"
void bargraph_spiDriverInit( const uint8_t*  gpioObj,  const uint8_t*  spiObj);
#line 73 "d:/clicks_git/b/bargraph_click/sw/library/__bargraph_driver.h"
void bargraph_gpioDriverInit( const uint8_t*  gpioObj);
#line 80 "d:/clicks_git/b/bargraph_click/sw/library/__bargraph_driver.h"
void bargraph_driverInit();
#line 85 "d:/clicks_git/b/bargraph_click/sw/library/__bargraph_driver.h"
void bargraph_reset();
#line 92 "d:/clicks_git/b/bargraph_click/sw/library/__bargraph_driver.h"
void bargraph_display( uint8_t input );
#line 97 "d:/clicks_git/b/bargraph_click/sw/library/__bargraph_driver.h"
void bargraph_enable( uint8_t input );

void bargraph3_display(uint8_t ctrl, uint8_t dir, uint8_t counter);
#line 30 "D:/Clicks_git/B/BarGraph_Click/SW/example/c/ARM/STM/Click_BarGraph_STM.c"
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
 bargraph_spiDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_SPI );
 bargraph_driverInit();
}

void applicationTask()
{

 bargraph_display( 5 );

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
