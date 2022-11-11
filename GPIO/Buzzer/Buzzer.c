#include <stm32f10x.h>


void gpioConfig(){

	GPIO_InitTypeDef gpioInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	gpioInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	gpioInitStructure.GPIO_Pin=GPIO_Pin_0;
	gpioInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&gpioInitStructure);
}

int main(){
	gpioConfig();
	
	while(1){
		GPIO_SetBits(GPIOB, GPIO_Pin_0);
		for(int i=0;i<360000;i++);
		GPIO_ResetBits(GPIOB, GPIO_Pin_0);
		GPIO_SetBits(GPIOB, GPIO_Pin_0);
		for(int i=0;i<7000;i++);
		GPIO_ResetBits(GPIOB, GPIO_Pin_0);
		GPIO_SetBits(GPIOB, GPIO_Pin_0);
		for(int i=0;i<36000000;i++);
		GPIO_ResetBits(GPIOB, GPIO_Pin_0);
	}
}
