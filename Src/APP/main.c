#include "RCC_interface.h"
#include "GPIO_interface.h"
int main(){
	MRCC_vEnablePeripheralClk(AHB1_BUS,GPIOAEN);
	MGPIO_vSetMode(GPIOA, PIN9, OUTPUT_MODE);
	MGPIO_vSetOutputType(GPIOA, PIN9, OUT_PUSH_PULL);
	MGPIO_vSetOutputSpeed(GPIOA, PIN9, OUT_HI_SP);
	MGPIO_vWritePin(GPIOA, PIN9, OUT_HIGH);
	while(1){

	}
	return 0;
}
