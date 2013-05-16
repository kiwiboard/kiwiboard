#ifndef __KIWIBOARD_H__
#define __KIWIBOARD_H__
#define KIWIBOARD

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "android/log.h"

#define LOG_TAG "KiwiBoard" //
#undef LOG
#include <android/log.h>   //
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)  

enum GPIO
{
	GPIO1 = 0,
	GPIO2 = 1,
	GPIO3 = 2,
	GPIO4 = 3,
	GPIO5 = 4,
	GPIO6 = 5,
	GPIO7 = 6,
	GPIO8 = 7,	
	GPIO9 = 8,
	GPIO10 = 9,	
	GPIO_MAX = 10,
};

enum GPIO_MODE
{
	INPUT = 0,
	OUTPUT = 1,
	INPUT_PULLUP = 2,
};

enum GPIO_DATA
{
	LOW = 0,
	HIGH = 1,
};

#define UART_BUFFER_SIZE   1024
class KiwiBoardSerial
{
private:
	unsigned char buffer[UART_BUFFER_SIZE];
	int buffer_head, buffer_tail;
	
	int fd;
	
	char portName[16];
	bool setupPort(int baud);
public:
	KiwiBoardSerial();
	void run();	
	int available();
	void begin(int speed);
	void end();
	void find();
	void findUntil();
	void flush();
	void parseFloat();
	void parseInt();
	void peek();
	void print(const char *value);
	void print(int value);
	void println(const char *value);
	void println(int value);
	unsigned char read();
	void readBytes();
	void readBytesUntil();
	void setTimeout();
	void write(char ch);
	void serialEvent();
	
	//extension by KiwiBoard to change
	void setPort(const char *tty);
};



#define TCNT0  AVR_TCNT0()
unsigned long AVR_TCNT0();
unsigned long clockCyclesPerMicrosecond();

void pinMode(int pin, int mode);
void digitalWrite(int pin, int value);
int digitalRead(int pin);


void delay(unsigned long ms);
void delayMicroseconds(unsigned long us);
unsigned long micros();
unsigned long millis();

extern KiwiBoardSerial Serial;
extern int LoopExit;

#endif