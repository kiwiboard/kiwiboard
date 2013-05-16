#include "kiwiboard.h"

#define LEFT	GPIO4
#define RIGHT	GPIO5



void logTime()
{
	static long last;
	
	struct  timeval    tv;
	struct  timezone   tz;
	gettimeofday(&tv,&tz);

	printf("Period: %ld\n",tv.tv_usec - last);
	last = tv.tv_usec;		
}

void servoAngle(int pin, int angle)
{
	int m;
	int a1 = angle;
	for(m=0; m<10; m++)
	{
		digitalWrite(pin, HIGH); 
		delayMicroseconds(a1);
		digitalWrite(pin, LOW); 
		delayMicroseconds(19500-a1);
	}
}

void setup()
{
	pinMode(LEFT, OUTPUT);
	pinMode(RIGHT, OUTPUT);	
	servoAngle(LEFT, 1000);
	servoAngle(RIGHT, 1000);	
	
	Serial.begin(9600);
}

void loop()		
{
	char cmd = 'N';  //NULL

	if(Serial.available())
	{
		cmd = (char)Serial.read();
		printf("CMD = %c(%d) \n", cmd, cmd);
	}
	switch(cmd)
	{
	case 'L':
		servoAngle(LEFT, 2000);
		break;
	case 'R':
		servoAngle(RIGHT, 2000);
		break;
	case 'D':
		servoAngle(LEFT, 1000);
		servoAngle(RIGHT, 1000);
		break;
	default:
		break;			
	}

	delay(200);
}
