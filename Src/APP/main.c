#include "RCC_interface.h"
#include "SSD_interface.h"
#include "LCD_interface.h"
int main(){
	MRCC_vEnablePeripheralClk(AHB1_BUS,GPIOAEN);
	HLCD_vInit();

	u8 num=0;
	volatile int i=0;
	HLCD_vDisplayString("Alhussainy");
	for(i=0;i<1000000;i++){};
	while(1){
		HLCD_vCLR();

		 if(num>9) num=0;
		 HLCD_vSendCharacter('0'+num);
		 HSSD_vDisplayNum(num);
		 for(i=0;i<1000000;i++){};
		 num++;
	}
	return 0;
}
