#include "kiwiboard.h"

void setup()
{
	pinMode(GPIO10, OUTPUT);
}

void loop()		
{
	digitalWrite(GPIO10, HIGH); 
	delay(1000);
	digitalWrite(GPIO10, LOW); 
	delay(1000);
}
