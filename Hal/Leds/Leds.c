/**
  ******************************************************************************
  * @file    Leds.c
  * @brief   Source file for the LEDs driver.
  * @author  Khaled Waleed 
  * @version 0.1
  ******************************************************************************
  */

/* Includes */
#include "Leds.h"

/**
  * @brief  Initializes an individual LED specified by the provided LED configuration.
  * @param  LedConfigStruct: Pointer to the LED_Typedef structure that defines the LED's port and pin.
  * @retval None
  */
void Led_Init(LED_Typedef *LedConfigStruct)
{
	M_GPIO_SetPinMode(LedConfigStruct->LED_PORT, LedConfigStruct->LED_PIN, GPIO_OUTPUT_PUSH_PULL_2MHZ);
}

/**
  * @brief  Turns on an individual LED specified by the provided LED configuration.
  * @param  LedConfigStruct: Pointer to the LED_Typedef structure that defines the LED's port and pin.
  * @retval None
  */
void Led_On(LED_Typedef *LedConfigStruct)
{
	M_GPIO_SetPinValue(LedConfigStruct->LED_PORT, LedConfigStruct->LED_PIN, GPIO_HIGH);
}

/**
  * @brief  Turns off an individual LED specified by the provided LED configuration.
  * @param  LedConfigStruct: Pointer to the LED_Typedef structure that defines the LED's port and pin.
  * @retval None
  */
void Led_Off(LED_Typedef *LedConfigStruct)
{
	M_GPIO_SetPinValue(LedConfigStruct->LED_PORT, LedConfigStruct->LED_PIN, GPIO_LOW);
}

/**
  * @brief  Toggles the state of an individual LED specified by the provided LED configuration.
  * @param  LedConfigStruct: Pointer to the LED_Typedef structure that defines the LED's port and pin.
  * @retval None
  */
void Led_Toggle(LED_Typedef *LedConfigStruct)
{
	M_GPIO_TogglePin(LedConfigStruct->LED_PORT, LedConfigStruct->LED_PIN);
}
