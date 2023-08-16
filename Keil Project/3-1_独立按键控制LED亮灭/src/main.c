/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-13 13:45:12
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-08-16 22:25:44
 * @FilePath: \3-1_独立按键控制LED亮灭\src\main.c
 * @Description: 通过开发板的四个按键控制LED亮灭——按下和松开的交互
 * 
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
#include <REG52.H>

void main(){
    // 控制D2灯亮
    P2_1 = 0;
    // while(1){
        // 按键接通则亮灯
        if(TXD == 0){
            P2_0 = 0;
        }else{
            // 按键断开则灭灯
            P2_0 = 1;
        }
        
    // }
    
}