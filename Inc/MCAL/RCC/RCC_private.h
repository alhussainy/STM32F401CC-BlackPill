/***********************************************************************************/
/* File Name : RCC_private.h                                                       */
/* File Info : Contains RCC Registers and Macros								   */
/* Version   : V1.0                                                                */
/* Date      : 23 Feb. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Guard*********************************/
/***********************************************************************************/
#ifndef MCAL_RCC_RCC_PRIVATE_H_
#define MCAL_RCC_RCC_PRIVATE_H_

/***********************************************************************************
*	  - Developer can't Edit in it
*	  - Design :
					- #define	:	NO
					- Union		:	NO
					- Struct	:	YES
************************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/



/***********************************************************************************
	-----> Macros
			*  Base_Address RCC 0x40023800
************************************************************************************/

#define RCC_BASE_ADD	0x40023800


/***********************************************************************************/
/****************************User-defined data types********************************/
/***********************************************************************************/
typedef struct{
	volatile u32 CR;				/* RCC clock control register */
	volatile u32 PLLCFGR;			/* RCC PLL configuration register */
	volatile u32 CFGR;				/* RCC clock configuration register */
	volatile u32 CIR;				/* RCC clock interrupt register */
	volatile u32 AHB1RSTR;
	volatile u32 AHB2RSTR;
	volatile u32 RESERVED_1[2];
	volatile u32 APB1RSTR;
	volatile u32 APB2RSTR;
	volatile u32 RESERVED_2[2];
	volatile u32 AHB1ENR;
	volatile u32 AHB2ENR;
	volatile u32 RESERVED_3[2];
	volatile u32 APB1ENR;
	volatile u32 APB2ENR;
	volatile u32 RESERVED_4[2];
	volatile u32 AHB1LPENR;
	volatile u32 AHB2LPENR;
	volatile u32 RESERVED_5[2];
	volatile u32 APB1LPENR;
	volatile u32 APB2LPENR;
	volatile u32 RESERVED_6[2];
	volatile u32 BDCR;
	volatile u32 CSR;
	volatile u32 RESERVED_7[2];
	volatile u32 SSCGR;
	volatile u32 PLLI2SCFGR;
	volatile u32 RESERVED_8;
	volatile u32 DCKCFGR;
} RCC_t;

#define RCC ((volatile RCC_t*)(RCC_BASE_ADD))
/* Buses options*/
typedef enum{
	AHB1_BUS =0	,
	AHB2_BUS	,
	APB1_BUS	,
	APB2_BUS
} Bus_t;
/* RCC source options */
typedef enum{
	HSI = 0	,
	HSE		,
	PLL
}RCC_Src_t;
/* HSE source options */
typedef enum{
	HSE_Crystal	=0	,
	HSE_RC
} HSE_Src_t;
/* PLL source options */
typedef enum{
	PLL_HSI	=0	,
	PLL_HSE
} PLL_Src_t;
/* AHB Prescalar options */
typedef enum{
	AHB_PRE_1	=0	,
	AHB_PRE_2		,
	AHB_PRE_4		,
	AHB_PRE_8		,
	AHB_PRE_16		,
	AHB_PRE_64		,
	AHB_PRE_128		,
	AHB_PRE_256		,
	AHB_PRE_512		,
} AHB_PRESCL_t;
/* APB1 Prescalar options */
typedef enum{
	APB1_PRE_1	=0	,
	APB1_PRE_2		,
	APB1_PRE_4		,
	APB1_PRE_8		,
	APB1_PRE_16
} APB1_PRESCL_t;
/* APB2 Prescalar options */
typedef enum{
	APB2_PRE_1	=0	,
	APB2_PRE_2		,
	APB2_PRE_4		,
	APB2_PRE_8		,
	APB2_PRE_16
} APB2_PRESCL_t;
/***********************************************************************************/
/*RCC->RC Bits*/
#define PLLI2SRDY	27U /* PLLI2S clock ready flag */
#define PLLI2SON	26U /* PLLI2S enable */
#define PLLRDY		25U /* Main PLL (PLL) clock ready flag */
#define PLLON		24U /* Main PLL (PLL) enable */
/* PLLON Notes:
	- Cleared by hardware when entering Stop or Standby mode.
	- This bit cannot be reset if PLL clock is used as the system clock
*/
#define CSSON		19U /* Clock security system enable */
#define HSEBYP		18U /* HSE clock bypass */
/* HSEBYP Notes:
	- The external clock must be enabled with the HSEON bit, to be used by the device.
	- The HSEBYP bit can be written only if the HSE oscillator is disabled.
*/
#define HSERDY		17U /* HSE clock ready flag */
#define HSEON		16U /* HSE clock enable */
/* HSEON Notes:
	- Cleared by hardware to stop the HSE oscillator when entering Stop or Standby mode.
	- This bit cannot be reset if the HSE oscillator is used directly or indirectly as
	  the system clock.
*/
#define HSIRDY		01U /* Internal high-speed clock ready flag */
#define HSION		00U /* Internal high-speed clock enable */
/* HSION Notes:
	- Set by hardware to force the HSI oscillator ON when leaving the Stop or Standby mode
	  or in case of a failure of the HSE oscillator used directly or indirectly as the system
	  clock.
	- This bit cannot be reset if the HSI oscillator is used directly or indirectly as
	  the system clock.
*/
/*RCC->RC Bits End*/
/***********************************************************************************/



/***********************************************************************************/
/*RCC->PLLCFGR Bits*/
/*
This register is used to configure the PLL clock outputs according to the formulas:
• f(VCO clock) = f(PLL clock input) × (PLLN / PLLM)
• f(PLL general clock output) = f(VCO clock) / PLLP
• f(USB OTG FS, SDIO, RNG clock output) = f(VCO clock) / PLLQ
*/
/*
//TODO:
* Bits 27:24 PLLQ: Main PLL (PLL) division factor for USB OTG FS, SDIO and random
  number generator clocks.
*/
#define PLLSRC		22U /* Main PLL(PLL) and audio PLL (PLLI2S) entry clock source */
/*PLLSRC Values:
* 0: HSI clock selected as PLL and PLLI2S clock entry
* 1: HSE oscillator clock selected as PLL and PLLI2S clock entry
*/
/*RCC->PLLCFGR Bits End*/
/***********************************************************************************/



/***********************************************************************************/
/*RCC->CFGR Bits*/
/*
//TODO:
* Microcontroller clock output 2 & 1
* HSE division factor for RTC clock
*/
#define I2SSRC		23U /* I2S clock selection */

#define PPRE2_0		13U /*APB high-speed prescaler (APB2)*/
#define PPRE2_1		14U /*APB high-speed prescaler (APB2)*/
#define PPRE2_2		15U /*APB high-speed prescaler (APB2)*/
/*3 bits: 13-14-15*/
/*
* 0xx: AHB clock not divided
* 100: AHB clock divided by 2
* 101: AHB clock divided by 4
* 110: AHB clock divided by 8
* 111: AHB clock divided by 16
*/
#define PPRE1_0		10U /* APB Low speed prescaler (APB1) */
#define PPRE1_1		11U /* APB Low speed prescaler (APB1) */
#define PPRE1_2		12U /* APB Low speed prescaler (APB1) */
/*3 bits: 10-11-12*/
/*
* 0xx: AHB clock not divided
* 100: AHB clock divided by 2
* 101: AHB clock divided by 4
* 110: AHB clock divided by 8
* 111: AHB clock divided by 16
*/
#define HPRE_0		04U /* AHB prescaler */
#define HPRE_1		05U /* AHB prescaler */
#define HPRE_2		06U /* AHB prescaler */
#define HPRE_3		07U /* AHB prescaler */
/*4 bits: 4-5-6-7 */
/*
* 0xxx: system clock not divided
* 1000: system clock divided by 2
* 1001: system clock divided by 4
* 1010: system clock divided by 8
* 1011: system clock divided by 16
* 1100: system clock divided by 64
* 1101: system clock divided by 128
* 1110: system clock divided by 256
* 1111: system clock divided by 512
*/
#define SWS			02U /* System clock switch status*/

#define SW1			00U /* System clock switch */
#define SW0			00U /* System clock switch */
/* 2 bits: 0-1*/
/*
 * 00: HSI oscillator selected as system clock
 * 01: HSE oscillator selected as system clock
 * 10: PLL selected as system clock
 * 11: not allowed
 */
/*RCC->CFGR Bits End*/
/***********************************************************************************/



/***********************************************************************************/
/*RCC->CIR Bits*/ /* RCC clock interrupt register */

#define CSSC			23U /* Clock security system interrupt clear  */
/*This bit is set by software to clear the CSSF flag*/

#define PLLI2SRDYC		21U /* PLLI2S ready interrupt clear */
/*This bit is set by software to clear the PLLI2SRDYF flag.*/

#define PLLRDYC			20U /* Main PLL(PLL) ready interrupt clear */
/*This bit is set by software to clear the PLLRDYF flag.*/

#define HSERDYC			19U /* HSE ready interrupt clear */
/*This bit is set by software to clear the HSERDYF flag.*/

#define HSIRDYC			18U /* HSI ready interrupt clear */
/*This bit is set software to clear the HSIRDYF flag.*/

#define LSERDYC			17U /* LSE ready interrupt clear */
/*This bit is set by software to clear the LSERDYF flag.*/

#define LSIRDYC			16U /* LSI ready interrupt clear */
/*This bit is set by software to clear the LSIRDYF flags.*/

/*Interrupt Enable*/
#define PLLI2SRDYIE		13U /*  PLLI2S ready interrupt enable */
#define PLLRDYIE		12U /*  Main PLL (PLL) ready interrupt enable */
#define HSERDYIE		11U /*  HSE ready interrupt enable */
#define HSIRDYIE		10U /*  HSI ready interrupt enable */
#define LSERDYIE		09U /*  LSE ready interrupt enable */
#define LSIRDYIE		08U /*  LSI ready interrupt enable */

/*Interrupt Flags */
#define CSSF			07U /*  Clock security system interrupt flag */
/*CSSF Notes:
 * - Set by hardware when a failure is detected in the HSE oscillator.
 * - Cleared by software setting the CSSC bit.
 */
#define PLLI2SRDYF		05U /*  PLLI2S ready interrupt flag */
#define PLLRDYF			04U /*  Main PLL (PLL) ready interrupt flag */
#define HSERDYF			03U /*  HSE ready interrupt flag */
#define HSIRDYF			02U /*  HSI ready interrupt flag */
#define LSERDYF			01U /*  LSE ready interrupt flag */
#define LSIRDYF			02U /*  LSI ready interrupt flag */
/*RCC->CIR Bits End*/
/***********************************************************************************/

/***********************************************************************************/
/*RCC->AHB1RSTR Bits*/ /* RCC AHB1 peripheral reset register */

/*General RESET BITs Notes:
* 0: does not reset
* 1: resets
*/
#define DMA2RST			22U /* DMA2 reset  */
#define DMA1RST			21U /* DMA1 reset */
#define CRCRST			12U /* CRC reset */
#define GPIOCRST		02U /* IO port C reset */
#define GPIOBRST		01U /* IO port B reset */
#define GPIOARST		00U /* IO port A reset */

/*RCC->AHB1RSTR Bits End*/
/***********************************************************************************/

/***********************************************************************************/
/*RCC->AHB1ENR Bits*/ /* RCC AHB1 peripheral clock enable register */

/*General RESET BITs Notes:
* 0: clock disabled
* 1: clock enabled
*/
#define DMA2EN			22U /* DMA2 clock enable */
#define DMA1EN			21U /* DMA1 clock enable */
#define CRCEN			12U /* CRC clock enable */
#define GPIOCEN			02U /* IO port C clock enable */
#define GPIOBEN			01U /* IO port B clock enable */
#define GPIOAEN			00U /* IO port A clock enable */

/*RCC->AHB1RSTR Bits End*/
/***********************************************************************************/
/* TODO:
 * RCC AHB2 peripheral reset register
 * RCC APB1 peripheral reset register
 * RCC APB2 peripheral reset register
 * RCC AHB2 peripheral clock enable register
 * RCC APB1 peripheral clock enable register
 * peripheral clock enable in low power mode register
 */


/***********************************************************************************/
/****************************Functions Declaration**********************************/
/***********************************************************************************/

/***********************************************************************************/
/* Function Name  : MRCC_vInitAHBPrescaler                                         */
/* Function Info  : Inits PreScalar							                       */
/* Function Input : - AHB Prescalar options(AHB_PRESCL_t)						   */
/* Function Return: None						                                   */
/***********************************************************************************/
static void MRCC_vInitAHBPrescaler(AHB_PRESCL_t Copy_tAHB_PRE);

/***********************************************************************************/
/* Function Name  : MRCC_vInitAPB1Prescaler                                        */
/* Function Info  : Inits APB1 PreScalar					                       */
/* Function Input : APB1 Prescalar options(APB1_PRESCL_t)						   */
/* Function Return: None						                                   */
/***********************************************************************************/
static void MRCC_vInitAPB1Prescaler(APB1_PRESCL_t Copy_tAPB1_PRE);

/***********************************************************************************/
/* Function Name  : MRCC_vAPB2InitPrescaler                                        */
/* Function Info  : Inits APB2 PreScalar					                       */
/* Function Input : APB2 Prescalar options(APB2_PRESCL_t)						   */
/* Function Return: None						                                   */
/***********************************************************************************/
static void MRCC_vInitAPB2Prescaler(APB2_PRESCL_t Copy_tAPB2_PRE);

/***********************************************************************************/
/* Function Name  : MRCC_vInitHSE_SRC                                              */
/* Function Info  : Sets HSE Source							                       */
/* Function Input : HSE source options(HSE_Src_t): HSE_Crystal, HSE_RC			   */
/* Function Return: None						                                   */
/***********************************************************************************/
static void MRCC_vInitHSE_SRC(HSE_Src_t Copy_t_HSE_SRC);

/***********************************************************************************/
/* Function Name  : MRCC_vInitHSE_SRC                                              */
/* Function Info  : Sets PLL Source							                       */
/* Function Input : PLL source options(PLL_Src_t): PLL_HSI, PLL_HSE  			   */
/* Function Return: None						                                   */
/***********************************************************************************/
static void MRCC_vInitPLL_SRC(PLL_Src_t Copy_tPLL_SRC);

#endif /* MCAL_RCC_RCC_PRIVATE_H_ */
