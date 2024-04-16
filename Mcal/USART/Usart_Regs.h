/**
  ******************************************************************************
  * @file    Usart_Regs.h
  * @brief   Header file including register mapping for USART registers.
  * @author  Khaled Waleed Samir
  * @version 0.1
  ******************************************************************************
  */
#ifndef USART_REGS_H_
#define USART_REGS_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "StdTypes.h"

/**********************************************************************************************************************
 *  REGISTERS MAPPING MACROS 
 *********************************************************************************************************************/
#define BASE_ADDRESS_USART_1 0x40013800 /* Base Address for USART_1 Registers*/

#define USART_SR    *( (volatile uint32_t*) (BASE_ADDRESS_USART_1))
#define USART_DR    *( (volatile uint32_t*) (BASE_ADDRESS_USART_1+0x04))
#define USART_BRR   *( (volatile uint32_t*) (BASE_ADDRESS_USART_1+0x08))
#define USART_CR1   *( (volatile uint32_t*) (BASE_ADDRESS_USART_1+0x0C))
#define USART_CR2   *( (volatile uint32_t*) (BASE_ADDRESS_USART_1+0x10))
#define USART_CR3   *( (volatile uint32_t*) (BASE_ADDRESS_USART_1+0x14))
#define USART_GTPR  *( (volatile uint32_t*) (BASE_ADDRESS_USART_1+0x18))


#endif  /* USART_REGS_H_ */