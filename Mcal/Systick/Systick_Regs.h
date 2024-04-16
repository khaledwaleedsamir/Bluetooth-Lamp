/**
  ******************************************************************************
  * @file    Systick_Regs.h
  * @brief   Header file including register mapping for systick registers.
  * @author  Khaled Waleed Samir
  * @version 0.1
  ******************************************************************************
  */
#ifndef SYSTICK_REGS_H_
#define SYSTICK_REGS_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "StdTypes.h"

/**********************************************************************************************************************
 *  REGISTERS MAPPING MACROS 
 *********************************************************************************************************************/
#define BASE_ADDRESS_SYSTICK 0xE000E010 /* Base Address for SysTick Timer Registers*/

#define STK_CTRL  *( (volatile uint32_t*) (BASE_ADDRESS_SYSTICK))
#define STK_LOAD  *( (volatile uint32_t*) (BASE_ADDRESS_SYSTICK + 0x04))
#define STK_VAL   *( (volatile uint32_t*) (BASE_ADDRESS_SYSTICK + 0x08))
#define STK_CALIB *( (volatile uint32_t*) (BASE_ADDRESS_SYSTICK + 0x0C))

#endif /* SYSTICK_REGS_H_ */
