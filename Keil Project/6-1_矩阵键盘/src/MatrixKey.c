/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2024-01-04 21:56:35
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2024-01-04 23:14:23
 * @FilePath: \6-1_矩阵键盘\src\MatrixKey.c
 * @Description: 按列逐行扫描矩阵键盘（参见图纸下面P13~P10的IO口）
 * 
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
#include "REG52.H"
#include "Delay.H"

/**
 * @description: 按列扫描每一个按键，如果按下（低电平）则选中
 * @return {unsigned char} KeyNum 显示的值
 */
unsigned char MatrixKey(){

    unsigned char KeyNum = 0;

    // 先将P1所有bit置为1
    P1 = 0xFF;
    // 将P1寄存器的第四bit置为0
    P1 = 0xF7;// 扫描第一列
    if (P1 == 0x77) // 判断第一行是否按下
    {
        // 加入延时函数消除抖动
        Delay(20);
        // 判断是否松手，如果松手，则不需要加入延时函数消除抖动
        while (P1 == 0x77)
        {
            Delay(20);
            // 按下了矩阵按键S1，所以我们赋值为1
            KeyNum = 1;
        }
        
    }
    
    if (P1 == 0xB7) // 判断第二行是否按下
    {
        Delay(20);
        while (P1 == 0xB7)
        {
            Delay(20);
            // 按下了矩阵按键S5，所以我们赋值为5
            KeyNum = 5;
        }
        
    }
    if (P1 == 0xD7) // 判断第三行是否按下
    {
        Delay(20);
        while (P1 == 0xD7)
        {
            Delay(20);
            // 按下了矩阵按键S9，所以我们赋值为9
            KeyNum = 9;
        }
        
    }
    if (P1 == 0xE7) // 判断第四行是否按下
    {
        Delay(20);
        while (P1 == 0xE7)
        {
            Delay(20);
            // 按下了矩阵按键S13，所以我们赋值为13
            KeyNum = 13;
        }
        
    }

    // 先将P1所有bit置为1
    P1 = 0xFF;
    P1 = 0xFB; // 扫描第二列
    if(P1 == 0x7B){Delay(20);while(P1 == 0x7B);Delay(20);KeyNum = 2;} // 判断第一行是否按下
    if(P1 == 0xBB){Delay(20);while(P1 == 0xBB);Delay(20);KeyNum = 6;} // 判断第二行是否按下
    if(P1 == 0xDB){Delay(20);while(P1 == 0xDB);Delay(20);KeyNum = 10;} // 判断第三行是否按下
    if(P1 == 0xEB){Delay(20);while(P1 == 0xEB);Delay(20);KeyNum = 14;} // 判断第四行是否按下

    // 先将P1所有bit置为1
    P1 = 0xFF;
    P1 = 0xFD; // 扫描第三列
    if(P1 == 0x7D){Delay(20);while(P1 == 0x7D);Delay(20);KeyNum = 3;} // 判断第一行是否按下
    if(P1 == 0xBD){Delay(20);while(P1 == 0xBD);Delay(20);KeyNum = 7;} // 判断第二行是否按下
    if(P1 == 0xDD){Delay(20);while(P1 == 0xDD);Delay(20);KeyNum = 11;} // 判断第三行是否按下
    if(P1 == 0xED){Delay(20);while(P1 == 0xED);Delay(20);KeyNum = 15;} // 判断第四行是否按下

    // 先将P1所有bit置为1
    P1 = 0xFF;
    P1 = 0xFE; // 扫描第四列
    if(P1 == 0x7E){Delay(20);while(P1 == 0x7E);Delay(20);KeyNum = 4;} // 判断第一行是否按下
    if(P1 == 0xBE){Delay(20);while(P1 == 0xBE);Delay(20);KeyNum = 8;} // 判断第二行是否按下
    if(P1 == 0xDE){Delay(20);while(P1 == 0xDE);Delay(20);KeyNum = 12;} // 判断第三行是否按下
    if(P1 == 0xEE){Delay(20);while(P1 == 0xEE);Delay(20);KeyNum = 16;} // 判断第四行是否按下
    
    return KeyNum;

}