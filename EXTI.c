/*===========================================================
 = Module: EXTERNAL INTERRUPTS                              =
 = File Name: SYSCFG.c                                        =
 = Description: Source file for the SYSCFG driver             =
 = Author: Saeed Elsayed                                    =
 ===========================================================*/

#include "EXTI.h"



void EXTI_Init(uint8 port_id, uint8 pin_id, EXTI_EdgeType edge_type)
{
	if(edge_type == FALLING_EDGE)
	{
		SET_BIT(EXTI->FTSR, pin_id);
		CLEAR_BIT(EXTI->RTSR, pin_id);
	}
	else if(edge_type == RAISING_EDGE)
	{
		SET_BIT(EXTI->RTSR, pin_id);
		CLEAR_BIT(EXTI->FTSR, pin_id);
	}
	else if(edge_type == FALLING_AND_RAISING_EGDE)
	{
		SET_BIT(EXTI->FTSR, pin_id);
		SET_BIT(EXTI->RTSR, pin_id);
	}

	switch(pin_id)
	{
	uint8 bit_index;
	case 0:
	case 1:
	case 2:
	case 3:
		if(port_id == GPIO_A)
		{
			CLEAR_BIT(SYSCFG->EXTICR1, (4*pin_id));
			CLEAR_BIT(SYSCFG->EXTICR1, (4*pin_id)+1);
			CLEAR_BIT(SYSCFG->EXTICR1, (4*pin_id)+2);
			CLEAR_BIT(SYSCFG->EXTICR1, (4*pin_id)+3);
		}
		else if(port_id == GPIO_B)
		{
			SET_BIT(SYSCFG->EXTICR1, (4*pin_id));
			CLEAR_BIT(SYSCFG->EXTICR1, (4*pin_id)+1);
			CLEAR_BIT(SYSCFG->EXTICR1, (4*pin_id)+2);
			CLEAR_BIT(SYSCFG->EXTICR1, (4*pin_id)+3);
		}
		else if(port_id == GPIO_C)
		{
			CLEAR_BIT(SYSCFG->EXTICR1, (4*pin_id));
			SET_BIT(SYSCFG->EXTICR1, (4*pin_id)+1);
			CLEAR_BIT(SYSCFG->EXTICR1, (4*pin_id)+2);
			CLEAR_BIT(SYSCFG->EXTICR1, (4*pin_id)+3);
		}
		else if(port_id == GPIO_D)
		{
			SET_BIT(SYSCFG->EXTICR1, (4*pin_id));
			SET_BIT(SYSCFG->EXTICR1, (4*pin_id)+1);
			CLEAR_BIT(SYSCFG->EXTICR1, (4*pin_id)+2);
			CLEAR_BIT(SYSCFG->EXTICR1, (4*pin_id)+3);
		}
		else if(port_id == GPIO_E)
		{
			CLEAR_BIT(SYSCFG->EXTICR1, (4*pin_id));
			CLEAR_BIT(SYSCFG->EXTICR1, (4*pin_id)+1);
			SET_BIT(SYSCFG->EXTICR1, (4*pin_id)+2);
			CLEAR_BIT(SYSCFG->EXTICR1, (4*pin_id)+3);
		}
		else if(port_id == GPIO_h)
		{
			SET_BIT(SYSCFG->EXTICR1, (4*pin_id));
			SET_BIT(SYSCFG->EXTICR1, (4*pin_id)+1);
			SET_BIT(SYSCFG->EXTICR1, (4*pin_id)+2);
			CLEAR_BIT(SYSCFG->EXTICR1, (4*pin_id)+3);
		}
		break;
	case 4:
	case 5:
	case 6:
	case 7:
		bit_index = pin_id - 4;
		if(port_id == GPIO_A)
		{
			CLEAR_BIT(SYSCFG->EXTICR2, (4*bit_index));
			CLEAR_BIT(SYSCFG->EXTICR2, (4*bit_index)+1);
			CLEAR_BIT(SYSCFG->EXTICR2, (4*bit_index)+2);
			CLEAR_BIT(SYSCFG->EXTICR2, (4*bit_index)+3);
		}
		else if(port_id == GPIO_B)
		{
			SET_BIT(SYSCFG->EXTICR2, (4*bit_index));
			CLEAR_BIT(SYSCFG->EXTICR2, (4*bit_index)+1);
			CLEAR_BIT(SYSCFG->EXTICR2, (4*bit_index)+2);
			CLEAR_BIT(SYSCFG->EXTICR2, (4*bit_index)+3);
		}
		else if(port_id == GPIO_C)
		{
			CLEAR_BIT(SYSCFG->EXTICR2, (4*bit_index));
			SET_BIT(SYSCFG->EXTICR2, (4*bit_index)+1);
			CLEAR_BIT(SYSCFG->EXTICR2, (4*bit_index)+2);
			CLEAR_BIT(SYSCFG->EXTICR2, (4*bit_index)+3);
		}
		else if(port_id == GPIO_D)
		{
			SET_BIT(SYSCFG->EXTICR2, (4*bit_index));
			SET_BIT(SYSCFG->EXTICR2, (4*bit_index)+1);
			CLEAR_BIT(SYSCFG->EXTICR2, (4*bit_index)+2);
			CLEAR_BIT(SYSCFG->EXTICR2, (4*bit_index)+3);
		}
		else if(port_id == GPIO_E)
		{
			CLEAR_BIT(SYSCFG->EXTICR2, (4*bit_index));
			CLEAR_BIT(SYSCFG->EXTICR2, (4*bit_index)+1);
			SET_BIT(SYSCFG->EXTICR2, (4*bit_index)+2);
			CLEAR_BIT(SYSCFG->EXTICR2, (4*bit_index)+3);
		}
		else if(port_id == GPIO_h)
		{
			SET_BIT(SYSCFG->EXTICR2, (4*bit_index));
			SET_BIT(SYSCFG->EXTICR2, (4*bit_index)+1);
			SET_BIT(SYSCFG->EXTICR2, (4*bit_index)+2);
			CLEAR_BIT(SYSCFG->EXTICR2, (4*bit_index)+3);
		}
		break;
	case 8:
	case 9:
	case 10:
	case 11:
		bit_index = pin_id - 8;
		if(port_id == GPIO_A)
		{
			CLEAR_BIT(SYSCFG->EXTICR3, (4*bit_index));
			CLEAR_BIT(SYSCFG->EXTICR3, (4*bit_index)+1);
			CLEAR_BIT(SYSCFG->EXTICR3, (4*bit_index)+2);
			CLEAR_BIT(SYSCFG->EXTICR3, (4*bit_index)+3);
		}
		else if(port_id == GPIO_B)
		{
			SET_BIT(SYSCFG->EXTICR3, (4*bit_index));
			CLEAR_BIT(SYSCFG->EXTICR3, (4*bit_index)+1);
			CLEAR_BIT(SYSCFG->EXTICR3, (4*bit_index)+2);
			CLEAR_BIT(SYSCFG->EXTICR3, (4*bit_index)+3);
		}
		else if(port_id == GPIO_C)
		{
			CLEAR_BIT(SYSCFG->EXTICR3, (4*bit_index));
			SET_BIT(SYSCFG->EXTICR3, (4*bit_index)+1);
			CLEAR_BIT(SYSCFG->EXTICR3, (4*bit_index)+2);
			CLEAR_BIT(SYSCFG->EXTICR3, (4*bit_index)+3);
		}
		else if(port_id == GPIO_D)
		{
			SET_BIT(SYSCFG->EXTICR3, (4*bit_index));
			SET_BIT(SYSCFG->EXTICR3, (4*bit_index)+1);
			CLEAR_BIT(SYSCFG->EXTICR3, (4*bit_index)+2);
			CLEAR_BIT(SYSCFG->EXTICR3, (4*bit_index)+3);
		}
		else if(port_id == GPIO_E)
		{
			CLEAR_BIT(SYSCFG->EXTICR3, (4*bit_index));
			CLEAR_BIT(SYSCFG->EXTICR3, (4*bit_index)+1);
			SET_BIT(SYSCFG->EXTICR3, (4*bit_index)+2);
			CLEAR_BIT(SYSCFG->EXTICR3, (4*bit_index)+3);
		}
		else if(port_id == GPIO_h)
		{
			SET_BIT(SYSCFG->EXTICR3, (4*bit_index));
			SET_BIT(SYSCFG->EXTICR3, (4*bit_index)+1);
			SET_BIT(SYSCFG->EXTICR3, (4*bit_index)+2);
			CLEAR_BIT(SYSCFG->EXTICR3, (4*bit_index)+3);
		}
		break;
	case 12:
	case 13:
	case 14:
	case 15:
		bit_index = pin_id - 12;
		if(port_id == GPIO_A)
		{
			CLEAR_BIT(SYSCFG->EXTICR4, (4*bit_index));
			CLEAR_BIT(SYSCFG->EXTICR4, (4*bit_index)+1);
			CLEAR_BIT(SYSCFG->EXTICR4, (4*bit_index)+2);
			CLEAR_BIT(SYSCFG->EXTICR4, (4*bit_index)+3);
		}
		else if(port_id == GPIO_B)
		{
			SET_BIT(SYSCFG->EXTICR4, (4*bit_index));
			CLEAR_BIT(SYSCFG->EXTICR4, (4*bit_index)+1);
			CLEAR_BIT(SYSCFG->EXTICR4, (4*bit_index)+2);
			CLEAR_BIT(SYSCFG->EXTICR4, (4*bit_index)+3);
		}
		else if(port_id == GPIO_C)
		{
			CLEAR_BIT(SYSCFG->EXTICR4, (4*bit_index));
			SET_BIT(SYSCFG->EXTICR4, (4*bit_index)+1);
			CLEAR_BIT(SYSCFG->EXTICR4, (4*bit_index)+2);
			CLEAR_BIT(SYSCFG->EXTICR4, (4*bit_index)+3);
		}
		else if(port_id == GPIO_D)
		{
			SET_BIT(SYSCFG->EXTICR4, (4*bit_index));
			SET_BIT(SYSCFG->EXTICR4, (4*bit_index)+1);
			CLEAR_BIT(SYSCFG->EXTICR4, (4*bit_index)+2);
			CLEAR_BIT(SYSCFG->EXTICR4, (4*bit_index)+3);
		}
		else if(port_id == GPIO_E)
		{
			CLEAR_BIT(SYSCFG->EXTICR4, (4*bit_index));
			CLEAR_BIT(SYSCFG->EXTICR4, (4*bit_index)+1);
			SET_BIT(SYSCFG->EXTICR4, (4*bit_index)+2);
			CLEAR_BIT(SYSCFG->EXTICR4, (4*bit_index)+3);
		}
		else if(port_id == GPIO_h)
		{
			SET_BIT(SYSCFG->EXTICR4, (4*bit_index));
			SET_BIT(SYSCFG->EXTICR4, (4*bit_index)+1);
			SET_BIT(SYSCFG->EXTICR4, (4*bit_index)+2);
			CLEAR_BIT(SYSCFG->EXTICR4, (4*bit_index)+3);
		}
		break;

	}

}

void EXTI_Enable(uint8 pin_id)
{
	if(pin_id <= 4)
	{
		uint8 index = pin_id + 6;
		SET_BIT(NVIC_ISER0, index);
	}
	else if(pin_id  <= 9)
	{
		SET_BIT(NVIC_ISER0, 23);
	}
	else if(pin_id <= 15)
	{
		SET_BIT(NVIC_ISER1, 8);
	}
	SET_BIT(EXTI->IMR, pin_id);
}

void EXTI_Disable(uint8 pin_id)
{
	CLEAR_BIT(EXTI->IMR, pin_id);
}
