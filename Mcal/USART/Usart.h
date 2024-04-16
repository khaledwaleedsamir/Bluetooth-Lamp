/**
  ******************************************************************************
  * @file    Usart.h
  * @brief   Header file for USART_1 nodule.
  * @author  Khaled Waleed Samir
  * @version 0.1
  ******************************************************************************
  */

 /**********************************************************************************************************************
  * INCLUDES
 *********************************************************************************************************************/
#include "Usart_Regs.h"
#include "StdTypes.h"
#include "Bitmaths.h"
#include "GPIO.h"
#include "NVIC.h"
#include "RCC.h"

/**********************************************************************************************************************
  * Callback Function
 *********************************************************************************************************************/
static void (*volatile Usart1_Callback)(void) =  0;

/**********************************************************************************************************************
 * MACROS
 *********************************************************************************************************************/
#define F_CLK 8000000   /* not used BRR value pre calculated for the common baud rates */
#define _8_DATA_BITS 8
#define _9_DATA_BITS 9
#define _1_STOP_BITS 1
#define _2_STOP_BITS 2
#define PARITY_DISABLED 0
#define PARITY_ODD 1
#define PARITY_EVEN 2

/* Common Baud Rates */
#define _9600_BAUD_RATE   1
#define _19200_BAUD_RATE  2
#define _38400_BAUD_RATE  3
#define _57600_BAUD_RATE  4
#define _115200_BAUD_RATE 5
/**********************************************************************************************************************
 * Functions Prototypes
 *********************************************************************************************************************/
void M_Usart_Init(uint8_t baudRate, uint8_t bitsPerframe, uint8_t parityBits, uint8_t stopBits);
void M_Usart_Tx(uint8_t data);
uint8_t M_Usart_Rx(void);
void M_Usart_setCallback(void (*func_ptr)(void));
