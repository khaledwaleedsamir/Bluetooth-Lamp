/**
  ******************************************************************************
  * @file    NVIC.c
  * @brief   Main file for Nested Interrupt Vector Controller Driver.
  * @author  Khaled Waleed Samir
  * @version 0.1
  ******************************************************************************
  */

#include "NVIC.h"

void M_NVIC_Init(void)
{
    #if   PRIORITY_GROUPING == GROUP_16_SUBGROUP_0
	      SCB_AIRCR = GROUP_16_SUBGROUP_0;
    #elif PRIORITY_GROUPING == GROUP_8_SUBGROUP_2
	      SCB_AIRCR = GROUP_8_SUBGROUP_2;
    #elif PRIORITY_GROUPING == GROUP_4_SUBGROUP_4
	      SCB_AIRCR = GROUP_4_SUBGROUP_4;
    #elif PRIORITY_GROUPING == GROUP_2_SUBGROUP_8
	      SCB_AIRCR = GROUP_2_SUBGROUP_8;
    #elif PRIORITY_GROUPING == GROUP_0_SUBGROUP_16
	      SCB_AIRCR = GROUP_0_SUBGROUP_16;
    #endif
}


void M_NVIC_SetInterruptPriority(uint8_t Local_uint8_t_PeripheralID, uint8_t Local_uint8_t_GroupPriority, uint8_t Local_uint8_t_SubPriority)
{
    #if   PRIORITY_GROUPING == GROUP_16_SUBGROUP_0
          if(Local_uint8_t_GroupPriority<=16 && Local_uint8_t_SubPriority ==0)
          {
             uint8_t Local_uint8_t_IPR_Number = Local_uint8_t_PeripheralID/4;
             uint8_t Local_uint8_t_ByteOffset = Local_uint8_t_PeripheralID%4;
             NVIC->NVIC_IPR[Local_uint8_t_IPR_Number] |= (Local_uint8_t_GroupPriority<<4)<<Local_uint8_t_ByteOffset;

          }
    #elif PRIORITY_GROUPING == GROUP_8_SUBGROUP_2
          if(Local_uint8_t_GroupPriority <= 8 && Local_uint8_t_SubPriority <= 2)
          {
            uint8_t Local_uint8_t_IPR_Number = Local_uint8_t_PeripheralID/4;
            uint8_t Local_uint8_t_ByteOffset = Local_uint8_t_PeripheralID%4;
            uint8_t Local_uint8_t_IPRxValue   = Local_uint8_t_GroupPriority<<5;
               Local_uint8_t_IPRxValue  |= Local_uint8_t_SubPriority<<4; 
            NVIC->NVIC_IPR[Local_uint8_t_IPR_Number] |= (Local_uint8_t_IPRxValue)<<Local_uint8_t_ByteOffset;

          }
    #elif PRIORITY_GROUPING == GROUP_4_SUBGROUP_4
          if(Local_uint8_t_GroupPriority <= 4 && Local_uint8_t_SubPriority <= 4)
          {
            uint8_t Local_uint8_t_IPR_Number = Local_uint8_t_PeripheralID/4;
            uint8_t Local_uint8_t_ByteOffset = Local_uint8_t_PeripheralID%4;
            uint8_t Local_uint8_t_IPRxValue  = Local_uint8_t_GroupPriority<<6;
               Local_uint8_t_IPRxValue  |= Local_uint8_t_SubPriority<<4; 
            NVIC->NVIC_IPR[Local_uint8_t_IPR_Number] |= (Local_uint8_t_IPRxValue)<<Local_uint8_t_ByteOffset;
          }
    #elif PRIORITY_GROUPING == GROUP_2_SUBGROUP_8
          if(Local_uint8_t_GroupPriority <= 2 && Local_uint8_t_SubPriority <= 8)
          {
            uint8_t Local_uint8_t_IPR_Number = Local_uint8_t_PeripheralID/4;
            uint8_t Local_uint8_t_ByteOffset = Local_uint8_t_PeripheralID%4;
            uint8_t Local_uint8_t_IPRxValue  = Local_uint8_t_GroupPriority<<7;
               Local_uint8_t_IPRxValue  |= Local_uint8_t_SubPriority<<4; 
            NVIC->NVIC_IPR[Local_uint8_t_IPR_Number] |= (Local_uint8_t_IPRxValue)<<Local_uint8_t_ByteOffset;
          }
    #elif PRIORITY_GROUPING == GROUP_0_SUBGROUP_16
          if(Local_uint8_t_GroupPriority == 0 && Local_uint8_t_SubPriority <= 16)
          {
            uint8_t Local_uint8_t_IPR_Number = Local_uint8_t_PeripheralID/4;
            uint8_t Local_uint8_t_ByteOffset = Local_uint8_t_PeripheralID%4;
            NVIC->NVIC_IPR[Local_uint8_t_IPR_Number] |= (Local_uint8_t_SubPriority<<4)<<Local_uint8_t_ByteOffset;
          }
    #endif


}
void M_NVIC_InterruptEnable(uint8_t Local_uint8_t_IntNumber)
{
    if(Local_uint8_t_IntNumber < 32)
    {
        SetBit(NVIC->NVIC_ISER[0],Local_uint8_t_IntNumber);
    }
    else if(Local_uint8_t_IntNumber < 60)
    {
        Local_uint8_t_IntNumber-=32;
        SetBit(NVIC->NVIC_ISER[1],Local_uint8_t_IntNumber);
    }

}
void M_NVIC_InterruptDisable(uint8_t Local_uint8_t_IntNumber)
{
    if(Local_uint8_t_IntNumber < 32)
    {
        SetBit(NVIC->NVIC_ICER[0],Local_uint8_t_IntNumber);
    }
    else if(Local_uint8_t_IntNumber < 60)
    {
        Local_uint8_t_IntNumber-=32;
        SetBit(NVIC->NVIC_ICER[1],Local_uint8_t_IntNumber);
    }

}
void M_NVIC_InterruptPendingSet(uint8_t Local_uint8_t_IntNumber)
{
    if(Local_uint8_t_IntNumber < 32)
    {
        SetBit(NVIC->NVIC_ISPR[0],Local_uint8_t_IntNumber);
    }
    else if(Local_uint8_t_IntNumber < 60)
    {
        Local_uint8_t_IntNumber-=32;
        SetBit(NVIC->NVIC_ISPR[1],Local_uint8_t_IntNumber);
    }
}
void M_NVIC_InterruptPendingClear(uint8_t Local_uint8_t_IntNumber)
{
   if(Local_uint8_t_IntNumber < 32)
    {
        SetBit(NVIC->NVIC_ICPR[0],Local_uint8_t_IntNumber);
    }
    else if(Local_uint8_t_IntNumber < 60)
    {
        Local_uint8_t_IntNumber-=32;
        SetBit(NVIC->NVIC_ICPR[1],Local_uint8_t_IntNumber);
    }
   
}
uint8_t   M_NVIC_InterrruptGetActiveBit(uint8_t Local_uint8_t_IntNumber)
{
	uint8_t Local_uint8_t_Bit;
    if(Local_uint8_t_IntNumber < 32)
    {
        Local_uint8_t_Bit = GetBit(NVIC->NVIC_IABR[0],Local_uint8_t_IntNumber);
    }
    else if(Local_uint8_t_IntNumber < 60)
    {
        Local_uint8_t_IntNumber-=32;
        Local_uint8_t_Bit = GetBit(NVIC->NVIC_IABR[1],Local_uint8_t_IntNumber);
    }
    return Local_uint8_t_Bit;
}
