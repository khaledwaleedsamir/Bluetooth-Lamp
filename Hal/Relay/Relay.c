/**
  ******************************************************************************
  * @file    Relay.c
  * @brief   Main file for Relay module.
  * @author  Khaled Waleed Samir
  * @version 0.1
  ******************************************************************************
  */
#include "Relay.h"
void Relay_Init(void)
{
    M_GPIO_SetPinMode(RELAY_PORT, RELAY_CONTROL_PIN, GPIO_OUTPUT_PUSH_PULL_2MHZ);
}
void Relay_On(void)
{
    #if RELAY_MODE == ACTIVE_HIGH
    M_GPIO_SetPinValue(RELAY_PORT, RELAY_CONTROL_PIN, GPIO_HIGH);
    #elif RELAY_MODE == ACTIVE_LOW
    M_GPIO_SetPinValue(RELAY_PORT, RELAY_CONTROL_PIN, GPIO_LOW);
    #else
    #warning Relay mode not correct check relay configurations
    #endif
}
void Relay_Off(void)
{
    #if RELAY_MODE == ACTIVE_HIGH
    M_GPIO_SetPinValue(RELAY_PORT, RELAY_CONTROL_PIN, GPIO_LOW);
    #elif RELAY_MODE == ACTIVE_LOW
    M_GPIO_SetPinValue(RELAY_PORT, RELAY_CONTROL_PIN, GPIO_HIGH);
    #else
    #warning Relay mode not correct check relay configurations
    #endif
}
void Relay_Toggle(void)
{
    M_GPIO_TogglePin(RELAY_PORT, RELAY_CONTROL_PIN);
}
