
#ifndef _KEYS_H
#define _KEYS_H

#include "stm32f10x.h"


/************************************************
 ALIENTEK ս��STM32F103������ʵ��0
 ����ģ��
 ע�⣬�����ֲ��е��½������½�ʹ�õ�main�ļ� 
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/


typedef enum
{
    KEY0_PRESS = 0,
    KEY1_PRESS,
    WKUP_PRESS,
    NO_PRESS,

}Key_enuPress;



#define KEY0 GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)
#define KEY1 GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)
#define WKUP GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)


void Key_vidInit(void);

 

Key_enuPress Key_vidScan(void);


#endif



