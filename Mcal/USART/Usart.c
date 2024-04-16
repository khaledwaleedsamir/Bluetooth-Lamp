/**
  ******************************************************************************
  * @file    Usart.c
  * @brief   Main file for USART_1 module. (Asynchronous mode only)
  * @author  Khaled Waleed Samir
  * @version 0.1
  ******************************************************************************
  */
 #include "Usart.h"

void M_Usart_Init(uint8_t baudRate, uint8_t dataBits, uint8_t parityBits, uint8_t stopBits)
{
  /* Setting GPIO / Alternate function I/O */
  M_RCC_EnableClock(RCC_APB2, RCC_APB2_IOPAEN);
  M_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN_9, AFIO_OUTPUT_PUSH_PULL_2MHZ);
  M_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN_10, GPIO_INPUT_PULL_UP_DOWN);
  
  /* USART_1 Clock Enable */
  M_RCC_EnableClock(RCC_APB2, RCC_APB2_USART1EN);


  /* Baud Rate Calculations 
  float USARTDIV = ( F_CLK / (float)(baudRate*16) );
  uint16_t Div_Mantissa = (uint16_t)USARTDIV;
  float fractional_part = USARTDIV - Div_Mantissa;
  uint8_t  Div_Fraction = (uint8_t)(fractional_part*16); */


  /* Setting The value of the Baud Rate Register based on Baud Rate required using the previous formula */
  switch(baudRate)
  {
    case _9600_BAUD_RATE:   USART_BRR |= 0x341; break;
    case _19200_BAUD_RATE:  USART_BRR |= 0x1A1; break;
    case _38400_BAUD_RATE:  USART_BRR |= 0xD0; break;
    case _57600_BAUD_RATE:  USART_BRR |= 0x8B; break;
    case _115200_BAUD_RATE: USART_BRR |= 0x45; break;
    default:                                    break;
  }

  /* Setting Data bits Length*/
  switch(dataBits)
  {
    case _8_DATA_BITS: ClrBit(USART_CR1,12); break;
    case _9_DATA_BITS: SetBit(USART_CR1,12); break;
    default:                                 break;
  }

  /* Setting Parity Bits */
  switch(parityBits)
  {
    case PARITY_DISABLED: ClrBit(USART_CR1,10);                  break;
    case PARITY_ODD: SetBit(USART_CR1,10); SetBit(USART_CR1,9);  break;
    case PARITY_EVEN: SetBit(USART_CR1,10); ClrBit(USART_CR1,9); break;
    default:                                                     break;
  }

    /* Setting Number of stop bits */
  switch(stopBits)
  {
    case _1_STOP_BITS: ClrBit(USART_CR2,12); ClrBit(USART_CR2,13); break;
    case _2_STOP_BITS: ClrBit(USART_CR2,12); SetBit(USART_CR2,13); break;
    default:                                                       break;
  }

  /* In asynchronous mode, the following bits must be kept cleared:
  - LINEN and CLKEN bits in the USART_CR2 register,
  - SCEN, HDSEL and IREN  bits in the USART_CR3 register.*/
  ClrBit(USART_CR2, 14); ClrBit (USART_CR2,11);
  ClrBit(USART_CR3,5); ClrBit(USART_CR3,3); ClrBit(USART_CR3,1);

  SetBit(USART_CR1,3); /* Enable Tx */
  SetBit(USART_CR1,2); /* Enable Rx */

  /* Enable Rx Interrupt */
  M_NVIC_InterruptEnable(VT_USART1);
  SetBit(USART_CR1,5);

  /* Enabling USART_2 */
  SetBit(USART_CR1,13);

}

void M_Usart_Tx(uint8_t data)
{
  USART_DR = data;
  while(!GetBit(USART_SR,7)); /* Wait untill transmission is complete*/
}

uint8_t M_Usart_Rx(void)
{
  while(!GetBit(USART_SR,5)); /* Wait till data is ready to be read */
  uint8_t data = (uint8_t)(USART_DR & (uint8_t)0x00FF);
  return data;
}


void M_Usart_setCallback(void (*func_ptr)(void))
{
	 Usart1_Callback = func_ptr;
}

void USART1_IRQHandler(void)
{
  /* Check Interrupt Source */
		if(GetBit(USART_SR,5))
		{
      /* Clear Interrupt Flag */
			//ClrBit(USART_SR,5);
			if (Usart1_Callback != 0)	 //Check if a Function is Assigned to Callback
			{
				(*(Usart1_Callback))();
			}
		}
}  

