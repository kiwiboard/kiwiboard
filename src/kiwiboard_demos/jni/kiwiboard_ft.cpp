#include "kiwiboard.h"

#define UART_MAX 4
const char *uartName[UART_MAX] =
{
	"/dev/ttyS1",
	"/dev/ttyS2",
	"/dev/ttyS5",
	"/dev/ttyS6"
};

KiwiBoardSerial uarts[UART_MAX];

void setup()
{
	int pin;
	for(pin=0; pin<GPIO_MAX; pin++)
	{
		pinMode(pin, INPUT);
	}
	
	for(pin=0; pin<UART_MAX; pin++)
	{
		uarts[pin].setPort(uartName[pin]);
		uarts[pin].begin(9600);
	}
	
//	LoopExit = 1;
}

int count = 0;

void loop()		
{

	// char cmd = 'N';  //NULL

	// if(Serial.available())
	// {
		// cmd = (char)Serial.read();
		// printf("CMD = %c(%d) \n", cmd, cmd);
	// }
	// Serial.print("UART ");
	// delay(100);
	// return;

	int pin;
	for(pin=0; pin<GPIO_MAX; pin++)
	{
		printf("GPIO(%d): %d \n", pin+1, digitalRead(pin)); 
	}

	for(pin=0; pin<UART_MAX; pin++)
	{
		uarts[pin].write('2' + pin);
	}

	for(pin=0; pin<UART_MAX; pin++)
	{
		printf("=%s(%d): ", uartName[pin], pin+2);
		while(uarts[pin].available())
		{
			printf("%c", (char)uarts[pin].read());
		}
		printf("\n");
	}

	printf("-- %d\n", ++count);
	delay(1000);
}
