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
#include "RCC_private.h"
#include "BIT_MATH.h"

/***********************************************************************************/
/***************************Functions INPUTS OPTIONS********************************/
/***********************************************************************************/
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
	MRCC_vInitAHBPrescaler(Copy_tAHB_PRE);
	MRCC_vInitAPB1Prescaler(Copy_tAPB1_PRE);
	MRCC_vInitAPB2Prescaler(Copy_tAPB2_PRE);
}



/***********************************************************************************/
/* Function Name  : MRCC_vInitAHBPrescaler                                         */
/* Function Info  : Inits PreScalar							                       */
/* Function Input : AHB Prescalar options(AHB_PRESCL_t)						  	   */
/*					AHB_PRE_1, AHB_PRE_2, AHB_PRE_4, AHB_PRE_8, AHB_PRE_16,		   */
/*					AHB_PRE_64, AHB_PRE_128, AHB_PRE_256, AHB_PRE_512			   */
/* Function Return: None						                                   */
/***********************************************************************************/
static void MRCC_vInitAHBPrescaler(AHB_PRESCL_t Copy_tAHB_PRE){
	switch(Copy_tAHB_PRE){
				case AHB_PRE_1:
					/* 0xxx: system clock not divided */
					CLR_BIT(RCC->CFGR,HPRE_0);
					CLR_BIT(RCC->CFGR,HPRE_1);
					CLR_BIT(RCC->CFGR,HPRE_2);
					CLR_BIT(RCC->CFGR,HPRE_3);
				break;
				case AHB_PRE_2:
					/* 1000: system clock divided by 2 */
					CLR_BIT(RCC->CFGR,HPRE_0);
					CLR_BIT(RCC->CFGR,HPRE_1);
					CLR_BIT(RCC->CFGR,HPRE_2);
					SET_BIT(RCC->CFGR,HPRE_3);
				break;
				case AHB_PRE_4:
					/* 1001: system clock divided by 4 */
					SET_BIT(RCC->CFGR,HPRE_0);
					CLR_BIT(RCC->CFGR,HPRE_1);
					CLR_BIT(RCC->CFGR,HPRE_2);
					SET_BIT(RCC->CFGR,HPRE_3);
				break;
				case AHB_PRE_8:
					/* 1010: system clock divided by 8 */
					CLR_BIT(RCC->CFGR,HPRE_0);
					SET_BIT(RCC->CFGR,HPRE_1);
					CLR_BIT(RCC->CFGR,HPRE_2);
					SET_BIT(RCC->CFGR,HPRE_3);
				break;
				case AHB_PRE_16:
					/* 1011: system clock divided by 16 */
					SET_BIT(RCC->CFGR,HPRE_0);
					SET_BIT(RCC->CFGR,HPRE_1);
					CLR_BIT(RCC->CFGR,HPRE_2);
					SET_BIT(RCC->CFGR,HPRE_3);
				break;
				case AHB_PRE_64:
					/* 1100: system clock divided by 64 */
					CLR_BIT(RCC->CFGR,HPRE_0);
					CLR_BIT(RCC->CFGR,HPRE_1);
					SET_BIT(RCC->CFGR,HPRE_2);
					SET_BIT(RCC->CFGR,HPRE_3);
				break;
				case AHB_PRE_128:
					/* 1101: system clock divided by 128 */
					SET_BIT(RCC->CFGR,HPRE_0);
					CLR_BIT(RCC->CFGR,HPRE_1);
					SET_BIT(RCC->CFGR,HPRE_2);
					SET_BIT(RCC->CFGR,HPRE_3);
				break;
				case AHB_PRE_256:
					/* 1110: system clock divided by 256 */
					CLR_BIT(RCC->CFGR,HPRE_0);
					SET_BIT(RCC->CFGR,HPRE_1);
					SET_BIT(RCC->CFGR,HPRE_2);
					SET_BIT(RCC->CFGR,HPRE_3);
				break;
				case AHB_PRE_512:
					/* 1111: system clock divided by 512 */
					SET_BIT(RCC->CFGR,HPRE_0);
					SET_BIT(RCC->CFGR,HPRE_1);
					SET_BIT(RCC->CFGR,HPRE_2);
					SET_BIT(RCC->CFGR,HPRE_3);
				break;
				default:
				break;
			}
}

/***********************************************************************************/
/* Function Name  : MRCC_vInitAPB1Prescaler                                        */
/* Function Info  : Inits APB1 PreScalar					                       */
/* Function Input : APB1 Prescalar options(APB1_PRESCL_t)						   */
/* 					APB1_PRE_1, APB1_PRE_1, APB1_PRE_4, APB1_PRE_8, APB1_PRE_16	   */
/* Function Return: None						                                   */
/***********************************************************************************/
static void MRCC_vInitAPB1Prescaler(APB1_PRESCL_t Copy_tAPB1_PRE){
	switch(Copy_tAPB1_PRE){
			case APB1_PRE_1:
				/* 0xx: AHB clock not divided */
				CLR_BIT(RCC->CFGR,PPRE1_0);
				CLR_BIT(RCC->CFGR,PPRE1_1);
				CLR_BIT(RCC->CFGR,PPRE1_2);
			break;
			case APB1_PRE_2:
				/* 100: AHB clock divided by 2 */
				CLR_BIT(RCC->CFGR,PPRE1_0);
				CLR_BIT(RCC->CFGR,PPRE1_1);
				SET_BIT(RCC->CFGR,PPRE1_2);
			break;
			case APB1_PRE_4:
				/* 101: AHB clock divided by 4 */
				SET_BIT(RCC->CFGR,PPRE1_0);
				CLR_BIT(RCC->CFGR,PPRE1_1);
				SET_BIT(RCC->CFGR,PPRE1_2);
			break;
			case APB1_PRE_8:
				/* 110: AHB clock divided by 8 */
				CLR_BIT(RCC->CFGR,PPRE1_0);
				SET_BIT(RCC->CFGR,PPRE1_1);
				SET_BIT(RCC->CFGR,PPRE1_2);
			break;
			case APB1_PRE_16:
				/* 111: AHB clock divided by 16 */
				SET_BIT(RCC->CFGR,PPRE1_0);
				SET_BIT(RCC->CFGR,PPRE1_1);
				SET_BIT(RCC->CFGR,PPRE1_2);
			break;
			default:
			break;
		}
}



/***********************************************************************************/
/* Function Name  : MRCC_vAPB2InitPrescaler                                        */
/* Function Info  : Inits APB2 PreScalar					                       */
/* Function Input : APB2 Prescalar options(APB2_PRESCL_t)						   */
/* 					APB2_PRE_1, APB2_PRE_2, APB2_PRE_4, APB2_PRE_8, APB2_PRE_16	   */
/* Function Return: None						                                   */
/***********************************************************************************/
static void MRCC_vInitAPB2Prescaler(APB2_PRESCL_t Copy_tAPB2_PRE){
	switch(Copy_tAPB2_PRE){
		case APB2_PRE_1:
			/* 0xx: AHB clock not divided */
			CLR_BIT(RCC->CFGR,PPRE2_0);
			CLR_BIT(RCC->CFGR,PPRE2_1);
			CLR_BIT(RCC->CFGR,PPRE2_2);
		break;
		case APB2_PRE_2:
			/* 100: AHB clock divided by 2 */
			CLR_BIT(RCC->CFGR,PPRE2_0);
			CLR_BIT(RCC->CFGR,PPRE2_1);
			SET_BIT(RCC->CFGR,PPRE2_2);
		break;
		case APB2_PRE_4:
			/* 101: AHB clock divided by 4 */
			SET_BIT(RCC->CFGR,PPRE2_0);
			CLR_BIT(RCC->CFGR,PPRE2_1);
			SET_BIT(RCC->CFGR,PPRE2_2);
		break;
		case APB2_PRE_8:
			/* 110: AHB clock divided by 8 */
			CLR_BIT(RCC->CFGR,PPRE2_0);
			SET_BIT(RCC->CFGR,PPRE2_1);
			SET_BIT(RCC->CFGR,PPRE2_2);
		break;
		case APB2_PRE_16:
			/* 111: AHB clock divided by 16 */
			SET_BIT(RCC->CFGR,PPRE2_0);
			SET_BIT(RCC->CFGR,PPRE2_1);
			SET_BIT(RCC->CFGR,PPRE2_2);
		break;
		default:
		break;
	}
}

/***********************************************************************************/
/* Function Name  : MRCC_vInitHSE_SRC                                              */
/* Function Info  : Sets HSE Source							                       */
/* Function Input : HSE source options(HSE_Src_t): HSE_Crystal, HSE_RC			   */
/* Function Return: None						                                   */
/***********************************************************************************/
static void MRCC_vInitHSE_SRC(HSE_Src_t Copy_t_HSE_SRC){
	switch(Copy_t_HSE_SRC){
		case HSE_Crystal:
			CLR_BIT(RCC->CR,HSEBYP);
		break;
		case HSE_RC:
			SET_BIT(RCC->CR,HSEBYP);
		break;
		default:
		break;
	}
}


/***********************************************************************************/
/* Function Name  : MRCC_vInitHSE_SRC                                              */
/* Function Info  : Sets PLL Source							                       */
/* Function Input : PLL source options(PLL_Src_t): PLL_HSI, PLL_HSE  			   */
/* Function Return: None						                                   */
/***********************************************************************************/
static void MRCC_vInitPLL_SRC(PLL_Src_t Copy_tPLL_SRC){
	switch(Copy_tPLL_SRC){
		case PLL_HSI:
			/*Enable HSI*/
			SET_BIT(RCC->CR,HSION);
			/*Select HSI as PLL source*/
			CLR_BIT(RCC->PLLCFGR,PLLSRC);
		break;
		case PLL_HSE:
			/*Enable HSE*/
			SET_BIT(RCC->CR,HSEON);
			/*Select HSE as PLL source*/
			SET_BIT(RCC->PLLCFGR,PLLSRC);
		break;
		default:
		break;
	}
}


/***********************************************************************************/
/* Function Name  : MRCC_vEnablePeripheralClk                                      */
/* Function Info  : Enable peripheral clock					                       */
/* Function Input : - Buses options(Bus_t): AHB1_BUS, AHB2_BUS, APB1_BUS, APB2_BUS
 * 					- Peripheral number on the bus								   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MRCC_vEnablePeripheralClk(Bus_t Copy_tBusName,u8 PeripheralNumber){
	switch(Copy_tBusName){
		/* GPIO, CRC, and DMA*/
		case AHB1_BUS:
			SET_BIT(RCC->AHB1ENR,PeripheralNumber);
		break;
		case AHB2_BUS:
			SET_BIT(RCC->AHB2ENR,PeripheralNumber);
		break;
		case APB1_BUS:
			SET_BIT(RCC->APB1ENR,PeripheralNumber);
		break;
		case APB2_BUS:
			SET_BIT(RCC->APB2ENR,PeripheralNumber);
		break;
		default:
		break;
	}
}


/***********************************************************************************/
/* Function Name  : MRCC_vDisablePeripheralClk                                     */
/* Function Info  : Disable peripheral clock					                   */
/* Function Input : - Buses options(Bus_t): AHB1_BUS, AHB2_BUS, APB1_BUS, APB2_BUS
 * 					- Peripheral number on the bus								   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MRCC_vDisablePeripheralClk(Bus_t Copy_tBusName,u8 PeripheralNumber){
	switch(Copy_tBusName){
			/* GPIO, CRC, and DMA*/
			case AHB1_BUS:
				SET_BIT(RCC->AHB1RSTR,PeripheralNumber);
			break;
			case AHB2_BUS:
				SET_BIT(RCC->AHB2RSTR,PeripheralNumber);
			break;
			case APB1_BUS:
				SET_BIT(RCC->APB1RSTR,PeripheralNumber);
			break;
			case APB2_BUS:
				SET_BIT(RCC->APB2RSTR,PeripheralNumber);
			break;
			default:
			break;
		}
}
