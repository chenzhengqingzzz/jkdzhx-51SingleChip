/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-09 22:15:17
 * @LastEditors: ������-win
 * @LastEditTime: 2023-08-09 22:47:00
 * @FilePath: \2-2_LED��˸\src\main.c
 * @Description: �����Ե���LED����˸
 * 
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
#include <REG52.H>
#include <INTRINS.H> //����nop������ͷ�ļ�

/**
 * @description: ��ʱΪ500ms���Ӻ����������Դﵽ��ʱ��Ŀ��
 * @return {*}
 */
void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_(); //
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


 void main(){


    while (1){
        P2 = 0xFE; // ����1��LED��
        Delay500ms();
        P2 = 0xFF; // Ϩ�����е�
        Delay500ms();
    }
    
 }