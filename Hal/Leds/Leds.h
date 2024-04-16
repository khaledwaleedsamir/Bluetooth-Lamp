/********************************************************************************
  * @file    Leds.h
  * @brief   Header file for LEDs driver.
  * @author  Khaled Waleed
  * @version 0.1
  ******************************************************************************
  * 1. Configuration:
  * ----------------------------------------------------------------------------
  * To configure the LEDs driver, you need to provide the LED_Typedef structure(s)
  * specifying the GPIO port and pin for each LED. This is typically done by
  * creating individual LED_Typedef structures.
  *
  * Example:
  * - For a single LED:
  *   LED_Typedef myLed;
  *   myLed.LED_PORT = GPIO_PORT_A;
  *   myLed.LED_PIN = GPIO_PIN_5;
  *
  * 2. Initialization:
  * ----------------------------------------------------------------------------
  * Initialize the LEDs by calling the Led_Init function with the provided LED configuration(s). 
  * This function configures the GPIO pins for LED control and should be  called once during 
  * the system setup.
  *
  * Example:
  * - For a single LED:
  *   Led_Init(&myLed);
  *
  * 3. Basic Usage:
  * ----------------------------------------------------------------------------
  * After initializing the LEDs, you can control their state using the following
  * functions:
  * - Led_On: Turns the LED on.
  * - Led_Off: Turns the LED off.
  * - Led_Toggle: Toggles the state of an LED.
  *
  * Example:
  * Led_On(&myLed); // Turns on the LED
  * Led_Off(&myLed); // Turns off the LED
  * Led_Toggle(&myLed); // Toggles the LED's state
  ******************************************************************************
  */

#ifndef _LEDS_H_
#define _LEDS_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "StdTypes.h"
#include "GPIO.h"
#include "Systick.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
	uint8_t LED_PORT;          /* GPIO port for the LED
	                                    @note acceptable values are GPIO_PORTx
	                                     where x can be (A..D)   */

	uint8_t LED_PIN;                /* LED Pin
	                                    @note acceptable values are GPIO_PIN_x
	                                      where x can be (0..15) */
} LED_Typedef;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Led_Init(LED_Typedef *LedConfigStruct);
void Led_On(LED_Typedef *LedConfigStruct);
void Led_Off(LED_Typedef *LedConfigStruct);
void Led_Toggle(LED_Typedef *LedConfigStruct);

#endif /*_LEDS_H_*/




