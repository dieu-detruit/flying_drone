#include<wiringPi.h>

#define GPIO_LED		25

int main(void)
{

	if(wiringPiSetupGpio() == -1)return 1;

	pinMode(GPIO_LED, OUTPUT);
	digitalWrite(GPIO_LED, 1);
	delay(1000);
	digitalWrite(GPIO_LED, 0);

	return 0;
}
