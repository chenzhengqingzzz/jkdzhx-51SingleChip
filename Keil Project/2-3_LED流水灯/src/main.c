/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-12 16:04:30
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-08-12 16:38:14
 * @FilePath: \2-3_LED流水灯\src\main.c
 * @Description: 8个LED灯逐个点亮实现流水灯的效果
 * 
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */

#include <REG52.H>
#include <INTRINS.H> //定义nop函数的头文件


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
        P2 = 0xFE; // 1111 1110
        Delay500ms();
        P2 = 0xFD; // 1111 1101
        Delay500ms();
        P2 = 0xFB; // 1111 1011
        Delay500ms();
        P2 = 0xF7; // 1111 0111
        Delay500ms();
        P2 = 0xEF; // 1110 1111
        Delay500ms();
        P2 = 0xDF; // 1101 1111
        Delay500ms();
        P2 = 0xBF; // 1011 1111
        Delay500ms();
        P2 = 0x7F; // 0111 1111
        Delay500ms();
    }
    
 }