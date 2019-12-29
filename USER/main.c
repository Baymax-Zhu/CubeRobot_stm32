#include "stm32f4xx.h"
#include "systick.h"
#include "usart1.h"
//#include "motor.h"
#include "robotctrl.h"
//#include "robot.h"

/**********************
//������
int main()
{
	char sendstr[]="yes";
	
	Usart1_Initialization();
	SysTick_Initialization();
	LED_Initialization();
	
	while(1)
	{
		Delay_Ms(4000);
		
		Usart1_SendString(sendstr);
		LED_On();
		Delay_Ms(1000);
		LED_Off();
		
	}
	
}
******************************/
//������

//int main(void)
//{
//	SysTick_Initialization();
//	Robot_Initialization();
//	Robot_Bcatch();
//	Robot_Fcatch();
//	
//	u8 str[]="XrdJBDIXrJdJuZYHDIU";
//	
//	Robotctrl_solve(str);
//	
//	while(1);
//}



/****************************************/
//��������� ������Ϣ�Ľ��պͷ��� 
//�������յ�����Ϣ  ����Ӧ�� �������� ����Robot

//USART1_RX_STA ����״̬�� ǰ14Ϊ���ݳ���
//bit15 Ϊ������ɱ�־λ 
void getmsg(u16 len,char *str);

int main(void)
{
	SysTick_Initialization();  //ϵͳ��ʱ�� ��ʼ��
 	Usart1_Initialization();   //����1��ʼ��
	Robotctrl_Initialization();
	 
	
	u16 msgLen=0;
	char rxbuf[50]={0};  //���峤��Ϊ50���ջ�����
	char cmd=0;
	
	while(1)
	{
		if(USART1_RX_STA & 0x8000 )  //���յ���Ϣ
		{
			msgLen= USART1_RX_STA & 0x3fff;  //ȡ�����ݳ���
			cmd=USART1_RX_BUF[0];
			msgLen=msgLen-2;
			getmsg(msgLen,rxbuf);
			
			Robotctrl_cmd(cmd,rxbuf);  // �������� ���� ����s
			
			USART1_RX_STA=0;
		}
	}
}

void getmsg(u16 len,char * str)
{
	int i;
	for(i=0;i<len;i++)
	{
		*str=USART1_RX_BUF[i+2];
		str++;
	}
	*str='\0';
}


