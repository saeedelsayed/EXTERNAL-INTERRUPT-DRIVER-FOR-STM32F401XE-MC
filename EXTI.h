/*===========================================================
 = Module: EXTERNAL INTERRUPTS                              =
 = File Name: EXTI.h                                        =
 = Description: Header file for the EXTI driver             =
 = Author: Saeed Elsayed                                    =
 ===========================================================*/

#ifndef EXTI_H_
#define EXTI_H_

#include "std_Types.h"
#include "Gpio.h"
#include "Bit_Operations.h"

typedef struct {
	uint32 MEMRMP;
	uint32 PMC;
	uint32 EXTICR1;
	uint32 EXTICR2;
	uint32 EXTICR3;
	uint32 EXTICR4;
}SYSCFG_registers;

typedef struct {
	uint32 IMR;
	uint32 EMR;
	uint32 RTSR;
	uint32 FTSR;
	uint32 SWIER;
	uint32 PR;
} ExtiType;

typedef enum{
	FALLING_EDGE, RAISING_EDGE, FALLING_AND_RAISING_EGDE
}EXTI_EdgeType;


/*===========================================================
 =                       Definitions                        =
 ===========================================================*/

#define NVIC_ISER0 (*(uint32 *)0xE000E100)
#define NVIC_ISER1 (*(uint32 *)0xE000E104)

#define EXTI ((ExtiType *)0x40013C00)
#define SYSCFG ((SYSCFG_registers*)0x40013800)

/*===========================================================
 =                 Declaration of functions                 =
 ===========================================================*/

void EXTI_Init(uint8 port_id, uint8 pin_id, EXTI_EdgeType edge_type);
void EXTI_Enable(uint8 pin_id);
void EXTI_Disable(uint8 pin_id);


#endif /* EXTI_H_ */
