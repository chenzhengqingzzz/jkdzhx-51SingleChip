/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-09-06 23:04:44
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-09-06 23:05:23
 * @FilePath: \jkdzhx-51SingleChip\Keil Project\5-1_模块化编程\src\Delay.c
 * @Description: 单独封装delay代码，以后在#include "Delay.h"中使用
 * 
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
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