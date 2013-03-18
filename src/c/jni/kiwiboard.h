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
	GPIO_INPUT = 0,
	GPIO_OUTPUT = 1,
};

enum GPIO_DATA
{
	GPIO_LOW = 0,
	GPIO_HIGH = 1,
};

void GPIO_mode(int gpio_id, int mode);
void GPIO_write(int gpio_id, int data);
int GPIO_read(int gpio_id);
