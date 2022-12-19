#include<lpc214x.h>

void delay(int ms)
{ for(int j=0;j<ms;j++)
	for(int i=0;i<50000;i++);
}

void ledWrite(int a)
{ if(a<16)
		{ IOSET0=a<<16;
			delay(20);
			IOCLR0=a<<16;
		}
	else 
	return;
}

__irq void upcount()
{ for(int i=0;i<16;i++)
		ledWrite(i);
	EXTINT|= 0x3;        
 VICVectAddr = 0; 
}

__irq void downcount()
{ for(int i=15;i>=0;i--)
		ledWrite(i);
	EXTINT|= 0x3;        
	VICVectAddr = 0; 
}
