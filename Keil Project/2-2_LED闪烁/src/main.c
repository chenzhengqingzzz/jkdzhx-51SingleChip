/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-09 22:15:17
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-08-16 22:29:20
 * @FilePath: \2-2_LED闪烁\src\main.c
 * @Description: 周期性的让LED灯闪烁
 * 
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
#include <REG52.H>
#include <INTRINS.H> //定义nop函数的头文件

/**
 * @description: 延时为500ms的子函数，计数以达到延时的目的
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
        P2 = 0xFE; // 点亮1号LED灯
        Delay500ms();
        P2 = 0xFF; // 熄灭所有灯
        Delay500ms();
    }
    
 }