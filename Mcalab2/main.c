#include"led.h"

int main()
{ PINSEL0|=0xF0F0;
	IODIR0|=(0XF<<16); 
	VICIntEnable = (3<<14);
	VICVectAddr0 = (unsigned int)upcount; // address of the ISR
  VICVectCntl0 = (1<<5)| 14; 
	VICVectAddr1 = (unsigned int)downcount; // address of the ISR
  VICVectCntl1 = (1<<5)| 15;   
	while(1);
	return 0;
}
