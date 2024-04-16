/**
  ******************************************************************************
  * @file    Lcd.h
  * @brief   Header file for LCD driver LCD : (1602A).
  * @author  Khaled Waleed
  * @version 0.1
  ******************************************************************************
  * @notes
  *   This is a generic LCD driver to setup any number of LCDs.
  *
  ******************************************************************************
  * 1. Configuration:
  * ----------------------------------------------------------------------------
  *   - Create a structure of LCD_Typedef and initialize it with the desired data and
  *     control pins/ports and the LCD mode (modes available 4 bit or 8 bit), for 4 bit
  *     mode you use 4 data pins only and you must initialize (D4..D7) LCD data pins.
  *
  * 2. Initialization:
  * ----------------------------------------------------------------------------
  *   - Call the "Lcd_Init" function with a properly configured "LCD_Typedef" structure
  *     to initialize the LCD driver.
  *
  * 3. Basic Usage:
  * ----------------------------------------------------------------------------
  *   - Use the provided functions to display characters, strings, numbers, or control
  *     the LCD.
  *
  ******************************************************************************
  */
#ifndef LCD_H_
#define LCD_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "StdTypes.h"
#include "GPIO.h"
#include "Systick.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*LCD mode Macros*/
#define _8_BIT_MODE                 1
#define _4_BIT_MODE                 2

/*LCD Commands Macros*/
#define LCD_DISPLAY_OFF_CURSOR_OFF   0x08
#define LCD_DISPLAY_ON_CURSOR_OFF    0x0C
#define LCD_DISPLAY_OFF_CURSOR_ON    0x0A
#define LCD_DISPLAY_ON_CURSOR_BLINK  0x0F
#define LCD_CLEAR                    0x01
#define LCD_NEXT_LINE                0xC0
#define LCD_RETURN_HOME              0x02
#define LCD_8BIT_MODE                0x38
#define LCD_4BIT_MODE_1              0x33
#define LCD_4BIT_MODE_2              0x32
#define LCD_4BIT_MODE_3              0x28
#define LCD_FIRST_LINE_POSITION_0    0x80
#define LCD_SECOND_LINE_POSITION_0   0xC0
#define NULL_ '\0'

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
	uint8_t LCD_Data_Port;          /*GPIO port for the Data pins in the LCD
	                                        @note acceptable values are GPIO_PORTx
	                                         where x can be (A..C) */

	uint8_t LCD_Control_Port;       /*GPIO port for the Control pins in the LCD
	                                        @note acceptable values are GPIOx
	                                         where x can be (A..C) */

	uint8_t LCD_Data_Pin_0;              /*LCD Data Pin 0 (D0)
	                                        @note acceptable values are GPIO_PIN_x
	                                         where x can be (0..15) */

	uint8_t LCD_Data_Pin_1;              /*LCD Data Pin 1 (D1)
	                                        @note acceptable values are GPIO_PIN_x
	                                         where x can be (0..15) */

	uint8_t LCD_Data_Pin_2;              /*LCD Data Pin 2 (D2)
	                                        @note acceptable values are GPIO_PIN_x
	                                         where x can be (0..15) */

	uint8_t LCD_Data_Pin_3;              /*LCD Data Pin 3 (D3)
	                                        @note acceptable values are GPIO_PIN_x
	                                         where x can be (0..15) */

	uint8_t LCD_Data_Pin_4;              /*LCD Data Pin 4 (D4)
	                                        @note acceptable values are GPIO_PIN_x
	                                         where x can be (0..15) */

	uint8_t LCD_Data_Pin_5;              /*LCD Data Pin 5 (D5)
	                                        @note acceptable values are GPIO_PIN_x
	                                         where x can be (0..15) */

	uint8_t LCD_Data_Pin_6;              /*LCD Data Pin 6 (D6)
	                                        @note acceptable values are GPIO_PIN_x
	                                         where x can be (0..15) */

	uint8_t LCD_Data_Pin_7;              /*LCD Data Pin 7 (D7)
	                                        @note acceptable values are GPIO_PIN_x
	                                         where x can be (0..15) */

	uint8_t LCD_RS_Pin;                  /*LCD Register select Control Pin (RS)
	                                        @note acceptable values are GPIO_PIN_x
	                                         where x can be (0..15) */

	uint8_t LCD_RW_Pin;                  /*LCD Read/Write Control Pin (RW)
	                                        @note acceptable values are GPIO_PIN_x
	                                         where x can be (0..15) */

	uint8_t LCD_EN_Pin;                  /*LCD Enable Control Pin (EN)
	                                        @note acceptable values are GPIO_PIN_x
	                                         where x can be (0..15) */

	uint8_t LCD_Mode;                     /*LCD Mode selection
	                                        @note acceptable values are
	                                         (++) _4_BIT_MODE
	                                         (++) _8_BIT_MODE       */

} LCD_Typedef;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Lcd_Init(LCD_Typedef *LcdConfig);
void Lcd_WriteCharacter(LCD_Typedef *LcdConfig, uint8_t Char);
void Lcd_WriteCommand(LCD_Typedef *LcdConfig, uint8_t Command);
void Lcd_WriteString(LCD_Typedef *LcdConfig, uint8_t* Ptr);
void Lcd_WriteNumber(LCD_Typedef *LcdConfig, int32_t Number);
void Lcd_Clear(LCD_Typedef *LcdConfig);
void Lcd_NextLine(LCD_Typedef *LcdConfig);
void Lcd_Goto(LCD_Typedef *LcdConfig, uint8_t Line, uint8_t Position);
void Lcd_WriteStringAt(LCD_Typedef *LcdConfig, uint8_t Line, uint8_t Position, uint8_t* Ptr);
void Lcd_WriteNumberAt(LCD_Typedef *LcdConfig, uint8_t Line, uint8_t Position, int32_t Number);
void Lcd_Cursor(LCD_Typedef *LcdConfig, uint8_t CursorState);

#endif /* LCD_H_ */
