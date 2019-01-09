_systemInit:
;Click_BarGraph_STM.c,32 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_BarGraph_STM.c,34 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #2
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_BarGraph_STM.c,35 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #1
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_BarGraph_STM.c,36 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #6
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_BarGraph_STM.c,37 :: 		mikrobus_spiInit( _MIKROBUS1, &_BARGRAPH_SPI_CFG[0] );
MOVW	R0, #lo_addr(__BARGRAPH_SPI_CFG+0)
MOVT	R0, #hi_addr(__BARGRAPH_SPI_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_spiInit+0
;Click_BarGraph_STM.c,38 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_BarGraph_STM.c,39 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_BarGraph_STM.c,41 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_BarGraph_STM.c,43 :: 		bargraph_spiDriverInit( (T_BARGRAPH_P)&_MIKROBUS1_GPIO, (T_BARGRAPH_P)&_MIKROBUS1_SPI );
MOVW	R1, #lo_addr(__MIKROBUS1_SPI+0)
MOVT	R1, #hi_addr(__MIKROBUS1_SPI+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_bargraph_spiDriverInit+0
;Click_BarGraph_STM.c,44 :: 		bargraph_driverInit();
BL	_bargraph_driverInit+0
;Click_BarGraph_STM.c,45 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_BarGraph_STM.c,47 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_BarGraph_STM.c,50 :: 		bargraph_display( 5 );
MOVS	R0, #5
BL	_bargraph_display+0
;Click_BarGraph_STM.c,52 :: 		Delay_ms( 500 );
MOVW	R7, #36223
MOVT	R7, #91
NOP
NOP
L_applicationTask2:
SUBS	R7, R7, #1
BNE	L_applicationTask2
NOP
NOP
NOP
;Click_BarGraph_STM.c,54 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_BarGraph_STM.c,56 :: 		void main()
;Click_BarGraph_STM.c,58 :: 		systemInit();
BL	_systemInit+0
;Click_BarGraph_STM.c,59 :: 		applicationInit();
BL	_applicationInit+0
;Click_BarGraph_STM.c,61 :: 		while (1)
L_main4:
;Click_BarGraph_STM.c,63 :: 		applicationTask();
BL	_applicationTask+0
;Click_BarGraph_STM.c,64 :: 		}
IT	AL
BAL	L_main4
;Click_BarGraph_STM.c,65 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
