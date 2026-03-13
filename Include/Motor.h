/***********************************************************************
* @file           Motor.h
* @author         ZhaoYun(ZFSZDZ)
* @date           2024.12.24
* @Version        V1.0.0
* @description    电机运行控制应用模块
***********************************************************************/
#include "../Include/Define.h"
#include "../Include/UserParams.h"

void MotorInit(void);
void MotorApp(void);
static void MotorRunStopControl(void);

tMotor_Type tMotor;

extern tAdc_Type tAdc;
extern tBldc_Type tBldc;
/*******************Copyright (c) ZFSZDZ ******END OF FILE************/
