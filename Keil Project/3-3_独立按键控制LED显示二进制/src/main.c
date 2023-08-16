/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-16 23:18:50
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-08-16 23:54:30
 * @FilePath: \jkdzhx-51SingleChip\Keil Project\3-3_独立按键控制LED显示二进制\src\main.c
 * @Description: 实现按键控制LED显示二进制，亮代表0，灭代表1
 *
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
#include "REG52.H"

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
            while (--j);
        } while (--i);
        time--;
    }
}

void main()
{
    unsigned char LEDNum = 0;  // 无符号字符型为0~255的8位二进制数据，表示一个寄存器
    while (1)
    {
        if (TXD == 0)
        {
            Delay(20);
            while (TXD == 0);
            Delay(20);

            // P2和P2_1不同，前者是8个位的总线，后者是1个位
            // 1111 1111
            // P2++; // 直接加会导致溢出 0000 0000
            // ~P2; // 这样会溢出后取反 1111 1111 每次循环都会是这样 不符合要求
            // 可以直接自减来实现效果
            // P2--;

            LEDNum++; // 刚开始是0000 0001
            P2 = ~LEDNum; // 取反后就是1111 1110
        }
        
    }
    
}