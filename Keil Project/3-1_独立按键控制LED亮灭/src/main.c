/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-13 13:45:12
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-08-13 13:47:59
 * @FilePath: \3-1_独立按键控制LED亮灭\src\main.c
 * @Description: 通过开发板的四个按键控制LED亮灭——按下和松开的交互
 * 
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
#include "REG52.H"

void main(){
    while(1){
        P2 = 0xFE;
    }
}