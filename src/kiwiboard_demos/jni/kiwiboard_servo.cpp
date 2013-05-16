#include "kiwiboard.h"

#define PIN   GPIO4

void setup()
{
	pinMode(PIN, OUTPUT);
}

void logTime()
{
	static long last;
	
	struct  timeval    tv;
	struct  timezone   tz;
	gettimeofday(&tv,&tz);

	printf("Period: %ld\n",tv.tv_usec - last);
	last = tv.tv_usec;		
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
			logTime();
			digitalWrite(PIN, HIGH); 
			delayMicroseconds(a1);
			digitalWrite(PIN, LOW); 
			delayMicroseconds(20000-a1);
		}
		delay(200);
		for(m=0; m<10; m++)
		{
			digitalWrite(PIN, HIGH); 
			delayMicroseconds(a2);
			digitalWrite(PIN, LOW); 
			delayMicroseconds(20000-a2);
		}
		delay(200);		
	}	
}
