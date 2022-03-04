/***********************************************************************************/
/* File Name : LCD_interface.h                                                     */
/* File Info : Contains interface functions declarations						   */
/* Version   : V1.0                                                                */
/* Date      : 01 Mar. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Guard*********************************/
/***********************************************************************************/
#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "LCD_config.h"
#include "GPIO_interface.h"

/***********************************************************************************/
/****************************User-defined data types********************************/
/***********************************************************************************/
#define _8_DATA_MODE	0
#define _4_DATA_MODE	1


/***********************************************************************************/
/* Function Name  : HLCD_vInit                                                     */
/* Function Info  : Inits LCD display							                   */
/* Function Input : None														   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vInit(void);

/***********************************************************************************/
/* Function Name  : HLCD_vSendCommand                                              */
/* Function Info  : Sends a command to LCD 						                   */
/* Function Input : LCD Command													   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vSendCommand(u8 Copy_u8Command);

/***********************************************************************************/
/* Function Name  : HLCD_vSendCharacter                                            */
/* Function Info  : Sends a character to LCD 					                   */
/* Function Input : LCD Character												   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vSendCharacter(u8 Copy_u8Character);

/***********************************************************************************/
/* Function Name  : HLCD_vDisplayString                                            */
/* Function Info  : Sends a string to LCD 		    			                   */
/* Function Input : String														   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vDisplayString(u8 *str);

/***********************************************************************************/
/* Function Name  : HLCD_vCLR		                                               */
/* Function Info  : Clears LCD Display   		    			                   */
/* Function Input : None												   		   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vCLR(void);


/***********************************************************************************/
/* Function Name  : HLCD_vWriteInt	                                               */
/* Function Info  : Sends a integer to LCD 		    			                   */
/* Function Input : integer 													   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vWriteInt(u32 num);

/***********************************************************************************/
/* Function Name  : HLCD_GoTo		                                               */
/* Function Info  : Sets LCD location	 		    			                   */
/* Function Input : position in row and column 									   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vGoTo(u8 row,u8 col);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
