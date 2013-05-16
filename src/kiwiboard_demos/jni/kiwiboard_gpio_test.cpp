#include "kiwiboard.h"

void setup()
{
	int pin;
	for(pin=0; pin<GPIO_MAX; pin++)
	{
		pinMode(pin, OUTPUT);
	}
}

void loop()		
{
	int pin;
	for(pin=0; pin<GPIO_MAX; pin++)
	{
		digitalWrite(pin, HIGH); 
	}
	delay(1000);
	for(pin=0; pin<GPIO_MAX; pin++)
	{
		digitalWrite(pin, LOW); 
	}		
	delay(1000);
}
