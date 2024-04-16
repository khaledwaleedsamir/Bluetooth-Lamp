/**
  ******************************************************************************
  * @file    Lcd.c
  * @brief   Source file for the LCD driver LCD : (1602A)
  * @author  Khaled Waleed
  * @version 0.1
  ******************************************************************************
  */

/* Includes */
#include "Lcd.h"

/**
  * @brief  Initializes the LCD module with the provided configuration.
  * @note   This function should be called to set up the LCD module before using it.
  * @param  LcdConfig: A pointer to the configuration structure of the LCD module.
  * @retval None
  */
void Lcd_Init(LCD_Typedef *LcdConfig)
{
	switch(LcdConfig->LCD_Mode)
	{
	case _8_BIT_MODE:
		/* Initializing LCD Data Port 0*/
        M_GPIO_SetPinMode(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_0, GPIO_OUTPUT_PUSH_PULL_2MHZ);

		/* Initializing LCD Data Port 1*/
		M_GPIO_SetPinMode(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_1, GPIO_OUTPUT_PUSH_PULL_2MHZ);

		/* Initializing LCD Data Port 2*/
		M_GPIO_SetPinMode(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_2, GPIO_OUTPUT_PUSH_PULL_2MHZ);

		/* Initializing LCD Data Port 3*/
		M_GPIO_SetPinMode(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_3, GPIO_OUTPUT_PUSH_PULL_2MHZ);

		/* Initializing LCD Data Port 4*/
		M_GPIO_SetPinMode(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_4, GPIO_OUTPUT_PUSH_PULL_2MHZ);

		/* Initializing LCD Data Port 5*/
		M_GPIO_SetPinMode(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_5, GPIO_OUTPUT_PUSH_PULL_2MHZ);

		/* Initializing LCD Data Port 6*/
		M_GPIO_SetPinMode(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_6, GPIO_OUTPUT_PUSH_PULL_2MHZ);

		/* Initializing LCD Data Port 7*/
		M_GPIO_SetPinMode(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_7, GPIO_OUTPUT_PUSH_PULL_2MHZ);

		/* Initializing LCD Control	 Port RS pin*/
        M_GPIO_SetPinMode(LcdConfig->LCD_Control_Port, LcdConfig->LCD_RS_Pin, GPIO_OUTPUT_PUSH_PULL_2MHZ);

		/* Initializing LCD Control	 Port RW pin*/
		M_GPIO_SetPinMode(LcdConfig->LCD_Control_Port, LcdConfig->LCD_RW_Pin, GPIO_OUTPUT_PUSH_PULL_2MHZ);

		/* Initializing LCD Control	 Port EN pin*/
		M_GPIO_SetPinMode(LcdConfig->LCD_Control_Port, LcdConfig->LCD_EN_Pin, GPIO_OUTPUT_PUSH_PULL_2MHZ);

        M_GPIO_SetPinValue(LcdConfig->LCD_Control_Port, LcdConfig->LCD_RW_Pin, GPIO_LOW);
		M_SysTick_Delay(1000);

		Lcd_WriteCommand(LcdConfig, LCD_8BIT_MODE);
		Lcd_WriteCommand(LcdConfig, LCD_DISPLAY_ON_CURSOR_OFF);
		Lcd_WriteCommand(LcdConfig, LCD_CLEAR);
		Lcd_WriteCommand(LcdConfig, LCD_RETURN_HOME);
		break;
	case _4_BIT_MODE:
		/* Initializing LCD Data Port 4*/
		M_GPIO_SetPinMode(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_4, GPIO_OUTPUT_PUSH_PULL_2MHZ);

		/* Initializing LCD Data Port 5*/
		M_GPIO_SetPinMode(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_5, GPIO_OUTPUT_PUSH_PULL_2MHZ);

		/* Initializing LCD Data Port 6*/
		M_GPIO_SetPinMode(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_6, GPIO_OUTPUT_PUSH_PULL_2MHZ);

		/* Initializing LCD Data Port 7*/
		M_GPIO_SetPinMode(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_7, GPIO_OUTPUT_PUSH_PULL_2MHZ);

		/* Initializing LCD Control	 Port RS pin*/
		M_GPIO_SetPinMode(LcdConfig->LCD_Control_Port, LcdConfig->LCD_RS_Pin, GPIO_OUTPUT_PUSH_PULL_2MHZ);

		/* Initializing LCD Control	 Port RW pin*/
		M_GPIO_SetPinMode(LcdConfig->LCD_Control_Port, LcdConfig->LCD_RW_Pin, GPIO_OUTPUT_PUSH_PULL_2MHZ);

		/* Initializing LCD Control	 Port EN pin*/
		M_GPIO_SetPinMode(LcdConfig->LCD_Control_Port, LcdConfig->LCD_EN_Pin, GPIO_OUTPUT_PUSH_PULL_2MHZ);

		M_GPIO_SetPinValue(LcdConfig->LCD_Control_Port, LcdConfig->LCD_RW_Pin, GPIO_LOW);
		M_SysTick_Delay(1000);
		Lcd_WriteCommand(LcdConfig, LCD_4BIT_MODE_1);
		Lcd_WriteCommand(LcdConfig, LCD_4BIT_MODE_2);
		Lcd_WriteCommand(LcdConfig, LCD_4BIT_MODE_3);
		Lcd_WriteCommand(LcdConfig, LCD_DISPLAY_ON_CURSOR_OFF);
		Lcd_WriteCommand(LcdConfig, LCD_CLEAR);
		Lcd_WriteCommand(LcdConfig, LCD_RETURN_HOME);
		break;
	default:
		break;

	}
}

/**
  * @brief  Write a character to the LCD in either 4-bit or 8-bit mode based on configuration struct.
  * @param  LcdConfig: Pointer to an LCD configuration structure.
  * @param  Char: The character to be written to the LCD.
  * @retval None
  */
void Lcd_WriteCharacter(LCD_Typedef *LcdConfig, uint8_t Char)
{
	switch(LcdConfig->LCD_Mode)
	{
	case _8_BIT_MODE:
		/* Set the RS (Register Select) pin to indicate data write.*/
		M_GPIO_SetPinValue(LcdConfig->LCD_Control_Port, LcdConfig->LCD_RS_Pin, GPIO_HIGH);

		/*Getting the value of the corresponding data pin based on Char by AND operation of the Char
		 * and the 1 shifted left to the data pin location to isolate that specific pin and then shifting
		 * it to right by the same amount to get a 1 or 0 to set or reset. */
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_7, (Char & 1<<7)>>7);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_6, (Char & 1<<6)>>6);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_5, (Char & 1<<5)>>5);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_4, (Char & 1<<4)>>4);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_3, (Char & 1<<3)>>3);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_2, (Char & 1<<2)>>2);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_1, (Char & 1<<1)>>1);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_0, (Char & 1<<0)>>0);

		/* Set the enable (EN) pin to signal the LCD to read the data.*/
		M_GPIO_SetPinValue(LcdConfig->LCD_Control_Port, LcdConfig->LCD_EN_Pin, GPIO_HIGH);

		M_SysTick_Delay(1); /* Delay to make sure data is read by the LCD. */

		/* Clear the enable indicating data transfer is complete. */
		M_GPIO_SetPinValue(LcdConfig->LCD_Control_Port, LcdConfig->LCD_EN_Pin, GPIO_LOW);

		M_SysTick_Delay(5); /* Delay of 5 milliseconds for LCD processing and stability. */

		break;
	case _4_BIT_MODE:
		M_GPIO_SetPinValue(LcdConfig->LCD_Control_Port, LcdConfig->LCD_RS_Pin, GPIO_HIGH);

		/*Getting the value of the corresponding data pin based on Char by AND operation of the Char
		 * and the 1 shifted left to the data pin location to isolate that specific pin and then shifting
		 * it to right by the same amount to get a 1 or 0 to set or reset. */
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_7, (Char & 1<<7)>>7);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_6, (Char & 1<<6)>>6);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_5, (Char & 1<<5)>>5);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_4, (Char & 1<<4)>>4);


		/* Set the enable (EN) pin to signal the LCD to read the data.*/
		M_GPIO_SetPinValue(LcdConfig->LCD_Control_Port, LcdConfig->LCD_EN_Pin, GPIO_HIGH);

		M_SysTick_Delay(1); /* Delay to make sure data is read by the LCD. */

		/* Clear the enable indicating data transfer is complete. */
		M_GPIO_SetPinValue(LcdConfig->LCD_Control_Port, LcdConfig->LCD_EN_Pin, GPIO_LOW);

		M_SysTick_Delay(5); /* Delay of 5 milliseconds for LCD processing and stability. */

		/*Sending the other LSB of the Char by doing the same process as the MSB but only changing the
		 * amount of shifting.*/
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_7, (Char & 1<<3)>>3);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_6, (Char & 1<<2)>>2);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_5, (Char & 1<<1)>>1);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_4, (Char & 1<<0)>>0);

		/* Set the enable (EN) pin to signal the LCD to read the data.*/
		M_GPIO_SetPinValue(LcdConfig->LCD_Control_Port, LcdConfig->LCD_EN_Pin, GPIO_HIGH);

		M_SysTick_Delay(1); /* Delay to make sure data is read by the LCD. */

		/* Clear the enable indicating data transfer is complete. */
		M_GPIO_SetPinValue(LcdConfig->LCD_Control_Port, LcdConfig->LCD_EN_Pin, GPIO_LOW);

		M_SysTick_Delay(5); /* Delay of 5 milliseconds for LCD processing and stability. */
		break;
	default:
		break;
	}
}

/**
  * @brief  Send a Command to the LCD in either 4-bit or 8-bit mode based on configuration struct.
  * @param  LcdConfig: Pointer to an LCD configuration structure.
  * @param  Command: The Command to be sent to the LCD.
  * @retval None
  */
void Lcd_WriteCommand(LCD_Typedef *LcdConfig, uint8_t Command)
{
	switch(LcdConfig->LCD_Mode)
	{
	case _8_BIT_MODE:

		/* Set the RS Pin to low indicating that a command is being sent to the LCD. */
		M_GPIO_SetPinValue(LcdConfig->LCD_Control_Port, LcdConfig->LCD_RS_Pin, GPIO_LOW);

		/*Getting the value of the corresponding data pin based on command by AND operation of the command
		 * and the 1 shifted left to the data pin location to isolate that specific pin and then shifting
		 * it to right by the same amount to get a 1 or 0 to set or reset. */
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_7, (Command & 1<<7)>>7);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_6, (Command & 1<<6)>>6);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_5, (Command & 1<<5)>>5);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_4, (Command & 1<<4)>>4);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_3, (Command & 1<<3)>>3);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_2, (Command & 1<<2)>>2);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_1, (Command & 1<<1)>>1);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_0, (Command & 1<<0)>>0);

		/* Set the enable (EN) pin to signal the LCD to read the data.*/
		M_GPIO_SetPinValue(LcdConfig->LCD_Control_Port, LcdConfig->LCD_EN_Pin, GPIO_HIGH);

		M_SysTick_Delay(1); /* Delay to make sure data is read by the LCD. */

		/* Clear the enable indicating data transfer is complete. */
		M_GPIO_SetPinValue(LcdConfig->LCD_Control_Port, LcdConfig->LCD_EN_Pin, GPIO_LOW);

		M_SysTick_Delay(5); /* Delay of 5 milliseconds for LCD processing and stability. */
		break;
	case _4_BIT_MODE:

		/* Set the RS Pin to low indicating that a command is being sent to the LCD. */
		M_GPIO_SetPinValue(LcdConfig->LCD_Control_Port, LcdConfig->LCD_RS_Pin, GPIO_LOW);

		/*Getting the value of the corresponding data pin based on command by AND operation of the command
		 * and the 1 shifted left to the data pin location to isolate that specific pin and then shifting
		 * it to right by the same amount to get a 1 or 0 to set or reset. */
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_7, (Command & 1<<7)>>7);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_6, (Command & 1<<6)>>6);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_5, (Command & 1<<5)>>5);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_4, (Command & 1<<4)>>4);

		/* Set the enable (EN) pin to signal the LCD to read the data.*/
		M_GPIO_SetPinValue(LcdConfig->LCD_Control_Port, LcdConfig->LCD_EN_Pin, GPIO_HIGH);

		M_SysTick_Delay(1); /* Delay to make sure data is read by the LCD. */

		/* Clear the enable indicating data transfer is complete. */
		M_GPIO_SetPinValue(LcdConfig->LCD_Control_Port, LcdConfig->LCD_EN_Pin, GPIO_LOW);

		M_SysTick_Delay(5); /* Delay of 5 milliseconds for LCD processing and stability. */

		/*Sending the other LSB of the command by doing the same process as the MSB but only changing the
		 * amount of shifting.*/
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_7, (Command & 1<<3)>>3);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_6, (Command & 1<<2)>>2);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_5, (Command & 1<<1)>>1);
		M_GPIO_SetPinValue(LcdConfig->LCD_Data_Port, LcdConfig->LCD_Data_Pin_4, (Command & 1<<0)>>0);

		/* Set the enable (EN) pin to signal the LCD to read the data.*/
		M_GPIO_SetPinValue(LcdConfig->LCD_Control_Port, LcdConfig->LCD_EN_Pin, GPIO_HIGH);

		M_SysTick_Delay(1); /* Delay to make sure data is read by the LCD. */

		/* Clear the enable indicating data transfer is complete. */
		M_GPIO_SetPinValue(LcdConfig->LCD_Control_Port, LcdConfig->LCD_EN_Pin, GPIO_LOW);

		M_SysTick_Delay(5); /* Delay of 5 milliseconds for LCD processing and stability. */
		break;
	default:
		break;
	}
}

/**
  * @brief  Writes a null-terminated string to the LCD display.
  * @note   This function sends each character of the provided string to the LCD.
  * @param  LcdConfig: A pointer to the configuration structure of the LCD module.
  * @param  Ptr: A pointer to the null-terminated string to be displayed on the LCD.
  * @retval None
  */
void Lcd_WriteString(LCD_Typedef *LcdConfig, uint8_t* Ptr)
{
	uint8_t Counter = 0;
	while(Ptr[Counter] != NULL_)
	{
		Lcd_WriteCharacter(LcdConfig, Ptr[Counter]);
		Counter++;
	}
}

/**
  * @brief  Writes an integer number to the LCD display.
  * @note   This function displays an integer number on the LCD, including negative values.
  * @param  LcdConfig: A pointer to the configuration structure of the LCD module.
  * @param  Number: The integer number to be displayed on the LCD.
  * @retval None
  */
void Lcd_WriteNumber(LCD_Typedef *LcdConfig, int32_t Number)
{
	/* Array to store individual digits. */
	uint8_t  Arr  [10] = {0};

	/*Counter for iterating through the digits. */
	int8_t   Counter   = 0;

	/* Variable to hold each digit. */
	uint8_t  Digit = 0;

	if(Number == 0 )
	{
		Lcd_WriteCharacter(LcdConfig, '0'); /* Display '0' for zero value. */
	}
	else
	{
		if(Number < 0)
		{
			Lcd_WriteCharacter(LcdConfig, '-');  /* Display '-' for negative numbers. */
			Number = Number * -1; /* Make the number positive. */
		}

		 /* Extract each digit and store in the array. */

		while(Number != 0)
		{
			Digit = Number % 10;
			Arr[Counter] = Digit;
			Counter++;
			Number = Number / 10;
		}
		Counter--;

		/* Display each digit from the array. */
		while(Counter >= 0)
		{
			/* Convert to ASCII and send to LCD to display the digits of the number. */
			Lcd_WriteCharacter(LcdConfig, Arr[Counter] + 48);
			Counter--;
		}
	}
}

/**
  * @brief  Clears the LCD display.
  * @note   This function sends a command to clear the LCD display, removing all content.
  * @param  LcdConfig: A pointer to the configuration structure of the LCD module.
  * @retval None
  */
void Lcd_Clear(LCD_Typedef *LcdConfig)
{
	Lcd_WriteCommand(LcdConfig, LCD_CLEAR);
}

/**
  * @brief  Moves the cursor to the beginning of the next line on the LCD display.
  * @param  LcdConfig: A pointer to the configuration structure of the LCD module.
  * @retval None
  */
void Lcd_NextLine(LCD_Typedef *LcdConfig)
{
	Lcd_WriteCommand(LcdConfig, LCD_NEXT_LINE);
}

/**
  * @brief   Moves the cursor of the LCD to the specified line and position.
  * @param   LcdConfig: A pointer to the configuration structure of the LCD module.
  * @param   Line: Line number to set the cursor position (1 or 2).
  * @param   Position: Position within the line to set the cursor position (0 to 15).
  */
void Lcd_Goto(LCD_Typedef *LcdConfig, uint8_t Line, uint8_t Position)
{
	if(Line == 1)
	{
		Lcd_WriteCommand(LcdConfig, (LCD_FIRST_LINE_POSITION_0 + Position));
	}
	if(Line == 2)
	{
		Lcd_WriteCommand(LcdConfig, (LCD_SECOND_LINE_POSITION_0 + Position));
	}
}

/**
  * @brief  Writes a string to the LCD at the specified line and position.
  * @param  LcdConfig: A pointer to the configuration structure of the LCD module.
  * @param  Line: Line number (1 or 2) where the string will be written.
  * @param  Position: Starting position (0 to 15) on the line where the string will begin.
  * @param  Ptr: Pointer to the string to be written.
  * @retval None
  */
void Lcd_WriteStringAt(LCD_Typedef *LcdConfig, uint8_t Line, uint8_t Position, uint8_t* Ptr)
{
	Lcd_Goto(LcdConfig, Line, Position);
	Lcd_WriteString(LcdConfig, Ptr);
}

/**
  * @brief  Writes a number to the LCD at the specified line and position.
  * @param  LcdConfig: A pointer to the configuration structure of the LCD module.
  * @param  Line: Line number (1 or 2) where the number will be written.
  * @param  Position: Starting position (0 to 15) on the line where the number will begin.
  * @param  Number: Number to be written.
  * @retval None
  */
void Lcd_WriteNumberAt(LCD_Typedef *LcdConfig, uint8_t Line, uint8_t Position, int32_t Number)
{
	Lcd_Goto(LcdConfig, Line, Position);
	Lcd_WriteNumber(LcdConfig, Number);
}

/**
  * @brief  Set the cursor state on the LCD.
  * @param  LcdConfig: A pointer to the configuration structure of the LCD module.
  * @param  CursorState: Desired cursor state, choose from:
  *                      - LCD_DISPLAY_OFF_CURSOR_OFF: Turn off display and cursor.
  *                      - LCD_DISPLAY_OFF_CURSOR_ON: Turn off display, but turn on cursor.
  *                      - LCD_DISPLAY_ON_CURSOR_OFF: Turn on display, but turn off cursor.
  *                      - LCD_DISPLAY_ON_CURSOR_BLINK: Turn on display and make cursor blink.
  *                      - Other values: Default to turning on display and turning off cursor.
  * @retval None
  */
void Lcd_Cursor(LCD_Typedef *LcdConfig, uint8_t CursorState)
{
	switch(CursorState)
	{
	case LCD_DISPLAY_OFF_CURSOR_OFF:
		Lcd_WriteCommand(LcdConfig, LCD_DISPLAY_OFF_CURSOR_OFF);
		break;
	case LCD_DISPLAY_OFF_CURSOR_ON:
		Lcd_WriteCommand(LcdConfig, LCD_DISPLAY_OFF_CURSOR_ON);
		break;
	case LCD_DISPLAY_ON_CURSOR_OFF:
		Lcd_WriteCommand(LcdConfig, LCD_DISPLAY_ON_CURSOR_OFF);
		break;
	case LCD_DISPLAY_ON_CURSOR_BLINK:
		Lcd_WriteCommand(LcdConfig, LCD_DISPLAY_ON_CURSOR_BLINK);
		break;
	default:
		Lcd_WriteCommand(LcdConfig, LCD_DISPLAY_ON_CURSOR_OFF);
		break;
	}
}
