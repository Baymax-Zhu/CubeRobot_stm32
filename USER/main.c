#include "stm32f4xx.h"
#include "systick.h"
#include "usart1.h"
//#include "motor.h"
#include "pwm1.h"
#include "robot.h"

#define a 40

//��������� ������Ϣ�Ľ��պͷ��� 
//�������յ�����Ϣ  ����Ӧ�� �������� ����Robot

int main(void)
{
	SysTick_Initialization();  //ϵͳ��ʱ�� ��ʼ��
 	Usart1_Initialization();   //����1��ʼ��
	
	
	while(1)
	{
		
		
	}
}
