/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-11-08 21:30:28
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-11-08 22:53:07
 * @FilePath: \jkdzhx-51SingleChip\Keil Project\5-2_LCD1602调试工具\src\main.c
 * @Description: 液晶屏1602相关配置以及使用
 * 
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
#include "REG52.H"
#include "LCD1602.h"
#include "Delay.h"

int result = 0;

void main(){
    
    // 初始化
    LCD_Init();
    
    // 调用1602的函数，具体查看相关定义以及api
    
    //1行1列显示字符c
    LCD_ShowChar(1, 1, 'c');
    //1行3列显示长度为3的字符串CZQ
    LCD_ShowString(1, 3, "CZQ");
    // 1行7列显示长度为3的数字456
    LCD_ShowNum(1, 7, 456, 3);
    // 1行11列显示长度为4的无符号数字-2877
    LCD_ShowSignedNum(1, 11, -2877, 4);
    // 将十进制转化为十六进制 65535转化为FFFF，长度为4，所以显示FFFF
    LCD_ShowHexNum(2, 1, 65535, 4);
    // 也可以直接显示十六进制数 十六进制AF转化为十六进制为AF，显示长度为4，所以是00AF
    LCD_ShowHexNum(2, 6, 0xAF, 4);
    // 将十进制转化为二进制 十进制5转化为二进制为101，显示长度为4，所以为0101
    LCD_ShowBinNum(2, 11, 5, 4);
    
    
    while (1)
    {   
        /*
        result++;
        Delay(1000);
        // 1行1列从000开始，每隔1s加一，显示屏会实时刷新
        LCD_ShowNum(1, 1, result, 3);
        */
    }
    
}