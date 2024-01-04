/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2024-01-04 21:41:50
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2024-01-04 23:10:30
 * @FilePath: \6-1_矩阵键盘\src\main.c
 * @Description:矩阵键盘反馈 
 * 
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
#include "REG52.H"
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;

void main(){

    // 上电初始化
    LCD_Init();
    // 显示字符串
    LCD_ShowString(1, 1, "MatrixKey!!!");
    while(1){

        // 接收返回值
        KeyNum = MatrixKey();
        if (KeyNum)
        {
          LCD_ShowNum(2, 1, KeyNum, 2);  
        }
        

    }

}