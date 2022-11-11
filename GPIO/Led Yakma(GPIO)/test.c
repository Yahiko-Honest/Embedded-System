#include <stm32f10x.h>

//void gpioConfig(void);
void gpioConfig(){
	
	GPIO_InitTypeDef GPIOInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIOInitStructure);
}

void delay(uint32_t time){
	
	while(time--);
	
}

int main()
{
	gpioConfig();
	while(1){
//		GPIO_SetBits(GPIOB,GPIO_Pin_0);													//Led yakma yöntem 1
//		delay(360000);
//		GPIO_ResetBits(GPIOB,GPIO_Pin_0);
//		delay(360000);
		GPIO_WriteBit(GPIOB,GPIO_Pin_0,Bit_SET);									//Led yakma yöntem 2
		delay(360000);
		GPIO_WriteBit(GPIOB,GPIO_Pin_0,Bit_RESET);
		delay(360000);
		
	}
}
