#include "robotctrl.h"

//��ɶ�robot�� ����

//���սⷨ��Ϣ  ����robot������Ӧ�Ķ���

char sendstr[]= "yes" ;

void Robotctrl_Init()
{
	Robot_Init();
}

void Robotctrl_Initialization(void)
{
	Robotctrl_Init();
	Usart1_Initialization();
	SysTick_Initialization();
}

void Robotctrl_solve(char* str)	//���սⷨ ��ħ��
{
	char* step;
	step=str;
	
	while(*step)
	{
		switch(*step)
		{
			case 'H': Robot_Uturn(T2); break;
			case 'u': Robot_Uturn(T_); break;
			case 'U': Robot_Uturn(T);  break;
			
			case 'I': Robot_Rturn(T2); break;
			case 'r': Robot_Rturn(T_); break;
			case 'R': Robot_Rturn(T);  break;
			
			case 'J': Robot_Fturn(T2); break;
			case 'f': Robot_Fturn(T_); break;
			case 'F': Robot_Fturn(T);  break;
			
			case 'X': Robot_Dturn(T2); break;
			case 'd': Robot_Dturn(T_); break;
			case 'D': Robot_Dturn(T);  break;
			
			case 'Y': Robot_Lturn(T2); break;
			case 'l': Robot_Lturn(T_); break;
			case 'L': Robot_Lturn(T);  break;
			
			case 'Z': Robot_Bturn(T2); break;
			case 'b': Robot_Bturn(T_); break;
			case 'B': Robot_Bturn(T);  break;
			default: break;
		}
		
		step++;
	}
}

void Robotctrl_Turnface()  //����Ӧ�泯�� �Խ�ͼ ÿ��ת����ɺ���Ҫ
{
	static u8 count=1;
	if(count==1)  //f��Ӧ����
	{
		count++;
		
		Delay_Ms(dlytime);
		Robot_Bcatch();
		Robot_Fcatch();
		
		Delay_Ms(dlytime);
		
		Robot_Bback();
		Robot_Fback();
		
		Delay_Ms(dlytime);
		
		Motor_L1_Turn(L1_JD_0);
		Motor_R1_Turn(R1_JD_180);
	}
	else if (count==2)//l�泯��
	{
		count++;
		
		Delay_Ms(dlytime);  
		
		Robot_Bcatch();
		Robot_Fcatch();
		
		Delay_Ms(dlytime);
		
		Robot_Lback();
		Robot_Rback();
		
		Delay_Ms(dlytime);
		
		Motor_L1_Turn(L1_JD_90);
		Motor_R1_Turn(R1_JD_90);
		
		Delay_Ms(dlytime);
		
		Motor_B1_Turn(B1_JD_0);
		Motor_F1_Turn(F1_JD_180);
	}
	else if (count==3) //r�泯��
	{
		count++;
		
		Delay_Ms(dlytime);
		
		Motor_B1_Turn(B1_JD_180);
		Motor_F1_Turn(F1_JD_0);		
	}
	else if (count==4)//u�泯��
	{
		count++;
		
		Delay_Ms(dlytime);
		
		Motor_B1_Turn(B1_JD_90);
		Motor_F1_Turn(F1_JD_90);
		
		Delay_Ms(dlytime);
		
		Robot_Lcatch();
		Robot_Rcatch();
		
		Delay_Ms(dlytime);
		
		Robot_Bback();
		Robot_Fback();
		
		Delay_Ms(dlytime);
		
		Motor_L1_Turn(L1_JD_180);
		Motor_R1_Turn(R1_JD_0);
	}
	else if (count==5)//d�泯��
	{
		count++;
		
		Delay_Ms(dlytime);
		Motor_L1_Turn(L1_JD_0);
		Motor_R1_Turn(R1_JD_180);
		
	}
	else if(count==6)//b�泯��
	{
		count=1;
		Delay_Ms(dlytime);
		Motor_L1_Turn(L1_JD_90);
		Motor_R1_Turn(R1_JD_90);
		
		Delay_Ms(dlytime);
		
		Motor_B1_Turn(B1_JD_0);
		Motor_F1_Turn(L1_JD_180);
		
		Delay_Ms(dlytime);
		
		Robot_Bcatch();
		Robot_Fcatch();
		
		Delay_Ms(dlytime);
		
		Robot_Lback();
		Robot_Rback();
		
		Delay_Ms(dlytime);
		
		Motor_B1_Turn(B1_JD_180);
		Motor_F1_Turn(L1_JD_0);
		
	//	rcvturn();    //������  �ǵ�ɾ��
		
	}
}


void rcvturn()
{
	Delay_Ms(dlytime);
	
	Motor_B1_Turn(B1_JD_0);
	Motor_F1_Turn(L1_JD_180);  //F�泯��
	
	Delay_Ms(dlytime);
	
	Robot_Lcatch();
	Robot_Rcatch();
	
	Delay_Ms(dlytime);
	
	Robot_Bback();
	Robot_Fback();
	
	Delay_Ms(dlytime);
	
	Motor_B1_Turn(B1_JD_90);
	Motor_F1_Turn(L1_JD_90); 
	
	Delay_Ms(dlytime);
	
	Motor_L1_Turn(L1_JD_180);
	Motor_R1_Turn(R1_JD_0);
	
	Delay_Ms(dlytime);
	
	Robot_Bcatch();
	Robot_Fcatch();
	
	Delay_Ms(dlytime);
	
		
	Robot_Lback();
	Robot_Rback();
	
	Delay_Ms(dlytime);
	
	Motor_L1_Turn(L1_JD_90);
	Motor_R1_Turn(R1_JD_90);
	
	Delay_Ms(dlytime);
	
	Robot_Lcatch();
	Robot_Rcatch();

		
}


void Robotctrl_cmd(char cmd, char* str)
{
	if(cmd=='C')
	{
		Robotctrl_Turnface();
		
		Delay_Ms(2000);
		Usart1_SendString(sendstr);   
	}
	else if(cmd == 'S')
	{
		rcvturn(); 
		
		Robotctrl_solve(str);
		
		Delay_Ms(1000);
		
		Motor_reset();//��ԭ��ɺ�λ
	}
}








