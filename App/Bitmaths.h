/**
  ******************************************************************************
  * @file    Bitmaths.h
  * @brief   Header file including bit maths operations macros.
  * @author  Khaled Waleed Samir
  * @version 0.1
  ******************************************************************************
  */
 
#ifndef BITMATHS_H_
#define BITMATHS_H_

#define SetBit(Reg,Bit) Reg |=  (1<<Bit)
#define ClrBit(Reg,Bit) Reg &= ~(1<<Bit)
#define TogBit(Reg,Bit) Reg ^=  (1<<Bit)
#define GetBit(Reg,Bit) (1&(Reg>>Bit))

#endif /* BITMATHS_H_ */
