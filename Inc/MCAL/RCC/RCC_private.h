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
	volatile u32 CIR;
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
	AHB1 =0	,
	AHB2	,
	APB1	,
	APB2
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
} AHB_Src_t;
/* APB1 Prescalar options */
typedef enum{
	APB1_PRE_1	=0	,
	APB1_PRE_2		,
	APB1_PRE_4		,
	APB1_PRE_8		,
	APB1_PRE_16
} APB1_Src_t;
/* APB2 Prescalar options */
typedef enum{
	APB2_PRE_1	=0	,
	APB2_PRE_2		,
	APB2_PRE_4		,
	APB2_PRE_8		,
	APB2_PRE_16
} APB2_Src_t;
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

#define PPRE2		13U /*APB high-speed prescaler (APB2)*/
/*3 bits: 13-14-15*/
/*
* 0xx: AHB clock not divided
* 100: AHB clock divided by 2
* 101: AHB clock divided by 4
* 110: AHB clock divided by 8
* 111: AHB clock divided by 16
*/
#define PPRE1		10U /* APB Low speed prescaler (APB1) */
/*3 bits: 10-11-12*/
/*
* 0xx: AHB clock not divided
* 100: AHB clock divided by 2
* 101: AHB clock divided by 4
* 110: AHB clock divided by 8
* 111: AHB clock divided by 16
*/
#define HPRE		04U /* AHB prescaler */
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

#define SW			00U /* System clock switch */
/* 2 bits: 0-1*/
/*
 * 00: HSI oscillator selected as system clock
 * 01: HSE oscillator selected as system clock
 * 10: PLL selected as system clock
 * 11: not allowed
 */
/*RCC->CFGR Bits End*/
/***********************************************************************************/

#endif /* MCAL_RCC_RCC_PRIVATE_H_ */
