/***********************************************************************
* @file           UserParams.h
* @author         ZhaoYun(ZFSZDZ)
* @date           2024.12.24
* @Version        V1.0.0
* @description    用户自定义宏定义
***********************************************************************/

#define     ORIENT_DUTY     (200)   //5%~10% 预定位占空比设置
#define     ORIENT_TIME     (4000)  //250ms 预定位时间设置

#define     DIR_CW          (0)
#define     DIR_CCW         (1)
#define     DEFAULT_DIR     (DIR_CCW) //默认逆时针转动
            
#define     DUTY_MAX        (500) //25%
#define     DUTY_MIN        (300) //15%
#define     DUTY_STEP       (1)

//RPM = 60*f/P = 60/T360*P = 60/T60*6*P = 60 000000/T60*62.5us*6*2 = 80000/T60(count)
#define     FORCEPHASETIME_MAX        (266) //300RPM
#define     FORCEPHASETIME_MIN        (133) //600RPM
#define     FORCEPHASETIME_STEP       (10)

#define     BEMF_ZERO_FACTOR    (30000) //理论值为50% 实际情况可以灵活调整
#define     PHASE_N_FACTOR      (5242) //升频升压阶段 换相系数N  Vbus*N%

#define     TEST_PIN_HIGH   {GPIOD->BSRR |= 0x00000008;}
#define     TEST_PIN_LOW    {GPIOD->BSRR |= 0x00080000;}
/*******************Copyright (c) ZFSZDZ ******END OF FILE************/
