/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-09-06 23:24:50
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-09-07 00:25:27
 * @FilePath: \jkdzhx-51SingleChip\Keil Project\5-1_模块化编程\src\main.c
 * @Description: 将delay函数进行封装，直接调用实现模块化
 * 
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
#include "REG52.H"
#include "Delay.h"
#include "NixieControl.h"

void main(){
    while (1)
    {
    // LED灯实现
    // P2_0 = 0;
    // Delay(500);
    // P2_0 = 1;
    // Delay(500);

    // 数码管实现
    NixieControl(1, 1);
    NixieControl(2, 2);
    NixieControl(3, 3);

    }
    
}