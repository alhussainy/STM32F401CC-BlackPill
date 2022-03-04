/***********************************************************************************/
/* File Name : LED_interface.h                                                     */
/* File Info : Contains functions prototypes and Macros							   */
/* Version   : V1.0                                                                */
/* Date      : 04 Mar. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Guard*********************************/
/***********************************************************************************/
#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_


/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "LED_config.h"
#include "LED_private.h"

/***********************************************************************************/
/* Function Name  : HLED_vInit                                                     */
/* Function Info  : Inits LED 									                   */
/* Function Input : - LED port(GPIO_t): GPIOA, GPIOB, or GPIOC
 * 					- LED pin number(PINS_t): PIN0:15							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLED_vInit(GPIO_t *Copy_tPtrGPIO,PINS_t Copy_tPinNumber);


/***********************************************************************************/
/* Function Name  : HLED_vOn                                                       */
/* Function Info  : Turns LED on								                   */
/* Function Input : - LED port(GPIO_t): GPIOA, GPIOB, or GPIOC
 * 					- LED pin number(PINS_t): PIN0:15							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLED_vOn(GPIO_t *Copy_tPtrGPIO,PINS_t Copy_tPinNumber);

/***********************************************************************************/
/* Function Name  : HLED_vOff                                                      */
/* Function Info  : Turns LED off								                   */
/* Function Input : - LED port(GPIO_t): GPIOA, GPIOB, or GPIOC
 * 					- LED pin number(PINS_t): PIN0:15							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLED_vOff(GPIO_t *Copy_tPtrGPIO,PINS_t Copy_tPinNumber);


/***********************************************************************************/
/* Function Name  : HLED_vToggle                                                   */
/* Function Info  : Toggles LED 								                   */
/* Function Input : - LED port(GPIO_t): GPIOA, GPIOB, or GPIOC
 * 					- LED pin number(PINS_t): PIN0:15							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLED_vToggle(GPIO_t *Copy_tPtrGPIO,PINS_t Copy_tPinNumber);
#endif /* HAL_LED_LED_INTERFACE_H_ */
