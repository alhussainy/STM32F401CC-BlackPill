/***********************************************************************************/
/* File Name : SSD_interface.h                                                     */
/* File Info : Contains interface functions declarations						   */
/* Version   : V1.0                                                                */
/* Date      : 28 Feb. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Guard*********************************/
/***********************************************************************************/
#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_


/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "SSD_config.h"
#include "GPIO_interface.h"


/***********************************************************************************/
/* Function Name  : HSSD_vInit                                                     */
/* Function Info  : Inits Seven segments display				                   */
/* Function Input : None														   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HSSD_vInit(void);


/***********************************************************************************/
/* Function Name  : HSSD_vDisplayNum                                                     */
/* Function Info  : Displays numbers(0:9)         				                   */
/* Function Input : Number to be displayed										   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HSSD_vDisplayNum(u8 Copy_u8Num);
#endif /* HAL_SSD_SSD_INTERFACE_H_ */
