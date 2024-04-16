/**
  ******************************************************************************
  * @file    Relay.h
  * @brief   Header file for Relay module.
  * @author  Khaled Waleed Samir
  * @version 0.1
  ******************************************************************************
  */
 
#ifndef RELAY_H_
#define RELAY_H_
 /**********************************************************************************************************************
 * Includes
 *********************************************************************************************************************/
#include "StdTypes.h"
#include "GPIO.h"

/**********************************************************************************************************************
 *             Configurations (Configure relay port and pin from here, ONLY edit the following section)
 *********************************************************************************************************************/

#define RELAY_PORT              GPIO_PORTA   /* GPIO port for the Relay Control pin
	                                           @note acceptable values are GPIO_PORTx where x can be (A..C) */

#define RELAY_CONTROL_PIN       GPIO_PIN_7   /* GPIO Relay Control pin
	                                           @note acceptable values are GPIO_PIN_x where x can be (0..15) */

#define RELAY_MODE              ACTIVE_HIGH  /* GPIO Relay Mode
	                                           @note acceptable values are ACTIVE_HIGH and ACTIVE_LOW 
                                               Configure the relay module or check which mode does it operate on
                                               and select it here . */

 /**********************************************************************************************************************
 * Macros
 *********************************************************************************************************************/
#define ACTIVE_HIGH 1
#define ACTIVE_LOW  0 

 /**********************************************************************************************************************
 * Functions Prototypes
 *********************************************************************************************************************/
void Relay_Init(void);
void Relay_On(void);
void Relay_Off(void);
void Relay_Toggle(void);




#endif /* RELAY_H_ */
