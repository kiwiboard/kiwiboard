#include "kiwiboard.h"
#include "unistd.h"
#include "pthread.h"


int wave_flag = 0;

void servo_move(int port, int interval, int count) // in us
{
	int i;
	int width_high;
	
	for(i=0; i<count; i++)
	{
		GPIO_write(GPIO9, GPIO_HIGH); 
		usleep(interval);
		GPIO_write(GPIO9, GPIO_LOW); 
		usleep(20000 - interval);
	}
}

void servo_wave()
{
	while(1)
	{
		if(wave_flag)
		{
			servo_move(GPIO9, 1200, 20);
			servo_move(GPIO9, 1600, 20);		
		}
		else
		{
			usleep(2000000);	//2sec	
		}
	}
}

void* thread_wave(void *arg)
{
	servo_wave();
	return 0;
}

int main(void)
{
	int i;
	pthread_t thread_id;	
	
	GPIO_mode(GPIO9, GPIO_OUTPUT);

	pthread_create(&thread_id, NULL, thread_wave, NULL);
	wave_flag = 1;

	for(i=0; i<10; i++)
		usleep(1000000);
		
	wave_flag = 0;

	return 0;
}
