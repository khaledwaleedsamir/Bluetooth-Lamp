/**
  ******************************************************************************
  * @file    RCC.h 
  * @brief   Header file for Reset Clock Control Driver.
  ******************************************************************************
  */

#include "RCC.h"
void M_RCC_InitSysClock (void)
{
	#if(RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL)
		RCC_CR   = 0x00010080;									/* Enable HSE with no bypass + (Default Trimming = 0) */
		while(!((RCC_CR)&(0x00020000)));						/* Check HSE is Ready */
		RCC_CFGR = 0x00000001;									/* HSE selected as system clock */

	#elif(RCC_CLOCK_TYPE == RCC_HSE_RC)
		RCC_CR   = 0x00050080;									/* Enable HSE with no bypass + (Default Trimming = 0) */
		while(!((RCC_CR)&(0x00020000)));						/* Check HSE is Ready */
		RCC_CFGR = 0x00000001;									/* Enable HSE with no bypass + (Default Trimming = 0) */

	#elif(RCC_CLOCK_TYPE == RCC_HSI)
		RCC_CR   = 0x00000081;									/* Enable HSI + (Default Trimming = 0) */
		while(!((RCC_CR)&(0x00000002)));						/* Check HSI is Ready */
		RCC_CFGR = 0x00000000;									/* HSI selected as system clock */

	#elif(RCC_CLOCK_TYPE == RCC_PLL)
		#if(RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2)				/* PLL INPUT CLOCK: (HSI/2) */
			RCC_CR   = 0x00000081;								/* Enable HSI + (Default Trimming = 0) */
			RCC_CFGR = 0x00000000;

		#elif(RCC_PLL_INPUT == RCC_PLL_IN_HSE_CRYSTAL_DIV_2)	/* PLL INPUT CLOCK: (HSE/2) */
			RCC_CR   = 0x00010080;								/* Enable HSE with no bypass + (Default Trimming = 0) */
			RCC_CFGR = 0x00030000;

		#elif(RCC_PLL_INPUT == RCC_PLL_IN_HSE_CRYSTAL)			/* PLL INPUT CLOCK: (HSE) */
			RCC_CR   = 0x00010080;								/* Enable HSE with no bypass + (Default Trimming = 0) */
			RCC_CFGR = 0x00010000;

		#elif(RCC_PLL_INPUT == RCC_PLL_IN_HSE_RC_DIV_2)			/* PLL INPUT CLOCK: (HSE/2) */
			RCC_CR   = 0x00050080;								/* Enable HSE with bypass + (Default Trimming = 0) */
			RCC_CFGR = 0x00030000;

		#elif(RCC_PLL_INPUT == RCC_PLL_IN_HSE_RC_)				/* PLL INPUT CLOCK: (HSE) */
			RCC_CR   = 0x00050080;								/* Enable HSE with bypass + (Default Trimming = 0) */
			RCC_CFGR = 0x00010000;
		#endif


		#if(RCC_PLL_MUL_VAL == 2)						/* PLL Multiplier =  (2) */
			RCC_CFGR |= 0x00000000;

		#elif(RCC_PLL_MUL_VAL == 3)						/* PLL Multiplier =  (3) */
			RCC_CFGR |= 0x00040000;

		#elif(RCC_PLL_MUL_VAL == 4)						/* PLL Multiplier =  (4) */
			RCC_CFGR |= 0x00080000;

		#elif(RCC_PLL_MUL_VAL == 5)						/* PLL Multiplier =  (5) */
			RCC_CFGR |= 0x000C0000;

		#elif(RCC_PLL_MUL_VAL == 6)						/* PLL Multiplier =  (6) */
			RCC_CFGR |= 0x00100000;

		#elif(RCC_PLL_MUL_VAL == 7)						/* PLL Multiplier =  (7) */
			RCC_CFGR |= 0x00140000;

		#elif(RCC_PLL_MUL_VAL == 8)						/* PLL Multiplier =  (8) */
			RCC_CFGR |= 0x00180000;

		#elif(RCC_PLL_MUL_VAL == 9)						/* PLL Multiplier =  (9) */
			RCC_CFGR |= 0x001C0000;

		#elif(RCC_PLL_MUL_VAL == 10)					/* PLL Multiplier =  (10) */
			RCC_CFGR |= 0x00200000;

		#elif(RCC_PLL_MUL_VAL == 11)					/* PLL Multiplier =  (11) */
			RCC_CFGR |= 0x00240000;

		#elif(RCC_PLL_MUL_VAL == 12)					/* PLL Multiplier =  (12) */
			RCC_CFGR |= 0x00280000;

		#elif(RCC_PLL_MUL_VAL == 13)					/* PLL Multiplier =  (13) */
			RCC_CFGR |= 0x002C0000;

		#elif(RCC_PLL_MUL_VAL == 14)					/* PLL Multiplier =  (14) */
			RCC_CFGR |= 0x00300000;

		#elif(RCC_PLL_MUL_VAL == 15)					/* PLL Multiplier =  (15) */
			RCC_CFGR |= 0x00340000;

		#elif(RCC_PLL_MUL_VAL == 16)					/* PLL Multiplier =  (16) */
			RCC_CFGR |= 0x00380000;
		#endif

		/* The PLL configuration (selection of HSI oscillator divided by 2 or HSE oscillator for PLL
		   input clock, and multiplication factor) must be done before enabling the PLL. Once the PLL
		   enabled, these parameters cannot be changed.	*/
		RCC_CR   |= 0x01000080;							/* Enable PLL + (Default Trimming = 0) */
		while(!((RCC_CR)&(0x02000000)));				/* Check PLL is Ready */
		RCC_CFGR |= 0x00000002;							/* PLL selected as system clock */

	#else
		//#error("You Chose Wrong Clock Type")			/* Return Error */
	#endif
}

void M_RCC_EnableClock (uint8_t Copy_uint8_tBusID, uint8_t Copy_uint8_tPerID)
{
	if(Copy_uint8_tPerID <= 31)
	{
		switch(Copy_uint8_tBusID)
		{
			case RCC_AHB :	SetBit(RCC_AHBENR,Copy_uint8_tPerID);		break;
			case RCC_APB1:	SetBit(RCC_APB1ENR,Copy_uint8_tPerID);		break;
			case RCC_APB2:	SetBit(RCC_APB2ENR,Copy_uint8_tPerID);		break;
		    default:                                                    break;
		}
	}
	else
	{
		// WRONG PIN SELECTION
	}
}

void M_RCC_DisableClock (uint8_t Copy_uint8_tBusID, uint8_t Copy_uint8_tPerID)
{
	if(Copy_uint8_tPerID <= 31)
	{
		switch(Copy_uint8_tBusID)
		{
			case RCC_AHB :	ClrBit(RCC_AHBENR,Copy_uint8_tPerID);		break;
			case RCC_APB1:	ClrBit(RCC_APB1ENR,Copy_uint8_tPerID);		break;
			case RCC_APB2:	ClrBit(RCC_APB2ENR,Copy_uint8_tPerID);		break;
		    default:                                                    break;
		}
	}
	else
	{
		// WRONG PIN SELECTION
	}
}