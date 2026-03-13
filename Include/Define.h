/***********************************************************************
* @file           Define.h
* @author         ZhaoYun(ZFSZDZ)
* @date           2024.10.12
* @Version        V1.0.0
* @description    张飞实战电子"扬帆起航"课程无感方波控制
***********************************************************************/

//画笔颜色
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE           	 0x001F  
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 //棕色
#define BRRED 			 0XFC07 //棕红色
#define GRAY  			 0X8430 //灰色
#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色
#define GRAYBLUE       	 0X5458 //灰蓝色
#define LIGHTGREEN     	 0X841F //浅绿色
#define LGRAY 			 0XC618 //浅灰色(PANNEL),窗体背景色
#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)

/*=========================================================================*/
typedef struct
{
    unsigned short ADDATA0;
    unsigned short ADDATA1;
    unsigned short ADDATA2;
    unsigned short ADDATA3;
    unsigned short ADDATA4;
}tDMA_Type;
/*=========================================================================*/
typedef struct
{
    unsigned short ValueInstant; //数据瞬时值
    unsigned short ValueAverage; //数据平均值
    unsigned short Num; //求平均值计数
    unsigned int Sum; //求平均值累加和
}tAnx_Type;
/*=========================================================================*/
typedef struct
{
    tAnx_Type An0,An3,An4,An5,An9;
    unsigned short SetDuty; //AD模块占空比调节原始值
    unsigned short TerminalVoltage;//ADC模块采样原始端电压
    unsigned short Vbus; //Vbus电压AD采样值
}tAdc_Type;
/*=========================================================================*/
typedef struct
{
    unsigned short StartDelayCount; //系统上电延时计数变量
    unsigned short LcdCount; //LCD刷新计数变量
}tSystem_Type;
/*=========================================================================*/
typedef struct
{
    unsigned char State; //状态机状态变量
    unsigned char PhaseStep; //相位变量
    unsigned char DemagnetizationTime; //退磁时间
    unsigned char ForceState; //强拖运行状态变量
    unsigned char SensorlessState; //无感运行状态变量
    unsigned char Slope; //悬空相端电压变化趋势 1 上坡 0下坡
    unsigned char ZeroPointCount;//过零点计数器
    unsigned short Duty; //占空比赋值变量
    unsigned short PwmCount;// PWM周期计数器
    unsigned short ForcePhaseTimeBase; //强拖换相时间基准值
    unsigned short ForcePhaseTimeCount; //强拖换相时间计数值
    unsigned short TerminalVoltageMax; //端电压最大阈值
    unsigned short TerminalVoltageMin; //端电压最小阈值
    unsigned short TerminalVoltage;//ADC模块采样原始端电压
    unsigned short VbusZcp;//1/2Vbus反电动势过零比较值
    unsigned short ZeventTime; //相邻过零点时间
    unsigned short CeventTime; //换相时间
    
}tBldc_Type;
/*=========================================================================*/
typedef struct
{
    unsigned char RunStopState; //运行停止状态
    unsigned char Direction; //电机旋转方向
}tMotor_Type;
/*******************Copyright (c) ZFSZDZ ******END OF FILE************/
