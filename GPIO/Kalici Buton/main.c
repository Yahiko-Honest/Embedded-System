#include <stm32f10x.h>                  // Device header
//Bunun üzerine biraz çalis adam mal!!
void gpioConfg(){

	GPIO_InitTypeDef gpioInitstructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	//Led
	gpioInitstructure.GPIO_Mode=GPIO_Mode_AF_PP;
	gpioInitstructure.GPIO_Pin=GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2;
	gpioInitstructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&gpioInitstructure);
	
	//Button
	gpioInitstructure.GPIO_Mode=GPIO_Mode_IPD;
	gpioInitstructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_Init(GPIOC,&gpioInitstructure);
	
}

void delay(uint16_t time){while(time--);}


uint16_t ButtonState=0;
uint16_t flag=0;


int main(){

	gpioConfig();
	ButtonState=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6);
	
	while(1){
	if(ButtonState==1){
		if(flag==0){
			flag++;
			GPIO_SetBits(GPIOB,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2);
		}
		else{flag=0;GPIO_ResetBits(GPIOB,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2);}
		
		delay(7200000);
		
	}
	}
}
