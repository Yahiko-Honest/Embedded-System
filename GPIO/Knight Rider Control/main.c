#include <stm32f10x.h>                  // Device header

void gpioConfig(){

	GPIO_InitTypeDef gpioInitstructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	gpioInitstructure.GPIO_Mode=GPIO_Mode_Out_PP;
	gpioInitstructure.GPIO_Pin=GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2;
	gpioInitstructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&gpioInitstructure);
	
	gpioInitstructure.GPIO_Mode=GPIO_Mode_IPD;
	gpioInitstructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_Init(GPIOC,&gpioInitstructure);
}


void delay(uint32_t time)
{
	while(time--);
	
}

uint16_t ButtonState=0;
uint16_t Counter=0;


int main(){

	int ledArray[3]={GPIO_Pin_0,GPIO_Pin_1,GPIO_Pin_2};
	ButtonState = GPIO_ReadInputBit(GPIOC, GPIO_Pin_6);
	
	while(1)
	{
		if(ButtonState == 1){
			for(int i=0;i<3;i++)
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
		else{
			for(int i=0;i<3;i++)
			{
				GPIO_SetBits(GPIOB, ledArray[i]);
				delay(36000000);
				GPIO_ResetBits(GPIOB, ledArray[i]);
			}
			for(int i=3;i>0;i--)
			{
				GPIO_SetBits(GPIOB, ledArray[i]);
				delay(36000000);
				GPIO_ResetBits(GPIOB, ledArray[i]);
			}
		}
		
	}
	
}
