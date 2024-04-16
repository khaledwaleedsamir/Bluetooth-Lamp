/**
  ******************************************************************************
  * @file    GPIO.h
  * @brief   Header file for GPIO module.
  * @author  Khaled Waleed Samir
  * @version 0.1
  ******************************************************************************
  */

#ifndef GPIO_H_
#define GPIO_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "GPIO_Regs.h"
#include "Bitmaths.h"
#include "StdTypes.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* PORTS MACROS*/
#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2

/* PINS MACROS*/
#define GPIO_PIN_0   0
#define GPIO_PIN_1   1
#define GPIO_PIN_2   2
#define GPIO_PIN_3   3
#define GPIO_PIN_4   4
#define GPIO_PIN_5   5
#define GPIO_PIN_6   6
#define GPIO_PIN_7   7
#define GPIO_PIN_8   8
#define GPIO_PIN_9   9
#define GPIO_PIN_10 10
#define GPIO_PIN_11 11
#define GPIO_PIN_12 12
#define GPIO_PIN_13 13
#define GPIO_PIN_14 14
#define GPIO_PIN_15 15

/* PIN VALUES MACROS*/
#define GPIO_HIGH 1
#define GPIO_LOW  0

/* INPUT MODES MACROS*/
#define GPIO_INPUT_ANALOG       0b0000
#define GPIO_INPUT_FLOATING     0b0100
#define GPIO_INPUT_PULL_UP_DOWN 0b1000

/* OUTPUT MODES MACROS BASED ON SPEED*/

/* OUTPUT MODES 10MHz SPEED*/
#define GPIO_OUTPUT_PUSH_PULL_10MHZ  0b0001
#define GPIO_OUTPUT_OPEN_DRAIN_10MHZ 0b0101
#define AFIO_OUTPUT_PUSH_PULL_10MHZ  0b1001
#define AFIO_OUTPUT_OPEN_DRAIN_10MHZ 0b1101

/* OUTPUT MODES 2MHz SPEED*/
#define GPIO_OUTPUT_PUSH_PULL_2MHZ   0b0010
#define GPIO_OUTPUT_OPEN_DRAIN_2MHZ  0b0110
#define AFIO_OUTPUT_PUSH_PULL_2MHZ   0b1010
#define AFIO_OUTPUT_OPEN_DRAIN_2MHZ  0b1110

/* OUTPUT MODES 50MHz SPEED*/
#define GPIO_OUTPUT_PUSH_PULL_50MHZ  0b0011
#define GPIO_OUTPUT_OPEN_DRAIN_50MHZ 0b0111
#define AFIO_OUTPUT_PUSH_PULL_50MHZ  0b1011
#define AFIO_OUTPUT_OPEN_DRAIN_50MHZ 0b1111


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 void M_GPIO_SetPinMode(uint8_t Local_uint8_t_Port, uint8_t Local_uint8_t_Pin, uint8_t Local_uint8_t_mode);
 void M_GPIO_SetPinValue(uint8_t Local_uint8_t_Port, uint8_t Local_uint8_t_Pin, uint8_t Local_uint8_t_Value);
 uint8_t   M_GPIO_GetPinValue(uint8_t Local_uint8_t_Port, uint8_t Local_uint8_t_Pin);
 void M_GPIO_TogglePin(uint8_t Local_uint8_t_Port, uint8_t Local_uint8_t_Pin);


#endif /* GPIO_H_ */
 
