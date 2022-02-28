/***********************************************************************************/
/* File Name : GPIO_program.c                              	                       */
/* File Info : Contains functions implementation								   */
/* Version   : V1.0                                                                */
/* Date      : 28 Feb. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "GPIO_config.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"


/***********************************************************************************/
/* Function Name  : MGPIO_vSetMode                                                 */
/* Function Info  : Sets GPIO Mode								                   */
/* Function Input : - GPIO Base Address
 * 					- Pin number(0:15)
 * 					- Modes options(MODES_t):INPUT_MODE,OUTPUT_MODE,AF_MODE,
 * 					and ANALOG_MODE		  							        	   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MGPIO_vSetMode(GPIO_t * Ptr_tGPIO,u8 Copy_u8PinNum,MODES_t Copy_tMode){
	//TODO-BUG: BUG if the bit is 1 it won't be reseted in run time
	Ptr_tGPIO->MODER |= (Copy_tMode<<(Copy_u8PinNum*2));
}



/***********************************************************************************/
/* Function Name  : MGPIO_vSetOutputType                                           */
/* Function Info  : Sets GPIO output type						                   */
/* Function Input : - GPIO Base Address
 * 					- Pin number(0:15)
 * 					- Output options(OUTPUT_TYPE_t):OUT_PUSH_PULL,OUT_OPEN_DRAI	   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MGPIO_vSetOutputType(GPIO_t * Ptr_tGPIO,u8 Copy_u8PinNum,OUTPUT_TYPE_t Copy_tOutputType){
	//TODO-BUG: BUG if the bit is 1 it won't be reseted in run time
	Ptr_tGPIO->OTYPER |= (Copy_tOutputType<<Copy_u8PinNum);
}

/***********************************************************************************/
/* Function Name  : MGPIO_vSetOutputSpeed                                          */
/* Function Info  : Sets GPIO output speed						                   */
/* Function Input : - GPIO Base Address
 * 					- Pin number(0:15)
 * 					- Output speed(OUTPUT_SPEED_t):OUT_LOW_SP,OUT_MID_SP,OUT_HI_SP
 * 					and OUT_VH_SP												   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MGPIO_vSetOutputSpeed(GPIO_t * Ptr_tGPIO,u8 Copy_u8PinNum,OUTPUT_SPEED_t Copy_tOutputSpeed){
		//TODO-BUG: BUG if the bit is 1 it won't be reseted in run time
		Ptr_tGPIO->OSPEEDR |= (Copy_tOutputSpeed<<(Copy_u8PinNum*2));
}


/***********************************************************************************/
/* Function Name  : MGPIO_vSetPull_up_down                                         */
/* Function Info  : Sets GPIO pull-up or pull-down		  		                   */
/* Function Input : - GPIO Base Address
 * 					- Pin number(0:15)
 * 					- Activate pull-up or pull-down(PULL_UP_DOWN_t):
 * 					NO_UP_DOWN,PULL_UP,PULL_dOWN								   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MGPIO_vSetPull_up_down(GPIO_t * Ptr_tGPIO,u8 Copy_u8PinNum,PULL_UP_DOWN_t Copy_tPullUpDown){
		//TODO-BUG: BUG if the bit is 1 it won't be reseted in run time
		Ptr_tGPIO->PUPDR |= (Copy_tPullUpDown<<(Copy_u8PinNum*2));
}



/***********************************************************************************/
/* Function Name  : MGPIO_vReadPin           		                               */
/* Function Info  : Gets data from pin 		     		  		                   */
/* Function Input : - GPIO Base Address
 * 					- Pin number(0:15)											   */
/* Function Return: u8 data (0 or 1)			                                   */
/***********************************************************************************/
u8 MGPIO_vReadPin(GPIO_t * Ptr_tGPIO,u8 Copy_u8PinNum){
	return ((Ptr_tGPIO->IDR>>Copy_u8PinNum)& 0x01);
}




/***********************************************************************************/
/* Function Name  : MGPIO_vWritePin           		                               */
/* Function Info  : Sets data on pin 		     		  		                   */
/* Function Input : - GPIO Base Address
 * 					- Pin number(0:15)
 * 					- Output options(OUTPUT_t):	OUT_LOW,OUT_HIGH				   */
/* Function Return: None		    			                                   */
/***********************************************************************************/
void MGPIO_vWritePin(GPIO_t * Ptr_tGPIO,u8 Copy_u8PinNum,OUTPUT_t Copy_tOutput){
	/* ODRx register can be used to set output value but for atomic bit set/reset,
	 *  the ODR bits can be individually set and reset by writing to the
	 *  GPIOx_BSRR register  */
	switch(Copy_tOutput){
		case OUT_LOW:
			SET_BIT(Ptr_tGPIO->BSRR,Copy_u8PinNum+15);
		break;
		case OUT_HIGH:
			SET_BIT(Ptr_tGPIO->BSRR,Copy_u8PinNum);
		break;
		default:
		break;
	}
}



/***********************************************************************************/
/* Function Name  : MGPIO_vSetAltFun           		                               */
/* Function Info  : Sets Alt function for pin 	 		  		                   */
/* Function Input : - GPIO Base Address
 * 					- Pin number(0:15)
 * 					- Alt Function Number(AF_t):	AF0:15						   */
/* Function Return: None		    			                                   */
/***********************************************************************************/
void MGPIO_vSetAltFun(GPIO_t * Ptr_tGPIO,u8 Copy_u8PinNum,AF_t Copy_tAFNumber){
	if(Copy_u8PinNum <= 7){
		Ptr_tGPIO->AFRL |= (Copy_tAFNumber<<(Copy_u8PinNum*4));
	}else if(Copy_u8PinNum > 7 && Copy_u8PinNum <= 15){
		Ptr_tGPIO->AFRH |= (Copy_tAFNumber<<((Copy_u8PinNum%8)*4));
	}else{

	}
}
