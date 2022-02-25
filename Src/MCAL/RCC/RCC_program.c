/***********************************************************************************/
/* File Name : RCC_program.c                               	                       */
/* File Info : Contains functions implementation								   */
/* Version   : V1.0                                                                */
/* Date      : 24 Feb. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "RCC_interface.h"
#include "BIT_MATH.h"

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
void MRCC_vInitRCC(RCC_Src_t Copy_tRCC_SRC,HSE_Src_t Copy_t_HSE_SRC,PLL_Src_t Copy_tPLL_SRC,AHB_PRESCL_t Copy_tAHB_PRE,APB1_PRESCL_t Copy_tAPB1_PRE,APB2_PRESCL_t Copy_tAPB2_PRE){
	switch(Copy_tRCC_SRC){
		case HSI:
			/*Select HSI RCC->CFGR SW[1:0]=00*/
			CLR_BIT(RCC->CFGR,SW0);
			CLR_BIT(RCC->CFGR,SW1);
			/*Enable HSI*/
			SET_BIT(RCC->CR,HSION);
		break;
		case HSE:
			MRCC_vInitHSE_SRC(Copy_t_HSE_SRC);
			/*Select HSI RCC->CFGR SW[1:0]=01*/
			SET_BIT(RCC->CFGR,SW0);
			CLR_BIT(RCC->CFGR,SW1);
			/*Enable HSE*/
			SET_BIT(RCC->CR,HSEON);
		break;
		case PLL:
			MRCC_vInitPLL_SRC(Copy_tPLL_SRC);
			/*Select HSI RCC->CFGR SW[1:0]=10*/
			CLR_BIT(RCC->CFGR,SW0);
			SET_BIT(RCC->CFGR,SW1);
			/*Enable PLL*/
			SET_BIT(RCC->CR,PLLON);
		break;
		default:
		break;
	}
	MRCC_vInitPrescaler( Copy_tAHB_PRE, Copy_tAPB1_PRE, Copy_tAPB2_PRE);
}
