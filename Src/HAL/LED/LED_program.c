/***********************************************************************************/
/* File Name : LED_program.h                               	                       */
/* File Info : Contains led functions implementation							   */
/* Version   : V1.0                                                                */
/* Date      : 04 Mar. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/


/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
/***********************************************************************************/
#include "LED_interface.h"


/* Function Name  : HLED_vInit                                                     */
/* Function Info  : Inits LED 									                   */
/* Function Input : - LED port(GPIO_t): GPIOA, GPIOB, or GPIOC
 * 					- LED pin number(PINS_t): PIN0:15							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLED_vInit(GPIO_t *Copy_tPtrGPIO,PINS_t Copy_tPinNumber){
	MGPIO_vSetMode(Copy_tPtrGPIO, Copy_tPinNumber, OUTPUT_MODE);
	MGPIO_vSetOutputType(Copy_tPtrGPIO, Copy_tPinNumber, OUT_PUSH_PULL);
	MGPIO_vSetOutputSpeed(Copy_tPtrGPIO, Copy_tPinNumber, OUT_LOW_SP);
}


/***********************************************************************************/
/* Function Name  : HLED_vOn                                                       */
/* Function Info  : Turns LED on								                   */
/* Function Input : - LED port(GPIO_t): GPIOA, GPIOB, or GPIOC
 * 					- LED pin number(PINS_t): PIN0:15							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLED_vOn(GPIO_t *Copy_tPtrGPIO,PINS_t Copy_tPinNumber){
	MGPIO_vWritePin(Copy_tPtrGPIO, Copy_tPinNumber, OUT_HIGH);
}

/***********************************************************************************/
/* Function Name  : HLED_vOff                                                      */
/* Function Info  : Turns LED off								                   */
/* Function Input : - LED port(GPIO_t): GPIOA, GPIOB, or GPIOC
 * 					- LED pin number(PINS_t): PIN0:15							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLED_vOff(GPIO_t *Copy_tPtrGPIO,PINS_t Copy_tPinNumber){
	MGPIO_vWritePin(Copy_tPtrGPIO, Copy_tPinNumber, OUT_LOW);
}


/***********************************************************************************/
/* Function Name  : HLED_vToggle                                                   */
/* Function Info  : Toggles LED 								                   */
/* Function Input : - LED port(GPIO_t): GPIOA, GPIOB, or GPIOC
 * 					- LED pin number(PINS_t): PIN0:15							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLED_vToggle(GPIO_t *Copy_tPtrGPIO,PINS_t Copy_tPinNumber){
	MGPIO_vTogglePin(Copy_tPtrGPIO, Copy_tPinNumber);
}
