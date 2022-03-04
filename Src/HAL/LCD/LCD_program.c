/***********************************************************************************/
/* File Name : LCD_program.c                              	                       */
/* File Info : Contains functions implementation								   */
/* Version   : V1.0                                                                */
/* Date      : 01 Mar. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "LCD_interface.h"


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


/*Dummy_delay until implementing timer delay function*/
static void DUMMY_DELAY(u16 Copy_u16Time){
	 volatile int i=0;
	 for(i=0;i<1000*Copy_u16Time;i++){};
}



/***********************************************************************************/
/* Function Name  : HLCD_vInit                                                     */
/* Function Info  : Inits LCD display							                   */
/* Function Input : None														   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vInit(void){
	#if LCD_MODE == _8_DATA_MODE
		MGPIO_vSetMode(LCD_PORT, LCD_PIN_RS, OUTPUT_MODE);
		MGPIO_vSetMode(LCD_PORT, LCD_PIN_EN, OUTPUT_MODE);
		MGPIO_vSetMode(LCD_PORT, LCD_PIN_D0, OUTPUT_MODE);
		MGPIO_vSetMode(LCD_PORT, LCD_PIN_D1, OUTPUT_MODE);
		MGPIO_vSetMode(LCD_PORT, LCD_PIN_D2, OUTPUT_MODE);
		MGPIO_vSetMode(LCD_PORT, LCD_PIN_D3, OUTPUT_MODE);
		MGPIO_vSetMode(LCD_PORT, LCD_PIN_D4, OUTPUT_MODE);
		MGPIO_vSetMode(LCD_PORT, LCD_PIN_D5, OUTPUT_MODE);
		MGPIO_vSetMode(LCD_PORT, LCD_PIN_D6, OUTPUT_MODE);
		MGPIO_vSetMode(LCD_PORT, LCD_PIN_D7, OUTPUT_MODE);
		MGPIO_vSetOutputType(LCD_PORT, LCD_PIN_RS, OUT_PUSH_PULL);
		MGPIO_vSetOutputType(LCD_PORT, LCD_PIN_EN, OUT_PUSH_PULL);
		MGPIO_vSetOutputType(LCD_PORT, LCD_PIN_D0, OUT_PUSH_PULL);
		MGPIO_vSetOutputType(LCD_PORT, LCD_PIN_D1, OUT_PUSH_PULL);
		MGPIO_vSetOutputType(LCD_PORT, LCD_PIN_D2, OUT_PUSH_PULL);
		MGPIO_vSetOutputType(LCD_PORT, LCD_PIN_D3, OUT_PUSH_PULL);
		MGPIO_vSetOutputType(LCD_PORT, LCD_PIN_D4, OUT_PUSH_PULL);
		MGPIO_vSetOutputType(LCD_PORT, LCD_PIN_D5, OUT_PUSH_PULL);
		MGPIO_vSetOutputType(LCD_PORT, LCD_PIN_D6, OUT_PUSH_PULL);
		MGPIO_vSetOutputType(LCD_PORT, LCD_PIN_D7, OUT_PUSH_PULL);
		MGPIO_vSetOutputSpeed(LCD_PORT, LCD_PIN_RS, OUT_LOW_SP);
		MGPIO_vSetOutputSpeed(LCD_PORT, LCD_PIN_EN, OUT_LOW_SP);
		MGPIO_vSetOutputSpeed(LCD_PORT, LCD_PIN_D0, OUT_LOW_SP);
		MGPIO_vSetOutputSpeed(LCD_PORT, LCD_PIN_D1, OUT_LOW_SP);
		MGPIO_vSetOutputSpeed(LCD_PORT, LCD_PIN_D2, OUT_LOW_SP);
		MGPIO_vSetOutputSpeed(LCD_PORT, LCD_PIN_D3, OUT_LOW_SP);
		MGPIO_vSetOutputSpeed(LCD_PORT, LCD_PIN_D4, OUT_LOW_SP);
		MGPIO_vSetOutputSpeed(LCD_PORT, LCD_PIN_D5, OUT_LOW_SP);
		MGPIO_vSetOutputSpeed(LCD_PORT, LCD_PIN_D6, OUT_LOW_SP);
		MGPIO_vSetOutputSpeed(LCD_PORT, LCD_PIN_D7, OUT_LOW_SP);
		/***_THIS_COMMAND_TO_ACTIVE_8_BIT_MODE_***/
		HLCD_vSendCommand(0x38);
	#else
		MGPIO_vSetMode(LCD_PORT, LCD_PIN_RS, OUTPUT_MODE);
		MGPIO_vSetMode(LCD_PORT, LCD_PIN_EN, OUTPUT_MODE);
		MGPIO_vSetMode(LCD_PORT, LCD_PIN_D4, OUTPUT_MODE);
		MGPIO_vSetMode(LCD_PORT, LCD_PIN_D5, OUTPUT_MODE);
		MGPIO_vSetMode(LCD_PORT, LCD_PIN_D6, OUTPUT_MODE);
		MGPIO_vSetMode(LCD_PORT, LCD_PIN_D7, OUTPUT_MODE);
		MGPIO_vSetOutputType(LCD_PORT, LCD_PIN_RS, OUT_PUSH_PULL);
		MGPIO_vSetOutputType(LCD_PORT, LCD_PIN_EN, OUT_PUSH_PULL);
		MGPIO_vSetOutputType(LCD_PORT, LCD_PIN_D4, OUT_PUSH_PULL);
		MGPIO_vSetOutputType(LCD_PORT, LCD_PIN_D5, OUT_PUSH_PULL);
		MGPIO_vSetOutputType(LCD_PORT, LCD_PIN_D6, OUT_PUSH_PULL);
		MGPIO_vSetOutputType(LCD_PORT, LCD_PIN_D7, OUT_PUSH_PULL);
		MGPIO_vSetOutputSpeed(LCD_PORT, LCD_PIN_RS, OUT_LOW_SP);
		MGPIO_vSetOutputSpeed(LCD_PORT, LCD_PIN_EN, OUT_LOW_SP);
		MGPIO_vSetOutputSpeed(LCD_PORT, LCD_PIN_D4, OUT_LOW_SP);
		MGPIO_vSetOutputSpeed(LCD_PORT, LCD_PIN_D5, OUT_LOW_SP);
		MGPIO_vSetOutputSpeed(LCD_PORT, LCD_PIN_D6, OUT_LOW_SP);
		MGPIO_vSetOutputSpeed(LCD_PORT, LCD_PIN_D7, OUT_LOW_SP);
		/***_THIS_COMMAND_TO_ACTIVE _4_BIT_MODE_***/
		HLCD_vSendCommand(0x33);
		HLCD_vSendCommand(0x32);
		HLCD_vSendCommand(0x28);
	#endif

		HLCD_vSendCommand(0x0C);   /***_THIS_COMMAND_TO_TURN_ON_DISPLAY_AND_TURN_OFF_CURSOR_***/
		HLCD_vSendCommand(0x01);   /***_THIS_COMMAND_TO_CLEAR_LCD_*****************************/
		HLCD_vSendCommand(0x06);   /***_THIS_COMMAND_TO_MOVE_CURSOR_FROM_LEFT_TO_RIGHT_********/
		HLCD_vSendCommand(0x02);   /***_THIS_COMMAND_TO_RETURN_HOME_***************************/
}


/***********************************************************************************/
/* Function Name  : HLCD_vSendCommand                                              */
/* Function Info  : Sends a command to LCD 						                   */
/* Function Input : LCD Command													   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vSendCommand(u8 Copy_u8Command){
	MGPIO_vWritePin(LCD_PORT, LCD_PIN_RS, OUT_LOW);
	#if LCD_MODE == _8_DATA_MODE
		MGPIO_vWritePort(LCD_PORT,LCD_PIN_D0,_8_BITS,Copy_u8Command);
		MGPIO_vWritePin(LCD_PORT, LCD_PIN_EN, OUT_HIGH);
		DUMMY_DELAY(20);
		MGPIO_vWritePin(LCD_PORT, LCD_PIN_EN, OUT_LOW);
		DUMMY_DELAY(100);
	#else
		MGPIO_vWritePort(LCD_PORT,LCD_PIN_D4,_4_BITS,((Copy_u8Command>>4)&0x0F));
		MGPIO_vWritePin(LCD_PORT, LCD_PIN_EN, OUT_HIGH);
		DUMMY_DELAY(20);
		MGPIO_vWritePin(LCD_PORT, LCD_PIN_EN, OUT_LOW);
		DUMMY_DELAY(100);
		MGPIO_vWritePort(LCD_PORT,LCD_PIN_D4,_4_BITS,(Copy_u8Command&0x0F));
		MGPIO_vWritePin(LCD_PORT, LCD_PIN_EN, OUT_HIGH);
		DUMMY_DELAY(20);
		MGPIO_vWritePin(LCD_PORT, LCD_PIN_EN, OUT_LOW);
		DUMMY_DELAY(100);
	#endif
}

/***********************************************************************************/
/* Function Name  : HLCD_vSendCharacter                                            */
/* Function Info  : Sends a character to LCD 					                   */
/* Function Input : LCD Character												   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vSendCharacter(u8 Copy_u8Character){
		MGPIO_vWritePin(LCD_PORT, LCD_PIN_RS, OUT_HIGH);
		#if LCD_MODE == _8_DATA_MODE
			MGPIO_vWritePort(LCD_PORT,LCD_PIN_D0,_8_BITS,Copy_u8Character);
			MGPIO_vWritePin(LCD_PORT, LCD_PIN_EN, OUT_HIGH);
			DUMMY_DELAY(20);
			MGPIO_vWritePin(LCD_PORT, LCD_PIN_EN, OUT_LOW);
			DUMMY_DELAY(100);
		#else
			MGPIO_vWritePort(LCD_PORT,LCD_PIN_D4,_4_BITS,((Copy_u8Character>>4)&0x0F));
			MGPIO_vWritePin(LCD_PORT, LCD_PIN_EN, OUT_HIGH);
			DUMMY_DELAY(20);
			MGPIO_vWritePin(LCD_PORT, LCD_PIN_EN, OUT_LOW);
			DUMMY_DELAY(100);
			MGPIO_vWritePort(LCD_PORT,LCD_PIN_D4,_4_BITS,(Copy_u8Character&0x0F));
			MGPIO_vWritePin(LCD_PORT, LCD_PIN_EN, OUT_HIGH);
			DUMMY_DELAY(20);
			MGPIO_vWritePin(LCD_PORT, LCD_PIN_EN, OUT_LOW);
			DUMMY_DELAY(100);
		#endif
}

/***********************************************************************************/
/* Function Name  : HLCD_vDisplayString                                            */
/* Function Info  : Sends a string to LCD 		    			                   */
/* Function Input : String														   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vDisplayString(u8 *str)
{
	u8 i = 0;
	while(str[i] != '\0')
	{
		HLCD_vSendCharacter(str[i]);
		i++;
	}
}

/***********************************************************************************/
/* Function Name  : HLCD_vCLR		                                               */
/* Function Info  : Clears LCD Display   		    			                   */
/* Function Input : None												   		   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vCLR(void)
{
	HLCD_vSendCommand(0x01);
}


/***********************************************************************************/
/* Function Name  : HLCD_vWriteInt	                                               */
/* Function Info  : Sends a integer to LCD 		    			                   */
/* Function Input : integer 													   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vWriteInt(u32 num)
{
	u32 rem = 0;
	u8 arr [16];
	s8 i = 0;
	while(num != 0)
	{
		rem = num % 10;
		arr[i] = rem + 48;
		i++;
		num = num / 10;
	}
	i--;
	while(i > -1)
	{
		HLCD_vSendCharacter(arr[i]);
		i--;
	}
}

/***********************************************************************************/
/* Function Name  : HLCD_GoTo		                                               */
/* Function Info  : Sets LCD location	 		    			                   */
/* Function Input : position in row and column 									   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vGoTo(u8 row,u8 col)
{
	u8 Loc[2] = {0x80 , 0xC0};
	HLCD_vSendCommand(Loc[row]+col);
}
