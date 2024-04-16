/**
  ******************************************************************************
  * @file    main.c
  * @brief   Main application file.
  * @author  Khaled Waleed Samir
  * @version 0.1
  ******************************************************************************
  */

/**********************************************************************************************************************
 * Includes
 *********************************************************************************************************************/
#include <stdint.h>
#include "Bitmaths.h"
#include "StdTypes.h"
#include "GPIO.h"
#include "Systick.h"
#include "RCC.h"
#include "Lcd.h"
#include "Leds.h"
#include "HC-05.h"
#include "Relay.h"
/**********************************************************************************************************************
 * Callback functions
 *********************************************************************************************************************/
void Usart_Callback(void);

/**********************************************************************************************************************
 * Global Variables and datatypes initalization
 *********************************************************************************************************************/
LCD_Typedef LCD1 = {0};
LED_Typedef blueLed = {0};

/**********************************************************************************************************************
 * MAIN FUNCTION
 *********************************************************************************************************************/
int main(void)
{
  /* Clocks Enable */
  M_RCC_InitSysClock();
  M_RCC_EnableClock(RCC_APB2, RCC_APB2_IOPAEN); // PORT A Clock Enable
  M_RCC_EnableClock(RCC_APB2, RCC_APB2_IOPBEN); // PORT B Clock Enable
  M_RCC_EnableClock(RCC_APB2, RCC_APB2_IOPCEN);


  /* LEDs Init */
  blueLed.LED_PORT = GPIO_PORTB;
  blueLed.LED_PIN = GPIO_PIN_7;
  Led_Init(&blueLed);

  /* Bluetooth Module Init */
  HC_05_Init();
  M_Usart_setCallback(Usart_Callback);

  /* Relay Init */
  Relay_Init();

  /* LCD Init */  
  LCD1.LCD_Mode = _4_BIT_MODE;
  LCD1.LCD_Control_Port = GPIO_PORTB;
  LCD1.LCD_Data_Port = GPIO_PORTA;
  LCD1.LCD_RS_Pin = GPIO_PIN_12;
  LCD1.LCD_RW_Pin = GPIO_PIN_13;
  LCD1.LCD_EN_Pin = GPIO_PIN_14;
  LCD1.LCD_Data_Pin_4 = GPIO_PIN_0;
  LCD1.LCD_Data_Pin_5 = GPIO_PIN_1;
  LCD1.LCD_Data_Pin_6 = GPIO_PIN_2;
  LCD1.LCD_Data_Pin_7 = GPIO_PIN_3;
  Lcd_Init(&LCD1);
  uint8_t WelcomeMsg [] = "Init Done";
  Lcd_WriteString(&LCD1, WelcomeMsg);
  Lcd_Clear(&LCD1);
  while(1)
  {
  }
}
/**********************************************************************************************************************
 * Usart_Callback function implementation
 *********************************************************************************************************************/
void Usart_Callback(void)
{
  uint8_t data = HC_05_Rx();
  if(data == 'Y')
  {
    uint8_t Msg [] = "    Lamp ON";
    Led_On(&blueLed);
    Relay_On();
    Lcd_WriteString(&LCD1, Msg);
  }
  else if(data == 'N')
  {
    uint8_t Msg [] = "    Lamp OFF";
    Led_Off(&blueLed);
    Relay_Off();
    Lcd_WriteString(&LCD1, Msg);
  }
}
