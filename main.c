#include "main.h"
#include "Delay.h"

sbit DEN_DO = P0^0;
sbit DEN_VANG = P0^1;
sbit DEN_XANH = P0^2;
#define LED_CHUC P2
#define LED_DV P3

unsigned char code segments7Led[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void main()
{
	signed char i;
	while(1)
	{
		//den do
		DEN_DO = 0;
		DEN_VANG = 1;
		DEN_XANH = 1;
		for(i=20;i>=0;i--)
		{
			LED_CHUC = segments7Led[i/10];
			LED_DV = segments7Led[i%10];
			Delay_ms(1000);
		}
		//den xanh
		DEN_DO = 1;
		DEN_VANG = 1;
		DEN_XANH = 0;
		for(i=15;i>=0;i--)
		{
			LED_CHUC = segments7Led[i/10];
			LED_DV = segments7Led[i%10];
			Delay_ms(1000);
		}
		//den vang
		DEN_DO = 1;
		DEN_VANG = 0;
		DEN_XANH = 1;
		for(i=5;i>=0;i--)
		{
			LED_CHUC = segments7Led[i/10];
			LED_DV = segments7Led[i%10];
			Delay_ms(1000);
		}
	}
}