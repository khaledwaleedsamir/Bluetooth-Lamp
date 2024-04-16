/**
  ******************************************************************************
  * @file    Systick.c
  * @brief   Main file for Systick timer.
  * @author  Khaled Waleed Samir
  * @version 0.1
  ******************************************************************************
  */

#include "Systick.h"
void (*SysTickCallback)(void);

void M_SysTick_InitInterrupt(void(*ptrToFunction)(void), uint32_t Local_uint32_t_TimeMS)
{
    /*Getting total ticks number*/
    uint32_t Local_uint32_t_TotalTicks = (((float)Local_uint32_t_TimeMS)/1000) * (float)F_CPU;
    
    /* Clearing the CTRL register to disable Systick timer for initalization.*/
    STK_CTRL = 0;

    /* Placing the Desired time in the Load register.*/
    STK_LOAD = Local_uint32_t_TotalTicks;

    /* Initalizing the CTRL register with 
       Bit 2 = 1 -> (Processor Clock AHB) 
       Bit 1 = 1 -> (SysTick Exception Request Enable)
       Bit 0 = 1 -> (Counter Enable) */
    STK_CTRL |= 0x07;
    
    /* Assigning the passed function to be the Systick_Handler callback function.*/
    SysTickCallback = ptrToFunction;

}

void M_SysTick_Delay(uint32_t Local_uint32_t_TimeMS)
{

	uint32_t Local_uint32_t_TotalTicks = (((float)Local_uint32_t_TimeMS)/1000) * (float)F_CPU;

    /* Clearing the CTRL register to disable Systick timer for initalization.*/
    STK_CTRL = 0; 

    /* Placing the Desired time in the Load register.*/
    STK_LOAD  = Local_uint32_t_TotalTicks;

    STK_VAL = 0;              /* Clear the Current Register value */

    /* Initalizing the CTRL register with 
       Bit 2 = 1 -> (Processor Clock AHB) 
       Bit 1 = 0 -> (SysTick Exception Request Disable)
       Bit 0 = 1 -> (Counter Enable) */
    STK_CTRL |= 0x05;

	/* Wait until the COUNT flag = 1 which mean SysTick Timer reaches ZERO value ...
	 * COUNT flag is cleared after read the CTRL register value */
	while(!( GetBit(STK_CTRL,SYSTICK_COUNT_FLAG_POS) ));
}

void SysTick_Handler(void)
{
    SysTickCallback();
}