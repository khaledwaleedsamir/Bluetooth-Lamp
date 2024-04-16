/**
  ******************************************************************************
  * @file    GPIO.c
  * @brief   Main file for GPIO Module.
  * @author  Khaled Waleed Samir
  * @version 0.1
  ******************************************************************************
  */
#include "GPIO.h"

/**
  * @brief  Sets the mode of a GPIO pin.
  * @param  Local_uint8_t_Port: The GPIO port (GPIO_PORTA, GPIO_PORTB, GPIO_PORTC).
  * @param  Local_uint8_t_Pin: The pin number (0 to 15).
  * @param  Local_uint8_t_mode: The mode to set for the pin available options are: 
  *                              1- ( GPIO_INPUT_ANALOG / GPIO_INPUT_FLOATING / GPIO_INPUT_PULL_UP_DOWN )
  *                              2- ( GPIO_OUTPUT_PUSH_PULL_10MHZ / GPIO_OUTPUT_OPEN_DRAIN_10MHZ / AFIO_OUTPUT_PUSH_PULL_10MHZ / AFIO_OUTPUT_OPEN_DRAIN_10MHZ )
  *                              3- ( GPIO_OUTPUT_PUSH_PULL_2MHZ / GPIO_OUTPUT_OPEN_DRAIN_2MHZ / AFIO_OUTPUT_PUSH_PULL_2MHZ / AFIO_OUTPUT_OPEN_DRAIN_2MHZ )
  *                              4- ( GPIO_OUTPUT_PUSH_PULL_50MHZ / GPIO_OUTPUT_OPEN_DRAIN_50MHZ / AFIO_OUTPUT_PUSH_PULL_50MHZ / AFIO_OUTPUT_OPEN_DRAIN_50MHZ )                             
  * @retval None
  */
void M_GPIO_SetPinMode(uint8_t Local_uint8_t_Port, uint8_t Local_uint8_t_Pin, uint8_t Local_uint8_t_mode)
{
    switch (Local_uint8_t_Port)
    {
    /*PORT-A CASE*/
    case GPIO_PORTA:
        /*LOW REGISTER GPIOx_CRL*/
        if(Local_uint8_t_Pin < 8)
        {
            /*Reseting the GPIOx_CRL Register bits for the required pin */
            GPIOA_CRL &= ~((uint32_t)(0b1111)<<(Local_uint8_t_Pin*4));
            /*Setting the GPIOx_CRL Register based on mode to set CNFy bits and MODEy bits */
            GPIOA_CRL |= ((uint32_t)Local_uint8_t_mode<<(Local_uint8_t_Pin*4));
        }
        /*HIGH REGISTER GPIOx_CRH*/
        else if(Local_uint8_t_Pin >= 8)
        {
            Local_uint8_t_Pin -= 8;
            /*Reseting the GPIOx_CRH Register bits for the required pin */
            GPIOA_CRH &= ~((uint32_t)(0b1111)<<(Local_uint8_t_Pin*4));
            /*Setting the GPIOx_CRH Register based on mode to set CNFy bits and MODEy bits */
            GPIOA_CRH |= ((uint32_t)Local_uint8_t_mode<<(Local_uint8_t_Pin*4));   
        }
        break;

    /*PORT-B CASE*/
    case GPIO_PORTB:
        /*LOW REGISTER GPIOx_CRL*/
        if(Local_uint8_t_Pin < 8)
        {
            /*Reseting the GPIOx_CRL Register bits for the required pin */
            GPIOB_CRL &= ~((uint32_t)(0b1111)<<(Local_uint8_t_Pin*4));
            /*Setting the GPIOx_CRL Register based on mode to set CNFy bits and MODEy bits */
            GPIOB_CRL |= ((uint32_t)Local_uint8_t_mode<<(Local_uint8_t_Pin*4));
        }
        /*HIGH REGISTER GPIOx_CRH*/
        else if(Local_uint8_t_Pin >= 8)
        {
            Local_uint8_t_Pin -= 8;
            /*Reseting the GPIOx_CRH Register bits for the required pin */
            GPIOB_CRH &= ~((uint32_t)(0b1111)<<(Local_uint8_t_Pin*4));
            /*Setting the GPIOx_CRH Register based on mode to set CNFy bits and MODEy bits */
            GPIOB_CRH |= ((uint32_t)Local_uint8_t_mode<<(Local_uint8_t_Pin*4));   
        }
        break;
    
    /*PORT-C CASE*/
    case GPIO_PORTC:
        /*LOW REGISTER GPIOx_CRL*/
        if(Local_uint8_t_Pin < 8)
        {
            /*Reseting the GPIOx_CRL Register bits for the required pin */
            GPIOC_CRL &= ~((uint32_t)(0b1111)<<(Local_uint8_t_Pin*4));
            /*Setting the GPIOx_CRL Register based on mode to set CNFy bits and MODEy bits */
            GPIOC_CRL |= ((uint32_t)Local_uint8_t_mode<<(Local_uint8_t_Pin*4));
        }
        /*HIGH REGISTER GPIOx_CRH*/
        else if(Local_uint8_t_Pin >= 8)
        {
            Local_uint8_t_Pin -= 8;
            /*Reseting the GPIOx_CRH Register bits for the required pin */
            GPIOC_CRH &= ~((uint32_t)(0b1111)<<(Local_uint8_t_Pin*4));
            /*Setting the GPIOx_CRH Register based on mode to set CNFy bits and MODEy bits */
            GPIOC_CRH |= ((uint32_t)Local_uint8_t_mode<<(Local_uint8_t_Pin*4));   
        }
        break;
    default:
        break;
    }
}

/**
  * @brief  Sets the value (high or low) of a GPIO pin.
  * @param  Local_uint8_t_Port: The GPIO port (GPIO_PORTA, GPIO_PORTB, GPIO_PORTC).
  * @param  Local_uint8_t_Pin: The pin number (0 to 15).
  * @param  Local_uint8_t_Value: The value to set for the pin (GPIO_HIGH or GPIO_LOW).
  * @retval None
  */

void M_GPIO_SetPinValue(uint8_t Local_uint8_t_Port, uint8_t Local_uint8_t_Pin, uint8_t Local_uint8_t_Value)
{
    switch (Local_uint8_t_Port)
    {
    /*PORT-A CASE*/
    case GPIO_PORTA:
        switch (Local_uint8_t_Value)
        {
        case GPIO_HIGH:
            SetBit(GPIOA_BSSR,Local_uint8_t_Pin);
            break;

        case GPIO_LOW:
            SetBit(GPIOA_BRR,Local_uint8_t_Pin);
            break;
        
        default:
            break;
        }
        break;

    /*PORT-B CASE*/
    case GPIO_PORTB:
        switch (Local_uint8_t_Value)
        {
        case GPIO_HIGH:
            SetBit(GPIOB_BSSR,Local_uint8_t_Pin);
            break;

        case GPIO_LOW:
            SetBit(GPIOB_BRR,Local_uint8_t_Pin);
            break;
        
        default:
            break;
        }
        break;

    /*PORT-C CASE*/
    case GPIO_PORTC:
        switch (Local_uint8_t_Value)
        {
        case GPIO_HIGH:
            SetBit(GPIOC_BSSR,Local_uint8_t_Pin);
            break;

        case GPIO_LOW:
            SetBit(GPIOC_BRR,Local_uint8_t_Pin);
            break;
        
        default:
            break;
        }
        break;
    
    default:
        break;
    }
}

/**
  * @brief  Gets the value of a GPIO pin.
  * @param  Local_uint8_t_Port: The GPIO port (GPIO_PORTA, GPIO_PORTB, GPIO_PORTC).
  * @param  Local_uint8_t_Pin: The pin number (0 to 15).
  * @retval The value of the pin (GPIO_HIGH or GPIO_LOW).
  */

uint8_t M_GPIO_GetPinValue(uint8_t Local_uint8_t_Port, uint8_t Local_uint8_t_Pin)
{
    uint8_t Local_uint8_t_Value;
    switch (Local_uint8_t_Port)
    {
    case GPIO_PORTA:
        Local_uint8_t_Value = GetBit(GPIOA_IDR, Local_uint8_t_Pin);
        break;
    case GPIO_PORTB:
        Local_uint8_t_Value = GetBit(GPIOB_IDR, Local_uint8_t_Pin);
        break;
    case GPIO_PORTC:
        Local_uint8_t_Value = GetBit(GPIOC_IDR, Local_uint8_t_Pin);
        break;
    default:
        break;
    }
    return Local_uint8_t_Value;
}

/**
  * @brief  Toggles the value of a GPIO pin (HIGH -> LOW , LOW -> HIGH).
  * @param  Local_uint8_t_Port: The GPIO port (GPIO_PORTA, GPIO_PORTB, GPIO_PORTC).
  * @param  Local_uint8_t_Pin: The pin number (0 to 15).
  * @retval None
  */

void M_GPIO_TogglePin(uint8_t Local_uint8_t_Port, uint8_t Local_uint8_t_Pin)
{
    switch (Local_uint8_t_Port)
    {
    case GPIO_PORTA:
        if((GetBit(GPIOA_ODR,Local_uint8_t_Pin)) == GPIO_HIGH)
        {
            M_GPIO_SetPinValue(GPIO_PORTA,Local_uint8_t_Pin,GPIO_LOW);   
        }
        else
        {
            M_GPIO_SetPinValue(GPIO_PORTA,Local_uint8_t_Pin,GPIO_HIGH);  
        } 
        break;
    case GPIO_PORTB:
        if((GetBit(GPIOB_ODR,Local_uint8_t_Pin)) == GPIO_HIGH)
        {
            M_GPIO_SetPinValue(GPIO_PORTB,Local_uint8_t_Pin,GPIO_LOW);   
        }
        else
        {
            M_GPIO_SetPinValue(GPIO_PORTB,Local_uint8_t_Pin,GPIO_HIGH);  
        }
        break;
    case GPIO_PORTC:
        if((GetBit(GPIOC_ODR,Local_uint8_t_Pin)) == GPIO_HIGH)
        {
            M_GPIO_SetPinValue(GPIO_PORTC,Local_uint8_t_Pin,GPIO_LOW);   
        }
        else
        {
            M_GPIO_SetPinValue(GPIO_PORTC,Local_uint8_t_Pin,GPIO_HIGH);  
        }
        break;
    default:
        break;
    }
}