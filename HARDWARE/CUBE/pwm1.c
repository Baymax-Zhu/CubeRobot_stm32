#include "pwm1.h"

void PWM1_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	PWM1_GPIO_CLK_Cmd(PWM1_GPIO_CLK, ENABLE);
	
	GPIO_PinAFConfig(PWM1_GPIO, PWM1_GPIOSource, PWM1_GPIO_AF);
	
	GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Pin =   PWM1_GPIO_Pin;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;
	GPIO_InitStructure.GPIO_PuPd =  GPIO_PuPd_UP;
	
	GPIO_Init(PWM1_GPIO, &GPIO_InitStructure);	
}

void PWM1_TIM_Init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	PWM1_TIM_CLK_Cmd(PWM1_TIM_CLK, ENABLE);
	
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 19999;  
	TIM_TimeBaseInitStructure.TIM_Prescaler = 83;// ��AHB1�ķ�Ƶϵ����Ϊ1ʱ  ͨ�ö�ʱ��ʱ����AHB1����ʱ�ӵ�2�� AHB1=42M  ��ʱ��Ϊ84M ����Ԥ��Ƶϵ��Ϊ
																									//���÷�Ƶϵ��Ϊ  ���� 0.0002
	
	TIM_TimeBaseInit(PWM1_TIM, &TIM_TimeBaseInitStructure);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 500;
	
	TIM_OC1Init(PWM1_TIM, &TIM_OCInitStructure);
	
	TIM_OC1PreloadConfig(PWM1_TIM, TIM_OCPreload_Enable);
	
	TIM_ARRPreloadConfig(PWM1_TIM, ENABLE);
	
//	TIM_Cmd(PWM1_TIM, ENABLE);	
	
//	TIM_CtrlPWMOutputs(PWM1_TIM, ENABLE);
}


void PWM1_Ctrl(u8 flag)
{
	if(flag)
	{
		TIM_Cmd(PWM1_TIM,ENABLE);
	}
	else
	{
		TIM_Cmd(PWM1_TIM,DISABLE);
	}
}



void PWM1_Initialization(void)
{
	PWM1_GPIO_Init();
	PWM1_TIM_Init();
}

void PWM1_SetScale(uint16_t scale)
{
	TIM_SetCompare1(PWM1_TIM, scale);
}

