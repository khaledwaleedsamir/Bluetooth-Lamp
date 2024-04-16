/**
  ******************************************************************************
  * @file    GPIO_Regs.h
  * @brief   Header file including memory mapping for GPIO Registers.
  * @author  Khaled Waleed Samir
  * @version 0.1
  ******************************************************************************
  */

#ifndef GPIO_REGS_H_
#define GPIO_REGS_H_

/**********************************************************************************************************************
 * Includes
 *********************************************************************************************************************/
#include "StdTypes.h"

/**********************************************************************************************************************
 * Registers Mapping Macros
 *********************************************************************************************************************/
#define PORTA_BASE_ADDRESS 0x40010800
#define PORTB_BASE_ADDRESS 0x40010C00
#define PORTC_BASE_ADDRESS 0x40011000

/*PORT-A REGISTERS*/
#define GPIOA_CRL   *( (volatile uint32_t*) (PORTA_BASE_ADDRESS))
#define GPIOA_CRH   *( (volatile uint32_t*) (PORTA_BASE_ADDRESS + 0x04))
#define GPIOA_IDR   *( (volatile uint32_t*) (PORTA_BASE_ADDRESS + 0x08))
#define GPIOA_ODR   *( (volatile uint32_t*) (PORTA_BASE_ADDRESS + 0x0C))
#define GPIOA_BSSR  *( (volatile uint32_t*) (PORTA_BASE_ADDRESS + 0x10))
#define GPIOA_BRR   *( (volatile uint32_t*) (PORTA_BASE_ADDRESS + 0x14))
#define GPIOA_LCKR  *( (volatile uint32_t*) (PORTA_BASE_ADDRESS + 0x18))

/*PORT-B REGISTERS*/
#define GPIOB_CRL   *( (volatile uint32_t*) (PORTB_BASE_ADDRESS))
#define GPIOB_CRH   *( (volatile uint32_t*) (PORTB_BASE_ADDRESS + 0x04))
#define GPIOB_IDR   *( (volatile uint32_t*) (PORTB_BASE_ADDRESS + 0x08))
#define GPIOB_ODR   *( (volatile uint32_t*) (PORTB_BASE_ADDRESS + 0x0C))
#define GPIOB_BSSR  *( (volatile uint32_t*) (PORTB_BASE_ADDRESS + 0x10))
#define GPIOB_BRR   *( (volatile uint32_t*) (PORTB_BASE_ADDRESS + 0x14))
#define GPIOB_LCKR  *( (volatile uint32_t*) (PORTB_BASE_ADDRESS + 0x18))

/*PORT-C REGISTERS*/
#define GPIOC_CRL   *( (volatile uint32_t*) (PORTC_BASE_ADDRESS))
#define GPIOC_CRH   *( (volatile uint32_t*) (PORTC_BASE_ADDRESS + 0x04))
#define GPIOC_IDR   *( (volatile uint32_t*) (PORTC_BASE_ADDRESS + 0x08))
#define GPIOC_ODR   *( (volatile uint32_t*) (PORTC_BASE_ADDRESS + 0x0C))
#define GPIOC_BSSR  *( (volatile uint32_t*) (PORTC_BASE_ADDRESS + 0x10))
#define GPIOC_BRR   *( (volatile uint32_t*) (PORTC_BASE_ADDRESS + 0x14))
#define GPIOC_LCKR  *( (volatile uint32_t*) (PORTC_BASE_ADDRESS + 0x18))


#endif /* GPIO_REGS_H_ */