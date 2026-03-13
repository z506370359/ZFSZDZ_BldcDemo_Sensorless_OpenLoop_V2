/***********************************************************************
* @file           Adc.c
* @author         ZhaoYun(ZFSZDZ)
* @date           2024.12.24
* @Version        V1.0.0
* @description    模拟量采集处理模块
***********************************************************************/
#include "../Include/Adc.h"

/***********************************************************************
* 函数名称  : AdcSample
* 功能描述  ：获取ADC转换完成数据
* 形参      ：无
* 返回值    ：无
* 要点备注  ：DMA搬运完数据，读取DMA结构体中的数据
***********************************************************************/
void AdcSample(void)
{
    tAdc.An0.ValueInstant = tDMA.ADDATA0; //UA/UB/UC 端电压采样转换值
    tAdc.An3.ValueInstant = tDMA.ADDATA1; //VBUS 采样转换值
    tAdc.An4.ValueInstant = tDMA.ADDATA2; //IBUS 采样转换值
    tAdc.An5.ValueInstant = tDMA.ADDATA3; //POT 旋钮采样转换值
    tAdc.An9.ValueInstant = tDMA.ADDATA4; //NTC 采样转换值
    
    tAdc.TerminalVoltage = tAdc.An0.ValueInstant;
    tAdc.Vbus = tAdc.An3.ValueInstant;
}
/***********************************************************************
* 函数名称  : AdcFilter
* 功能描述  ：ADC转换结果平均值滤波处理
* 形参      ：无
* 返回值    ：无
* 要点备注  ：无
***********************************************************************/
void AdcFilter(void)
{
    //VBUS 平均值滤波处理
    tAdc.An3.Sum += tAdc.An3.ValueInstant;
    tAdc.An3.Num ++;
    if(tAdc.An3.Num >= 128)
    {
        tAdc.An3.ValueAverage = (unsigned short)(tAdc.An3.Sum >> 7);
        tAdc.An3.Num = 0;
        tAdc.An3.Sum = 0;
    }
    //IBUS 平均值滤波处理
    tAdc.An4.Sum += tAdc.An4.ValueInstant;
    tAdc.An4.Num ++;
    if(tAdc.An4.Num >= 128)
    {
        tAdc.An4.ValueAverage = (unsigned short)(tAdc.An4.Sum >> 7);
        tAdc.An4.Num = 0;
        tAdc.An4.Sum = 0;
    }
    //POT 平均值滤波处理
    tAdc.An5.Sum += tAdc.An5.ValueInstant;
    tAdc.An5.Num ++;
    if(tAdc.An5.Num >= 128)
    {
        tAdc.An5.ValueAverage = (unsigned short)(tAdc.An5.Sum >> 7);
        tAdc.An5.Num = 0;
        tAdc.An5.Sum = 0;
    }
    //NTC 平均值滤波处理
    tAdc.An9.Sum += tAdc.An9.ValueInstant;
    tAdc.An9.Num ++;
    if(tAdc.An9.Num >= 128)
    {
        tAdc.An9.ValueAverage = (unsigned short)(tAdc.An9.Sum >> 7);
        tAdc.An9.Num = 0;
        tAdc.An9.Sum = 0;
    }
}
/***********************************************************************
* 函数名称  : AdcSetSpeed
* 功能描述  ：根据旋钮转换值处理为占空比调节范围值
* 形参      ：无
* 返回值    ：无
* 要点备注  ：0~4095 处理为 0~2000
***********************************************************************/
static void AdcSetSpeed(void)
{
    unsigned short Temp;
    
    Temp = tAdc.An5.ValueAverage >> 1;
    if(Temp > 2000)
        Temp = 2000;
    tAdc.SetDuty = Temp;
}
/***********************************************************************
* 函数名称  : AdcApp
* 功能描述  ：ADC模块应用程序
* 形参      ：无
* 返回值    ：无
* 要点备注  ：无
***********************************************************************/
void AdcApp(void)
{
    AdcSetSpeed();
}
/*******************Copyright (c) ZFSZDZ ******END OF FILE************/
