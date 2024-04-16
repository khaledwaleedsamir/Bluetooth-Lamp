/**
  ******************************************************************************
  * @file    HC-05.c
  * @brief   Main file for bluetooth module HC-05.
  * @author  Khaled Waleed Samir
  * @version 0.1
  ******************************************************************************
  */ 
#include "HC-05.h"

void HC_05_Init(void)
{ 
  M_Usart_Init(_9600_BAUD_RATE, _8_DATA_BITS, PARITY_DISABLED, _1_STOP_BITS);
}
void HC_05_Tx(uint8_t data)
{
	M_Usart_Tx(data);
}
uint8_t HC_05_Rx(void)
{
	return M_Usart_Rx();
}
