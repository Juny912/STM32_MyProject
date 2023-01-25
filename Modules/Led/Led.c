
#include "Led.h"

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



void Led_vidInit(void)
{
    /*Initial PB5 PE5 to Low output*/
    GPIO_ResetBits(GPIOB, GPIO_Pin_5);
    GPIO_SetBits(GPIOE, GPIO_Pin_5);
}


void Led_vidSetHigh(Led_enuNum LedNum)
{
    if (LED0 == LedNum)    
    {
        GPIO_SetBits(GPIOB, GPIO_Pin_5);
    }
    else if (LED1 == LedNum)
    {
        GPIO_SetBits(GPIOE, GPIO_Pin_5);
    }
    else
    {
        /*Do nothing*/
    }
    
}

void Led_vidSetLow(Led_enuNum LedNum)
{
    if (LED0 == LedNum)    
    {
        GPIO_ResetBits(GPIOB, GPIO_Pin_5);
    }
    else if (LED1 == LedNum)
    {
        GPIO_ResetBits(GPIOE, GPIO_Pin_5);
    }
    else
    {
        /*Do nothing*/
    }
    
}



