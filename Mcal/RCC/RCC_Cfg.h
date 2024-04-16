/**
  ******************************************************************************
  * @file    RCC_Cfg.h 
  * @brief   Configuration file for RCC Driver.
  ******************************************************************************
  */
#ifndef _RCC_CFG_H_
#define _RCC_CFG_H_

/**********************************************************************************************************************
 * CONFIGURATIONS
 *********************************************************************************************************************/
/* Options: RCC_HSE_CRYSTAL
			RCC_HSE_RC
			RCC_HSI			
			RCC_PLL				*/
#define RCC_CLOCK_TYPE 		(RCC_HSI)


/* Note: Select Value only if you have PLL as input Clock Source	*/
#if (RCC_CLOCK_TYPE == RCC_PLL)
	/* Options: RCC_PLL_IN_HSI_DIV_2
				RCC_PLL_IN_HSE_CRYSTAL_DIV_2
				RCC_PLL_IN_HSE_CRYSTAL
				RCC_PLL_IN_HSE_RC_DIV_2
				RCC_PLL_IN_HSE_RC				*/
	#define RCC_PLL_INPUT 		(RCC_PLL_IN_HSE_DIV_2)

	/* Options: 2 to 16	*/
	#define RCC_PLL_MUL_VAL 	(4)
#endif	/* End of PLL Configuration	*/



#endif	/* _RCC_CFG_H_	*/
