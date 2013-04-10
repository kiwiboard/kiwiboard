#include "kiwiboard.h"


void setup()
{
	LoopExit = 1;   //diffrent from Arduino. Set LoopExit = 1, the loop() will run once only
	pinMode(GPIO5, OUTPUT);
}


void loop()		
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
}
