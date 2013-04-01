#include "kiwiboard.h"


void setup()
{
	pinMode(GPIO5, OUTPUT);
}

// return:
// 0: stop
// !0: loop
int loop()		
{
	int i, m;
	int a1 = 1000;
	int a2 = 2000;
	
	for(i=0; i<30; i++)
	{
		for(m=0; m<10; m++)
		{
			digitalWrite(GPIO5, HIGH); 
			delayMicroseconds(a1);
			digitalWrite(GPIO5, LOW); 
			delayMicroseconds(20000-a1);
		}
		delay(200);
		for(m=0; m<10; m++)
		{
			digitalWrite(GPIO5, HIGH); 
			delayMicroseconds(a2);
			digitalWrite(GPIO5, LOW); 
			delayMicroseconds(20000-a2);
		}
		delay(200);		
	}	
	
	return 0;
}
