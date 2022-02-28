/***********************************************************************************/
/* File Name : SSD_program.c                              	                       */
/* File Info : Contains functions implementation								   */
/* Version   : V1.0                                                                */
/* Date      : 28 Feb. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "SSD_interface.h"

/***********************************************************************************/
/* Function Name  : HSSD_vInit                                                     */
/* Function Info  : Inits Seven segments display				                   */
/* Function Input : None														   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HSSD_vInit(void){
	/*init SSD Pins as Input)*/
	MGPIO_vSetMode(SSD_PORT, SSD_PINA, OUTPUT_MODE);
	MGPIO_vSetMode(SSD_PORT, SSD_PINB, OUTPUT_MODE);
	MGPIO_vSetMode(SSD_PORT, SSD_PINC, OUTPUT_MODE);
	MGPIO_vSetMode(SSD_PORT, SSD_PIND, OUTPUT_MODE);
	MGPIO_vSetMode(SSD_PORT, SSD_PINE, OUTPUT_MODE);
	MGPIO_vSetMode(SSD_PORT, SSD_PINF, OUTPUT_MODE);
	MGPIO_vSetMode(SSD_PORT, SSD_PING, OUTPUT_MODE);
	MGPIO_vSetOutputType(SSD_PORT, SSD_PINA, OUT_PUSH_PULL);
	MGPIO_vSetOutputType(SSD_PORT, SSD_PINB, OUT_PUSH_PULL);
	MGPIO_vSetOutputType(SSD_PORT, SSD_PINC, OUT_PUSH_PULL);
	MGPIO_vSetOutputType(SSD_PORT, SSD_PIND, OUT_PUSH_PULL);
	MGPIO_vSetOutputType(SSD_PORT, SSD_PINE, OUT_PUSH_PULL);
	MGPIO_vSetOutputType(SSD_PORT, SSD_PINF, OUT_PUSH_PULL);
	MGPIO_vSetOutputType(SSD_PORT, SSD_PING, OUT_PUSH_PULL);
	MGPIO_vSetOutputSpeed(SSD_PORT, SSD_PINA, OUT_LOW_SP);
	MGPIO_vSetOutputSpeed(SSD_PORT, SSD_PINB, OUT_LOW_SP);
	MGPIO_vSetOutputSpeed(SSD_PORT, SSD_PINC, OUT_LOW_SP);
	MGPIO_vSetOutputSpeed(SSD_PORT, SSD_PIND, OUT_LOW_SP);
	MGPIO_vSetOutputSpeed(SSD_PORT, SSD_PINE, OUT_LOW_SP);
	MGPIO_vSetOutputSpeed(SSD_PORT, SSD_PINF, OUT_LOW_SP);
	MGPIO_vSetOutputSpeed(SSD_PORT, SSD_PING, OUT_LOW_SP);
}

/***********************************************************************************/
/* Function Name  : HSSD_vDisplayNum                                                     */
/* Function Info  : Displays numbers(0:9)         				                   */
/* Function Input : Number to be displayed										   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HSSD_vDisplayNum(u8 Copy_u8Num){
	switch(Copy_u8Num){
		case 0:
				MGPIO_vWritePin(SSD_PORT, SSD_PINA, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINB, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINC, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PIND, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINE, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINF, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PING, OUT_LOW);
		break;

		case 1:
				MGPIO_vWritePin(SSD_PORT, SSD_PINA, OUT_LOW);
				MGPIO_vWritePin(SSD_PORT, SSD_PINB, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINC, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PIND, OUT_LOW);
				MGPIO_vWritePin(SSD_PORT, SSD_PINE, OUT_LOW);
				MGPIO_vWritePin(SSD_PORT, SSD_PINF, OUT_LOW);
				MGPIO_vWritePin(SSD_PORT, SSD_PING, OUT_LOW);
		break;

		case 2:
				MGPIO_vWritePin(SSD_PORT, SSD_PINA, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINB, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINC, OUT_LOW);
				MGPIO_vWritePin(SSD_PORT, SSD_PIND, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINE, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINF, OUT_LOW);
				MGPIO_vWritePin(SSD_PORT, SSD_PING, OUT_HIGH);
		break;

		case 3:
				MGPIO_vWritePin(SSD_PORT, SSD_PINA, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINB, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINC, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PIND, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINE, OUT_LOW);
				MGPIO_vWritePin(SSD_PORT, SSD_PINF, OUT_LOW);
				MGPIO_vWritePin(SSD_PORT, SSD_PING, OUT_HIGH);
		break;


		case 4:
				MGPIO_vWritePin(SSD_PORT, SSD_PINA, OUT_LOW);
				MGPIO_vWritePin(SSD_PORT, SSD_PINB, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINC, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PIND, OUT_LOW);
				MGPIO_vWritePin(SSD_PORT, SSD_PINE, OUT_LOW);
				MGPIO_vWritePin(SSD_PORT, SSD_PINF, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PING, OUT_HIGH);
		break;


		case 5:
				MGPIO_vWritePin(SSD_PORT, SSD_PINA, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINB, OUT_LOW);
				MGPIO_vWritePin(SSD_PORT, SSD_PINC, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PIND, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINE, OUT_LOW);
				MGPIO_vWritePin(SSD_PORT, SSD_PINF, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PING, OUT_HIGH);
		break;

		case 6:
				MGPIO_vWritePin(SSD_PORT, SSD_PINA, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINB, OUT_LOW);
				MGPIO_vWritePin(SSD_PORT, SSD_PINC, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PIND, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINE, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINF, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PING, OUT_HIGH);
		break;

		case 7:
				MGPIO_vWritePin(SSD_PORT, SSD_PINA, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINB, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINC, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PIND, OUT_LOW);
				MGPIO_vWritePin(SSD_PORT, SSD_PINE, OUT_LOW);
				MGPIO_vWritePin(SSD_PORT, SSD_PINF, OUT_LOW);
				MGPIO_vWritePin(SSD_PORT, SSD_PING, OUT_LOW);
		break;

		case 8:
				MGPIO_vWritePin(SSD_PORT, SSD_PINA, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINB, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINC, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PIND, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINE, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINF, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PING, OUT_HIGH);
		break;

		case 9:
				MGPIO_vWritePin(SSD_PORT, SSD_PINA, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINB, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINC, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PIND, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PINE, OUT_LOW);
				MGPIO_vWritePin(SSD_PORT, SSD_PINF, OUT_HIGH);
				MGPIO_vWritePin(SSD_PORT, SSD_PING, OUT_HIGH);
		break;

		default:
		break;
	}
}

