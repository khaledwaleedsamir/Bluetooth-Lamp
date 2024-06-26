/**
  ******************************************************************************
  * @file    Systick.h
  * @brief   Header file for Systick timer.
  * @author  Khaled Waleed Samir
  * @version 0.1
  ******************************************************************************
  */
#ifndef SYSTICK_H_
#define SYSTICK_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Systick_Regs.h"
#include "Bitmaths.h"
#include "StdTypes.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define F_CPU 8000000
#define SYSTICK_COUNT_FLAG_POS	 16

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void M_SysTick_InitInterrupt(void(*ptrToFunction)(void), uint32_t Local_uint32_t_TimeMS);
void M_SysTick_Delay(uint32_t time);

#endif /* SYSTICK_H_ */
 

 
