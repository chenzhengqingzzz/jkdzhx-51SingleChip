/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-16 22:17:02
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-08-16 23:16:23
 * @FilePath: \jkdzhx-51SingleChip\Keil Project\3-2_独立按键控制LED状态\src\main.c
 * @Description: 通过写延迟函数的方式来解决物理按键的抖动问题，并且模拟了键程开关状态
 *
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
#include <REG52.H>

/**
 * @description: 延时函数
 * @param {unsigned int} time 延时时间
 * @return {*}
 */
void Delay(unsigned int time) //@11.0592MHz
{
    unsigned char i, j;

    while (time) {
        i = 2;
        j = 199;
        do {
            while (--j)
                ;
        } while (--i);
        time--;
    }
}

void main()
{
    while (1) {
		// 当K1按键按下时
		if (TXD == 0)
		{
			// 过滤按下抖动
			Delay(20);
			// 按下代表低电平，让它一直循环，一松手就变为高电平
			// 这里主要是检测你松没松手 0代表按下状态，变为1就代表松手
			while (TXD == 0);
			// 过滤松手抖动
			Delay(20);
			// 这边可以理解成一个完整的键程（按下到松开）
			// --------------------------------------

			// 实现按完一个键程操作灯的亮灭
			P2_0 = ~P2_0;
		}
		
    }
}