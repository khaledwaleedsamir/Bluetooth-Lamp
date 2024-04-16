/**
  ******************************************************************************
  * @file    NVIC.h 
  * @brief   Header file for Nested Interrupt Vector Controller Driver.
  * @author  Khaled Waleed Samir
  * @version 0.1
  ******************************************************************************
  */

#ifndef NVIC_H_
#define NVIC_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "NVIC_Regs.h"
#include "NVIC_Cfg.h"
#include "BitMaths.h"
#include "StdTypes.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Priority Grouping Macros */
#define GROUP_16_SUBGROUP_0 0x05FA0300  /*To write to the SCB_AIRCR Register we need to write 0x05FA in the -*/
#define GROUP_8_SUBGROUP_2  0x05FA0400  /*VECTKEY bits otherwise the processor will ignore the write and we also-*/
#define GROUP_4_SUBGROUP_4  0x05FA0500  /*write the priority group option in bits 8, 9 ,10*/
#define GROUP_2_SUBGROUP_8  0x05FA0600
#define GROUP_0_SUBGROUP_16 0x05FA0700

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* Vector Table Priority  */
typedef enum
{
	VT_WWDG,
	VT_PVD,
	VT_TAMPER,
	VT_RTC,
	VT_FLASH,
	VT_RCC,
	VT_EXTI0,
	VT_EXTI1,
	VT_EXTI2,
	VT_EXTI3,
	VT_EXTI4,
	VT_DMA1_Channel1,
	VT_DMA1_Channel2,
	VT_DMA1_Channel3,
	VT_DMA1_Channel4,
	VT_DMA1_Channel5,
	VT_DMA1_Channel6,
	VT_DMA1_Channel7,
	VT_ADC1_2,
	VT_CAN1_TX,
	VT_CAN1_RX0,
	VT_CAN1_RX1,
	VT_CAN1_SCE,
	VT_EXTI9_5,
	VT_TIM1_BRK,
	VT_TIM1_UP,
	VT_TIM1_TRG,
	VT_TIM1_CC,
	VT_TIM2	,
	VT_TIM3	,
	VT_TIM4	,
	VT_I2C1_EV,
	VT_I2C1_ER,
	VT_I2C2_EV,
	VT_I2C2_ER,
	VT_SPI1	,
	VT_SPI2	,
	VT_USART1	,
	VT_USART2	,
	VT_USART3	,
	VT_EXTI15_10,
	VT_RTCAlarm,
	VT_OTG_FS_WKUP,
	VT_TIM5=50,
	VT_SPI3,
	VT_UART4,
	VT_UART5,
	VT_TIM6,
	VT_TIM7,
	VT_DMA2_Channel1,
	VT_DMA2_Channel2,
	VT_DMA2_Channel3,
	VT_DMA2_Channel4
}Enum_Vector_Table;

/*Priority and Sub-Priority*/
typedef enum
{
	GROUP_PRIORITY_0,
	GROUP_PRIORITY_1,
	GROUP_PRIORITY_2,
	GROUP_PRIORITY_3,
	GROUP_PRIORITY_4,
	GROUP_PRIORITY_5,
	GROUP_PRIORITY_6,
	GROUP_PRIORITY_7,
	GROUP_PRIORITY_8,
	GROUP_PRIORITY_9,
	GROUP_PRIORITY_10,
	GROUP_PRIORITY_11,
	GROUP_PRIORITY_12,
	GROUP_PRIORITY_13,
	GROUP_PRIORITY_14,
	GROUP_PRIORITY_15,
	GROUP_PRIORITY_16

}GROUP_PRIORITY;

typedef enum
{
	SUB_PRIORITY_0,
	SUB_PRIORITY_1,
    SUB_PRIORITY_2,
    SUB_PRIORITY_3,
    SUB_PRIORITY_4,
    SUB_PRIORITY_5,
    SUB_PRIORITY_6,
    SUB_PRIORITY_7,
    SUB_PRIORITY_8,
    SUB_PRIORITY_9,
    SUB_PRIORITY_10,
    SUB_PRIORITY_11,
    SUB_PRIORITY_12,
    SUB_PRIORITY_13,
    SUB_PRIORITY_14,
    SUB_PRIORITY_15,
    SUB_PRIORITY_16

}SUB_PRIORITY;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void M_NVIC_Init(void);
void M_NVIC_SetInterruptPriority(uint8_t Local_uint8_t_PeripheralID, uint8_t Local_uint8_t_GroupPriority, uint8_t Local_uint8_t_SubPriority);
void M_NVIC_InterruptEnable(uint8_t Local_uint8_t_IntNumber);
void M_NVIC_InterruptDisable(uint8_t Local_uint8_t_IntNumber);
void M_NVIC_InterruptPendingSet(uint8_t Local_uint8_t_IntNumber);
void M_NVIC_InterruptPendingClear(uint8_t Local_uint8_t_IntNumber);
uint8_t   M_NVIC_InterrruptGetActiveBit(uint8_t Local_uint8_t_IntNumber);

#endif /* NVIC_H_ */
