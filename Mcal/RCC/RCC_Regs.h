/**
  ******************************************************************************
  * @file    RCC_Regs.h 
  * @brief   Header file including memory mapping for RCC Registers.
  ******************************************************************************
  */
 #ifndef _RCC_REGS_H_
 #define _RCC_REGS_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "StdTypes.h"

/**********************************************************************************************************************
 * Registers Mapping
 *********************************************************************************************************************/
#define BASE_ADDRESS_RCC 0x40021000 /* Base Address for RCC Registers*/

#define RCC_CR        *( (volatile uint32_t*) (BASE_ADDRESS_RCC + 0x00))
#define RCC_CFGR      *( (volatile uint32_t*) (BASE_ADDRESS_RCC + 0x04))
#define RCC_CIR       *( (volatile uint32_t*) (BASE_ADDRESS_RCC + 0x08))
#define RCC_APB2RSTR  *( (volatile uint32_t*) (BASE_ADDRESS_RCC + 0x0C))
#define RCC_APB1RSTR  *( (volatile uint32_t*) (BASE_ADDRESS_RCC + 0x10))
#define RCC_AHBENR    *( (volatile uint32_t*) (BASE_ADDRESS_RCC + 0x14))
#define RCC_APB2ENR   *( (volatile uint32_t*) (BASE_ADDRESS_RCC + 0x18))
#define RCC_APB1ENR   *( (volatile uint32_t*) (BASE_ADDRESS_RCC + 0x1C))
#define RCC_BDCR      *( (volatile uint32_t*) (BASE_ADDRESS_RCC + 0x20))
#define RCC_CSR       *( (volatile uint32_t*) (BASE_ADDRESS_RCC + 0x24))
#define RCC_AHBRSTR   *( (volatile uint32_t*) (BASE_ADDRESS_RCC + 0x28))
#define RCC_CFGR2     *( (volatile uint32_t*) (BASE_ADDRESS_RCC + 0x2C))


 #endif /* _RCC_REGS_H_ */