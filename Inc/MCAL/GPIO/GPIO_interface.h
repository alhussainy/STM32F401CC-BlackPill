/***********************************************************************************/
/* File Name : GPIO_interface.h                                                    */
/* File Info : Contains interface functions declarations						   */
/* Version   : V1.0                                                                */
/* Date      : 23 Feb. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Guard*********************************/
/***********************************************************************************/
#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_config.h"
#include "GPIO_private.h"

/***********************************************************************************/
/****************************User-defined data types********************************/
/***********************************************************************************/
typedef enum{
	PIN0		  = 0	,
	PIN1				,
	PIN2				,
	PIN3				,
	PIN4				,
	PIN5				,
	PIN6				,
	PIN7				,
	PIN8				,
	PIN9				,
	PIN10				,
	PIN11				,
	PIN12				,
	PIN13				,
	PIN14				,
	PIN15
}PINS_t;
typedef enum{
	INPUT_MODE 	  =	0 	,
	OUTPUT_MODE 		,
	AF_MODE				,
	ANALOG_MODE
} MODES_t;

typedef enum{
	OUT_PUSH_PULL = 0	,
	OUT_OPEN_DRAIN
}OUTPUT_TYPE_t;

typedef enum{
	OUT_LOW_SP	  = 0	,
	OUT_MID_SP			,
	OUT_HI_SP			,
	OUT_VH_SP
}OUTPUT_SPEED_t;

typedef enum{
	NO_UP_DOWN	  = 0	,
	PULL_UP				,
	PULL_dOWN			,
}PULL_UP_DOWN_t;

typedef enum{
	OUT_LOW	  	  = 0	,
	OUT_HIGH			,
}OUTPUT_t;

typedef enum{
	AF0		  	  = 0	,
	AF1					,
	AF2					,
	AF3					,
	AF4					,
	AF5					,
	AF6					,
	AF7					,
	AF8					,
	AF9					,
	AF10				,
	AF11				,
	AF12				,
	AF13				,
	AF14				,
	AF15
}AF_t;

typedef enum{
	_4_BITS		 =0		,
	_8_BITS  	 		,
	_16_BITS
}DATA_LENGTH_t;
/***********************************************************************************/
/* Function Name  : MGPIO_vSetMode                                                 */
/* Function Info  : Sets GPIO Mode								                   */
/* Function Input : - GPIO Base Address
 * 					- Pin number(0:15)
 * 					- Modes options(MODES_t):INPUT_MODE,INPUT_MODE,AF_MODE,
 * 					and ANALOG_MODE		  							        	   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MGPIO_vSetMode(GPIO_t * Ptr_tGPIO,u8 Copy_u8PinNum,MODES_t Copy_tMode);


/***********************************************************************************/
/* Function Name  : MGPIO_vSetOutputType                                           */
/* Function Info  : Sets GPIO output type						                   */
/* Function Input : - GPIO Base Address
 * 					- Pin number(0:15)
 * 					- Output options(OUTPUT_TYPE_t):OUT_PUSH_PULL,OUT_OPEN_DRAI	   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MGPIO_vSetOutputType(GPIO_t * Ptr_tGPIO,u8 Copy_u8PinNum,OUTPUT_TYPE_t Copy_tOutputType);


/***********************************************************************************/
/* Function Name  : MGPIO_vSetOutputSpeed                                          */
/* Function Info  : Sets GPIO output speed						                   */
/* Function Input : - GPIO Base Address
 * 					- Pin number(0:15)
 * 					- Output speed(OUTPUT_SPEED_t):OUT_LOW_SP,OUT_MID_SP,OUT_HI_SP
 * 					and OUT_VH_SP												   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MGPIO_vSetOutputSpeed(GPIO_t * Ptr_tGPIO,u8 Copy_u8PinNum,OUTPUT_SPEED_t Copy_tOutputSpeed);



/***********************************************************************************/
/* Function Name  : MGPIO_vSetPull_up_down                                         */
/* Function Info  : Sets GPIO pull-up or pull-down		  		                   */
/* Function Input : - GPIO Base Address
 * 					- Pin number(0:15)
 * 					- Activate pull-up or pull-down(PULL_UP_DOWN_t):
 * 					NO_UP_DOWN,PULL_UP,PULL_dOWN								   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MGPIO_vSetPull_up_down(GPIO_t * Ptr_tGPIO,u8 Copy_u8PinNum,PULL_UP_DOWN_t Copy_tPullUpDown);


/***********************************************************************************/
/* Function Name  : MGPIO_vReadPin           		                               */
/* Function Info  : Gets data from pin 		     		  		                   */
/* Function Input : - GPIO Base Address
 * 					- Pin number(0:15)											   */
/* Function Return: u8 data (0 or 1)			                                   */
/***********************************************************************************/
u8 MGPIO_vReadPin(GPIO_t * Ptr_tGPIO,u8 Copy_u8PinNum);



/***********************************************************************************/
/* Function Name  : MGPIO_vWritePin           		                               */
/* Function Info  : Sets data on pin 		     		  		                   */
/* Function Input : - GPIO Base Address
 * 					- Pin number(0:15)
 * 					- Output options(OUTPUT_t):	OUT_LOW,OUT_HIGH				   */
/* Function Return: None		    			                                   */
/***********************************************************************************/
void MGPIO_vWritePin(GPIO_t * Ptr_tGPIO,u8 Copy_u8PinNum,OUTPUT_t Copy_tOutput);




/***********************************************************************************/
/* Function Name  : MGPIO_vSetAltFun           		                               */
/* Function Info  : Sets Alt function for pin 	 		  		                   */
/* Function Input : - GPIO Base Address
 * 					- Pin number(0:15)
 * 					- Alt Function Number(AF_t):	AF0:15						   */
/* Function Return: None		    			                                   */
/***********************************************************************************/
void MGPIO_vSetAltFun(GPIO_t * Ptr_tGPIO,u8 Copy_u8PinNum,AF_t Copy_tAFNumber);

/***********************************************************************************/
/* Function Name  : MGPIO_vTogglePin           		                               */
/* Function Info  : Toggles pin state		     		  		                   */
/* Function Input : - GPIO Base Address
 * 					- Pin number(0:15)											   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MGPIO_vTogglePin(GPIO_t * Ptr_tGPIO,u8 Copy_u8PinNum);

/***********************************************************************************/
/* Function Name  : MGPIO_vWritePort           		                               */
/* Function Info  : Sets output on set of port pins		  		                   */
/* Function Input : - GPIO Base Address
 * 					- Pin number(0:15)
 * 					- Data length to be written on the port	(DATA_LENGTH_t)		   */
/* Function Return: None		    			                                   */
/***********************************************************************************/
void MGPIO_vWritePort(GPIO_t * Ptr_tGPIO,u8 Copy_u8StartPinNum,DATA_LENGTH_t Copy_u8DataLength,u16 Copy_u16Data);
/*TODO:Pins Locker
 *
 */
#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
