/***********************************************************************
* @file           Adc.h
* @author         ZhaoYun(ZFSZDZ)
* @date           2024.12.24
* @Version        V1.0.0
* @description    模拟量采集处理模块
***********************************************************************/
#include "../Include/Define.h"

void AdcApp(void);
void AdcSample(void);
void AdcFilter(void);

static void AdcSetSpeed(void);

tAdc_Type tAdc;
extern tDMA_Type tDMA;

/*******************Copyright (c) ZFSZDZ ******END OF FILE************/
