#include <stm32f10x.h>                  // Device header

void gpioConfig(){

	GPIO_InitTypeDef gpioInitstructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	gpioInitstructure.GPIO_Mode=GPIO_Mode_Out_PP;
	gpioInitstructure.GPIO_Pin=GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2;
	gpioInitstructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&gpioInitstructure);
}


void delay(uint32_t time)
{
	while(time--);
	
}

int main(){

	int ledArray[3]={GPIO_Pin_0,GPIO_Pin_1,GPIO_Pin_2};
	while(1)
	{
		/*GPIO_SetBits(GPIOB, GPIO_Pin_0);
		delay(3600000);
		GPIO_ResetBits(GPIOB, GPIO_Pin_0);
		delay(3600000);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_1);
		delay(3600000);
		GPIO_ResetBits(GPIOB, GPIO_Pin_1);
		delay(3600000);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_2);
		delay(3600000);
		GPIO_ResetBits(GPIOB, GPIO_Pin_2);
		delay(3600000);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_1);
		delay(3600000);
		GPIO_ResetBits(GPIOB, GPIO_Pin_1);
		delay(3600000);*/
		
		for(int i=0;i<3;i++)//Daha kisa hali
		{
			GPIO_SetBits(GPIOB, ledArray[i]);
			delay(3600000);
			GPIO_ResetBits(GPIOB, ledArray[i]);
		}
		for(int i=3;i>0;i--)
		{
			GPIO_SetBits(GPIOB, ledArray[i]);
			delay(3600000);
			GPIO_ResetBits(GPIOB, ledArray[i]);
		}
	}
	
}
