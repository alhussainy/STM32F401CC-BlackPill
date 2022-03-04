/***********************************************************************************/
/* File Name : LCD_config.h                                                        */
/* File Info : Contains configuration options for LCD							   */
/* Version   : V1.0                                                                */
/* Date      : 28 Feb. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Guard*********************************/
/***********************************************************************************/
#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_


/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/

/***********************************************************************************
	-----> Macros
			*  Pins mapping for LCD
************************************************************************************/
/*LCD_MODE options:
 * 					-> _8_DATA_MODE
 * 					-> _4_DATA_MODE
 */
#define LCD_MODE	_4_DATA_MODE

/*Assume that All LCD pins are on the same port and only write opertion allowed*/
#define LCD_PORT	GPIOA

#define LCD_PIN_RS	PIN8
#define	LCD_PIN_EN	PIN9
#define LCD_PIN_D0	PIN0
#define LCD_PIN_D1	PIN1
#define LCD_PIN_D2	PIN2
#define LCD_PIN_D3	PIN3
#define LCD_PIN_D4	PIN4
#define LCD_PIN_D5	PIN5
#define LCD_PIN_D6	PIN6
#define LCD_PIN_D7	PIN7

#endif /* HAL_LCD_LCD_CONFIG_H_ */
