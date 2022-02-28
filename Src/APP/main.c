#include "RCC_interface.h"
#include "SSD_interface.h"

int main(){
	MRCC_vEnablePeripheralClk(AHB1_BUS,GPIOAEN);
	HSSD_vInit();

	u8 num=0;
	volatile int i=0;
	while(1){
		if(num>9) num=0;
		 HSSD_vDisplayNum(num);
		 for(i=0;i<1000000;i++){};
		 num++;
	}
	return 0;
}
