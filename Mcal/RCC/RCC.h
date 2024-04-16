/**
  ******************************************************************************
  * @file    RCC.h 
  * @brief   Header file for Reset Clock Control Driver.
  ******************************************************************************
  */
#ifndef _RCC_H_
#define _RCC_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "RCC_Regs.h"
#include "RCC_Cfg.h"
#include "StdTypes.h"
#include "Bitmaths.h"

/**********************************************************************************************************************
 *  Macros
 *********************************************************************************************************************/
/* Clock Types */
#define RCC_HSE_CRYSTAL				(0)
#define RCC_HSE_RC					  (1)
#define RCC_HSI								(2)
#define RCC_PLL								(3)

/* PLL Input Options */
#define RCC_PLL_IN_HSI_DIV_2		        (0)
#define RCC_PLL_IN_HSE_CRYSTAL_DIV_2		(1)
#define RCC_PLL_IN_HSE_CRYSTAL				  (2)
#define RCC_PLL_IN_HSE_RC_DIV_2				  (3)
#define RCC_PLL_IN_HSE_RC					      (4)

/* System Buses */
#define	RCC_AHB								((uint8_t)(0))
#define	RCC_APB1							((uint8_t)(1))
#define	RCC_APB2							((uint8_t)(2))

/* AHB Bus Peripherals' IDs */
#define	RCC_AHB_DMA1EN						((uint8_t)(0))
#define	RCC_AHB_DMA2EN						((uint8_t)(1))
#define	RCC_AHB_SRAMEN						((uint8_t)(2))
#define	RCC_AHB_FLITFEN						((uint8_t)(4))
#define	RCC_AHB_CRCEN						  ((uint8_t)(6))
#define	RCC_AHB_FSMCEN						((uint8_t)(8))
#define	RCC_AHB_SDIOEN						((uint8_t)(10))

/* APB1 Bus Peripherals' IDs */
#define	RCC_APB1_TIM2EN						((uint8_t)(0))
#define	RCC_APB1_TIM3EN						((uint8_t)(1))
#define	RCC_APB1_TIM4EN						((uint8_t)(2))
#define	RCC_APB1_TIM5EN						((uint8_t)(3))
#define	RCC_APB1_TIM6EN						((uint8_t)(4))
#define	RCC_APB1_TIM7EN						((uint8_t)(5))
#define	RCC_APB1_TIM12EN					((uint8_t)(6))
#define	RCC_APB1_TIM13EN					((uint8_t)(7))
#define	RCC_APB1_TIM14EN					((uint8_t)(8))
#define	RCC_APB1_WWDGEN						((uint8_t)(11))
#define	RCC_APB1_SPI2EN						((uint8_t)(14))
#define	RCC_APB1_SPI3EN						((uint8_t)(15))
#define	RCC_APB1_USART2EN					((uint8_t)(17))
#define	RCC_APB1_USART3EN					((uint8_t)(18))
#define	RCC_APB1_USART4EN					((uint8_t)(19))
#define	RCC_APB1_USART5EN					((uint8_t)(20))
#define	RCC_APB1_I2C1EN						((uint8_t)(21))
#define	RCC_APB1_I2C2EN						((uint8_t)(22))
#define	RCC_APB1_USBEN						((uint8_t)(23))
#define	RCC_APB1_CANEN						((uint8_t)(25))
#define	RCC_APB1_BKPEN						((uint8_t)(27))
#define	RCC_APB1_PWREN						((uint8_t)(28))
#define	RCC_APB1_DACEN						((uint8_t)(29))

/* APB2 Bus Peripherals' IDs */
#define	RCC_APB2_AFIOEN						((uint8_t)(0))
#define	RCC_APB2_IOPAEN						((uint8_t)(2))
#define	RCC_APB2_IOPBEN						((uint8_t)(3))
#define	RCC_APB2_IOPCEN						((uint8_t)(4))
#define	RCC_APB2_IOPDEN						((uint8_t)(5))
#define	RCC_APB2_IOPEEN						((uint8_t)(6))
#define	RCC_APB2_IOPFEN						((uint8_t)(7))
#define	RCC_APB2_IOPGEN						((uint8_t)(8))
#define	RCC_APB2_ADC1EN						((uint8_t)(9))
#define	RCC_APB2_ADC2EN						((uint8_t)(10))
#define	RCC_APB2_TIM1EN						((uint8_t)(11))
#define	RCC_APB2_SPI1EN						((uint8_t)(12))
#define	RCC_APB2_TIM8EN						((uint8_t)(13))
#define	RCC_APB2_USART1EN					((uint8_t)(14))
#define	RCC_APB2_ADC3EN						((uint8_t)(15))
#define	RCC_APB2_TIM9EN						((uint8_t)(19))
#define	RCC_APB2_TIM10EN					((uint8_t)(20))
#define	RCC_APB2_TIM11EN					((uint8_t)(21))

/**********************************************************************************************************************
 * Functions Prototypes
 *********************************************************************************************************************/
void M_RCC_InitSysClock (void);
void M_RCC_EnableClock  (uint8_t Copy_uint8_tBusID, uint8_t Copy_uint8_tPerID);
void M_RCC_DisableClock (uint8_t Copy_uint8_tBusID, uint8_t Copy_uint8_tPerID);

#endif /* _RCC_H_*/