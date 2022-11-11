#include <stm32f10x.h>
#include <stm32f10x_exti.h>

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

void extiConfig(){
	EXTI_InitTypeDef EXTIInitstructure;
	NVIC_InitTypeDef NVICInitstructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource6);
	
	//interrupt
	EXTIInitstructure.EXTI_Line=EXTI_Line6;
	EXTIInitstructure.EXTI_LineCmd=ENABLE;
	EXTIInitstructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTIInitstructure.EXTI_Trigger=EXTI_Trigger_Rising;
	
	EXTI_Init(&EXTIInitstructure);
	
	
	//nvic
	NVICInitstructure.NVIC_IRQChannel=EXTI9_5_IRQn;
	NVICInitstructure.NVIC_IRQChannelCmd=ENABLE;
	NVICInitstructure.NVIC_IRQChannelPreemptionPriority=1;
	NVICInitstructure.NVIC_IRQChannelSubPriority=1;

}

void delay(uint32_t timer){
	
	while(timer--);
	
}

uint16_t counter=0;

void EXTI9_5_IRQHandler(){
	
	if(EXTI_GetITStatus(EXTI_Line6)!=RESET){
		counter++;
			
		}
	EXTI_ClearITPendingBit(EXTI_Line6);
	}




int main(){
	
	gpioConfg();
	extiConfig();
	
	while(1){
	
		GPIO_SetBits(GPIOB,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2);
		delay(3600000);
		GPIO_ResetBits(GPIOB,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2);
		delay(3600000);
		
}
}