#include <stm32f10x.h>


void gpioConfig(){
	
	GPIO_InitTypeDef gpioInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//Led için yapilan clck ayarlari
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE); //Buton için yapilan clock ayarlari
	
	
	//Led ayarlari
	gpioInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	gpioInitStructure.GPIO_Pin=GPIO_Pin_0;
	gpioInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpioInitStructure);
	
	//Buton ayarlari
	gpioInitStructure.GPIO_Mode=GPIO_Mode_IPD;
	gpioInitStructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_Init(GPIOC, &gpioInitStructure);
	
}

uint16_t button_state = 0;
uint16_t counter = 0;

void delay(uint16_t timer){
	
	while(timer--);
	
}


int main(){

	gpioConfig();
	button_state = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6);
	
while(1){
	
	//Led yakmak için
//	if(button_state == 1){
//		GPIO_SetBits(GPIOB, GPIO_Pin_0);
//	}
//	else GPIO_ResetBits(GPIOB, GPIO_Pin_0);
//	}

	
	
	//button count
	if(button_state==1){
		counter++;
		delay(3600000);
	}
	
}

