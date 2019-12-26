#include "robot.h"

//��ɴӶ��ת����ħ��������Ӱ��  
//��������������
//catch  ������ץסħ��
//back   �ſ�ħ��
//turn   ��תħ���Ķ�Ӧ��


void Robot_Init()
{
	Motor_Initialization();
}

void Robot_Initialization()
{
	Robot_Init();
}




void Robot_Lcatch()
{
	Motor_L2_Turn(L2_JD_0);
}

void Robot_Fcatch()
{
	Motor_F2_Turn(F2_JD_0);
}

void Robot_Rcatch()
{
	Motor_R2_Turn(R2_JD_0);
}

void Robot_Bcatch()
{
	Motor_B2_Turn(B2_JD_0);
}




void Robot_Lback()
{
	Motor_L2_Turn(L2_JD_90);
}

void Robot_Fback()
{
	Motor_F2_Turn(F2_JD_90);
}

void Robot_Rback()
{
	Motor_R2_Turn(R2_JD_90);
}

void Robot_Bback()
{
	Motor_B2_Turn(B2_JD_90);
}



void Robot_Lturn(u8 turn)
{
	if(turn==T)
	{
		Motor_L1_Turn(L1_JD_180);
		Delay_Ms(dlytime);
		
	}
	else if (turn==T_)
	{
		Motor_L1_Turn(L1_JD_0);
		Delay_Ms(dlytime);
		
	}
	else if(turn==T2)
	{
		Robot_Lback();
		Delay_Ms(dlytime);
		Motor_L1_Turn(L1_JD_0);
		Delay_Ms(dlytime);
		Robot_Lcatch();
		Motor_L1_Turn(L1_JD_180);
	}	
	
	
	//�����ת��ĸ�λ
		Robot_Lback();
		Delay_Ms(dlytime);
		Motor_L1_Turn(L1_JD_90);
		Robot_Lcatch();
}

void Robot_Fturn(u8 turn)
{
		if(turn==T)
	{
		Motor_F1_Turn(F1_JD_180);
		Delay_Ms(dlytime);
		
	}
	else if (turn==T_)
	{
		Motor_F1_Turn(F1_JD_0);
		Delay_Ms(dlytime);
	}
	else if(turn==T2)
	{
		Robot_Fback();
		Delay_Ms(dlytime);
		Motor_F1_Turn(F1_JD_0);
		Delay_Ms(dlytime);
		Robot_Fcatch();
		Motor_F1_Turn(F1_JD_180);
	}	
	
	//��ת��ĸ�λ		
		Robot_Fback();
		Delay_Ms(dlytime);
		Motor_F1_Turn(F1_JD_90);
		Robot_Fcatch();
}

void Robot_Rturn(u8 turn)
{
		if(turn==T)
	{
		Motor_R1_Turn(R1_JD_180);
		Delay_Ms(dlytime);
	}
	else if (turn==T_)
	{
		Motor_R1_Turn(R1_JD_0);
		Delay_Ms(dlytime);
	}
	else if(turn==T2)
	{
		Robot_Rback();
		Delay_Ms(dlytime);
		Motor_R1_Turn(R1_JD_0);
		Delay_Ms(dlytime);
		Robot_Rcatch();
		Motor_R1_Turn(R1_JD_180);
	}	
	
	
	//��ת��ĸ�λ
		Robot_Rback();
		Delay_Ms(dlytime);
		Motor_R1_Turn(R1_JD_90);
		Robot_Rcatch();
}

void Robot_Bturn(u8 turn)
{
		if(turn==T)
	{
		Motor_B1_Turn(B1_JD_180);
		Delay_Ms(dlytime);
	}
	else if (turn==T_)
	{
		Motor_B1_Turn(B1_JD_0);
		Delay_Ms(dlytime);
	}
	else if(turn==T2)
	{
		Robot_Bback();
		Delay_Ms(dlytime);
		Motor_B1_Turn(B1_JD_0);
		Delay_Ms(dlytime);
		Robot_Bcatch();
		Motor_B1_Turn(B1_JD_180);
	}		
	
	
	//��ת��ĸ�λ
		Robot_Bback();
		Delay_Ms(dlytime);
		Motor_B1_Turn(B1_JD_90);
		Robot_Bcatch();
}

void Robot_getUDface()  //��̬���� ��U D�� ����BF ��
{
	Robot_Bback();
	Robot_Fback();
	Delay_Ms(dlytime);
	Motor_L1_Turn(L1_JD_180);
	Motor_R1_Turn(R1_JD_180);
	Delay_Ms(dlytime);
	Robot_Bcatch();
	Robot_Fcatch();
	
	Robot_Lback();
	Robot_Rback();
  Delay_Ms(dlytime);
	Motor_L1_Turn(L1_JD_90);
	Motor_R1_Turn(L1_JD_90);
	Delay_Ms(dlytime);
	Robot_Lcatch();
	Robot_Rcatch();
}

void  Robot_reUDface()  //��̬����   ��ԭ U D ��
{
	Robot_Bback();
	Robot_Fback();
	Delay_Ms(dlytime);
	Motor_L1_Turn(L1_JD_0);
	Motor_R1_Turn(R1_JD_0);
	Delay_Ms(dlytime);
	Robot_Bcatch();
	Robot_Fcatch();
	
	Robot_Lback();
	Robot_Rback();
  Delay_Ms(dlytime);
	Motor_L1_Turn(L1_JD_90);
	Motor_R1_Turn(L1_JD_90);
	Delay_Ms(dlytime);
	Robot_Lcatch();
	Robot_Rcatch();
	
}

void Robot_Uturn(u8 turn)
{

	Robot_getUDface();

	Robot_Fturn(turn);  //��U��ת��F��  ����F����תU��
	
	Robot_reUDface();
	
}

void Robot_Dturn(u8 turn)  //��
{
	
	Robot_getUDface();
	
	Robot_Bturn(turn); //��D����ת��B���  ����B����תD��
	
	Robot_reUDface();
	
	
}
	








