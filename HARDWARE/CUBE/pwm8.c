#include "pwm8.h"

void PWM8_GPIO_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	PWM8_GPIO_CLK_Cmd(PWM8_GPIO_CLK, ENABLE);
	
	GPIO_PinAFConfig(PWM8_GPIO, PWM8_GPIOSource, PWM8_GPIO_AF);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Pin = PWM8_GPIO_Pin;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	
	GPIO_Init(PWM8_GPIO, &GPIO_InitStructure);	
	
}


void PWM8_TIM_Init()
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	PWM8_TIM_CLK_Cmd(PWM8_TIM_CLK, ENABLE);
	
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 19999;  //一个pwm的宽度为 0.00002*1000 =0.02=20ms
	TIM_TimeBaseInitStructure.TIM_Prescaler = 83;// 当AHB1的分频系数不为1时  通用定时器时钟是AHB1总线时钟的2倍 AHB1=42M  则定时器为84M 设置预分频系数为
																									//设置分频系数为959  产生 0.0002
	TIM_TimeBaseInit(PWM8_TIM, &TIM_TimeBaseInitStructure);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 500;
	
	TIM_OC2Init(PWM8_TIM,&TIM_OCInitStructure);
	
	TIM_OC2PreloadConfig(PWM8_TIM,TIM_OCPreload_Enable);
	
	TIM_ARRPreloadConfig(PWM8_TIM,ENABLE);
	
//	TIM_Cmd(PWM8_TIM,ENABLE);

//	TIM_CtrlPWMOutputs(PWM1_TIM, ENABLE);
}

void PWM8_Ctrl(u8 flag)
{
	if(flag)
	{
		TIM_Cmd(PWM8_TIM,ENABLE);
	}
	else
	{
		TIM_Cmd(PWM8_TIM,DISABLE);
	}
}


void PWM8_Initialization(void)
{
	PWM8_GPIO_Init();
	PWM8_TIM_Init();
}

void PWM8_SetScale(uint16_t scale)
{
	TIM_SetCompare2(PWM8_TIM, scale);
}




