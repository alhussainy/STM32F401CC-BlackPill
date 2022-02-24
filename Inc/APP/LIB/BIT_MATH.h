/***********************************************************************************/
/* File Name : BIT_MATH.h                                                          */
/* File Info : Contains Main Bit math operations								   */
/* Version   : V1.0                                                                */
/* Date      : 23 Feb. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Guard*********************************/
/***********************************************************************************/
#ifndef APP_LIB_BIT_MATH_H_
#define APP_LIB_BIT_MATH_H_


#define SET_BIT(reg,bit)   (reg |= (1<<bit))
#define CLR_BIT(reg,bit)   (reg &= ~(1<<bit))
#define TOG_BIT(reg,bit)   (reg ^= (1<<bit))
#define GET_BIT(REG,BIT)   ((REG >> BIT)&1)

#endif /* APP_LIB_BIT_MATH_H_ */
