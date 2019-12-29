#ifndef _ROBOTCTRL_H
#define _ROBOTCTRL_H

#include "stm32f4xx.h"
#include "robot.h"
#include "motor.h"
#include "systick.h"
#include "usart1.h"


void Robotctrl_Init(void);

void Robotctrl_Initialization(void);

void Robotctrl_solve(char* str); //���սⷨ ��ħ��

void Robotctrl_Turnface(void);  //����Ӧ�泯�� �Խ�ͼ ÿ��ת����ɺ���Ҫ

void rcvturn(void);

void Robotctrl_cmd(char cmd, char* str);


#endif

