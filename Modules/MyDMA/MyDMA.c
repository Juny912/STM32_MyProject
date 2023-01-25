
#include "MyDMA.h"


u16 DMA_MemLen = 0;
/*�������ӣ� MyDMA_Configure(DMA1_Channel4, &USART1->DR, (u32)SendBuff, 1000);*/
/*��оƬ�ֲ�USARTʹ��DMAͨ��4,������DMA1_Channel4,      Ҫ��SendBuff�����ݴ��䵽���ڷ��ͼĴ���USART1->DR,һ�δ�1000������*/
void MyDMA_Configure(DMA_Channel_TypeDef *DMA_CHx, u32 cpar, u32 cmar, u16 cndtr)
{
    /*�����ӽ����ݴӴ洢�����䵽UART���ͼĴ���*/

    /*1. ʹ��DMAʱ��,DMAֱ������AHB�����ϣ�����ʹ��RCC_AHBPeriphClockCmd*/
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE); 

    DMA_MemLen = cndtr;/*��¼��Ҫ���������ֵ*/

    /*2. ��ʼ��DMA*/
    DMA_InitTypeDef DMA_InitStruct;    
    DMA_InitStruct.DMA_PeripheralBaseAddr = cpar;   /*����Ĵ�������ַ*/
    DMA_InitStruct.DMA_MemoryBaseAddr = cmar;       /*�洢������ַ*/
    DMA_InitStruct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;  /*�������ݿ��,8λ*/
    DMA_InitStruct.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;          /*�洢�����ݿ��,8λ*/
    DMA_InitStruct.DMA_BufferSize = cndtr;                /*ͨ��������������8�����ݣ�ʵ��������CNDTRx*/
    DMA_InitStruct.DMA_DIR = DMA_DIR_PeripheralDST; /*���ݴ��䷽��������Ŀ��*/
    DMA_InitStruct.DMA_MemoryInc = DMA_MemoryInc_Enable;    /*�洢����������ģʽ����*/
    DMA_InitStruct.DMA_PeripheralInc = DMA_PeripheralInc_Disable;  /*������������ģʽ�ر�*/
    DMA_InitStruct.DMA_Mode = DMA_Mode_Normal;      /*ģʽ���Ƿ�ѭ��,��ѭ��*/
    DMA_InitStruct.DMA_Priority = DMA_Priority_High;  /*���ȼ�,��*/
    DMA_InitStruct.DMA_M2M = DMA_M2M_Disable;       /*�Ƿ�洢������洢������ʹ��*/
    DMA_Init(DMA_CHx, &DMA_InitStruct);

    /*3. ʹ��UART1 DMA���͹���*/
    USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);

    /*4. ʹ��DMAͨ�����������䣬ʹ��DMA1��������ͨ��1*/
    DMA_Cmd(DMA_CHx, ENABLE);

    /*��ʱ�Ѿ�����DMA����*/
    
    
}



void MyDMA_Enable(DMA_Channel_TypeDef *DMA_CHx)
{
    /*�ر�DMA*/
    DMA_Cmd(DMA1_Channel1, DISABLE);
    /*�������ô�������������Ϊÿ�δ�����Ϻ�CNDTRx��ֵ��ݼ���0��������Ҫ�������ô���������*/
    DMA_SetCurrDataCounter(DMA1_Channel1, DMA_MemLen);
    /*���¿���������DMA����*/
    DMA_Cmd(DMA1_Channel1, ENABLE);
}



