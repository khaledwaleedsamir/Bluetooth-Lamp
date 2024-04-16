/**
  ******************************************************************************
  * @file    NVIC_Regs.h 
  * @brief   Header file including memory mapping for NVIC Registers.
  * @author  Khaled Waleed Samir
  * @version 0.1
  ******************************************************************************
  */


#ifndef NVIC_REGS_H_
#define NVIC_REGS_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "StdTypes.h"

/**********************************************************************************************************************
 *  REGISTERS MAPPING MACROS
 *********************************************************************************************************************/
/* Base address of the main NVIC register block is 0xE000E100 */

#define BASE_ADDRESS_NVIC 0xE000E100
#define NVIC ((NVIC_Typedef*) BASE_ADDRESS_NVIC)
#define NVIC_STIR  *((volatile uint8_t*)(BASE_ADDRESS_NVIC + 0xE00))

/* SCB -> AIRCR register to control the prio group setting*/
#define SCB_AIRCR   *( (volatile uint32_t*) (0xE000ED00 + 0x0C))

/**********************************************************************************************************************
 *  REGISTERS MAPPING DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    volatile uint32_t NVIC_ISER[3];
    volatile uint32_t RES0[29];
    volatile uint32_t NVIC_ICER[3];
    volatile uint32_t RES1[29];
    volatile uint32_t NVIC_ISPR[3];
    volatile uint32_t RES2[29];
    volatile uint32_t NVIC_ICPR[3];
    volatile uint32_t RES3[29];
    volatile uint32_t NVIC_IABR[3];
    volatile uint32_t RES4[61];
    volatile uint8_t  NVIC_IPR[20];
} NVIC_Typedef;

#endif /* NVIC_REGS_H_ */
