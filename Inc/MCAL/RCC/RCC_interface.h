/***********************************************************************************/
/* File Name : RCC_interface.h                                                     */
/* File Info : Contains functions declaration and user-defined data types		   */
/* Version   : V1.1                                                                */
/* Date      : 24 Feb. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Guard*********************************/
/***********************************************************************************/
#ifndef MCAL_RCC_RCC_INTERFACE_H_
#define MCAL_RCC_RCC_INTERFACE_H_

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_config.h"
#include "RCC_private.h"


/* Buses options(Bus_t): AHB1, AHB2, APB1, APB2 */
/* RCC source options(RCC_Src_t): 	HSI, HSE, PLL*/
/* HSE source options(HSE_Src_t): HSE_Crystal, HSE_RC */

/* PLL source options(PLL_Src_t): PLL_HSI, PLL_HSE */
/* AHB Prescalar options(AHB_PRESCL_t): AHB_PRE_1, AHB_PRE_2, AHB_PRE_4, AHB_PRE_8, AHB_PRE_16, AHB_PRE_64
 *						  AHB_PRE_128, AHB_PRE_256, AHB_PRE_512
 */

/* APB1 Prescalar options(APB1_PRESCL_t): APB1_PRE_1, APB1_PRE_2, APB1_PRE_4, APB1_PRE_8, APB1_PRE_16 */

/* APB2 Prescalar options(APB2_PRESCL_t): APB2_PRE_1, APB2_PRE_2, APB2_PRE_4, APB2_PRE_8, APB2_PRE_16 */

/***********************************************************************************/
/* Function Name  : MRCC_vInitRCC                                                  */
/* Function Info  : Inits RCC								                       */
/* Function Input : - RCC source options(RCC_Src_t): HSI, HSE, PLL
 * 					- HSE source options(HSE_Src_t): HSE_Crystal, HSE_RC
 * 					- PLL source options(PLL_Src_t): PLL_HSI, PLL_HSE
 * 					- AHB Prescalar options(AHB_PRESCL_t)
 * 					- APB1 Prescalar options(APB1_PRESCL_t)
 * 					- APB2 Prescalar options(APB2_PRESCL_t)						   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MRCC_vInitRCC(RCC_Src_t Copy_tRCC_SRC,HSE_Src_t Copy_t_HSE_SRC,PLL_Src_t Copy_tPLL_SRC,AHB_PRESCL_t Copy_tAHB_PRE,APB1_PRESCL_t Copy_tAPB1_PRE,APB2_PRESCL_t Copy_tAPB2_PRE);


/***********************************************************************************/
/* Function Name  : MRCC_vEnablePeripheralClk                                      */
/* Function Info  : Enable peripheral clock					                       */
/* Function Input : - Buses options(Bus_t): AHB1_BUS, AHB2_BUS, APB1_BUS, APB2_BUS
 * 					- Peripheral number on the bus								   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MRCC_vEnablePeripheralClk(Bus_t Copy_tBusName,u8 PeripheralNumber);


/***********************************************************************************/
/* Function Name  : MRCC_vDisablePeripheralClk                                     */
/* Function Info  : Disable peripheral clock					                   */
/* Function Input : - Buses options(Bus_t): AHB1_BUS, AHB2_BUS, APB1_BUS, APB2_BUS
 * 					- Peripheral number on the bus								   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MRCC_vDisablePeripheralClk(Bus_t Copy_tBusName,u8 PeripheralNumber);
#endif /* MCAL_RCC_RCC_INTERFACE_H_ */
