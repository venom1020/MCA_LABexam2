#include"uart.h"
int main()
{	int temp=0; 
	pllinit();
	uartinit();
	IODIR0|=0XF<<16;
	while(1)
	{ rec=rec_char();
		if(rec=='A' || rec=='a')
			clockwise();
		else
			anticlockwise();
	}
	return 0;
}
