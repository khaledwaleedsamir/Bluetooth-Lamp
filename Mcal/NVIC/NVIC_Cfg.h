/**
  ******************************************************************************
  * @file    NVIC_Cfg.h 
  * @brief   Configuration file for Nested Interrupt Vector Controller Driver.
  * @author  Khaled Waleed Samir
  * @version 0.1
  ******************************************************************************
  */
 
#ifndef NVIC_CFG_H_
#define NVIC_CFG_H_

/*     Priority Groups and Sub-Groups Options
   16 Priority Group /  0 Sub-Priority Groups --> [GROUP_16_SUBGROUP_0]
    8 Priority Group /  2 Sub-Priority Groups --> [GROUP_8_SUBGROUP_2]
    4 Priority Group /  4 Sub-Priority Groups --> [GROUP_4_SUBGROUP_4]
    2 Priority Group /  8 Sub-Priority Groups --> [GROUP_2_SUBGROUP_8]
    0 Priority Group / 16 Sub-Priority Groups --> [GROUP_0_SUBGROUP_16]   */

#define PRIORITY_GROUPING  GROUP_16_SUBGROUP_0

#endif /* NVIC_CFG_H_ */