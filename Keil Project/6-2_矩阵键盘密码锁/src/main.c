/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2024-01-04 21:41:50
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2024-01-08 22:26:49
 * @FilePath: \6-2_矩阵键盘密码锁\src\main.c
 * @Description:矩阵键盘反馈 
 * 
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
#include "REG52.H"
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password;
unsigned int inputCount;

void main(){

    // 上电初始化
    LCD_Init();
    // 显示字符串
    LCD_ShowString(1, 1, "Password:");
    while(1){

        // 接收返回值
        KeyNum = MatrixKey();
        if (KeyNum){
          if(KeyNum <= 10){ //如果S1~S10按键按下，则输入密码
              if (inputCount < 4){ //输入次数小于4则会进行更新
                Password *= 10; //新输入密码的话，原来的键位会左移
                Password += KeyNum % 10; //获取一位密码，如果是S10的话则转化为0
              }
              inputCount++; //计次+1
              LCD_ShowNum(2, 1, Password, 4); //更新显示
          }
        }
        if(KeyNum == 11){ //S11按键的确认逻辑
            if(Password == 2345){
                LCD_ShowString(1, 14, "OK!");
                Password = 0;
                inputCount = 0;
                LCD_ShowNum(2, 1, Password, 4); //更新显示
            }else{
                LCD_ShowString(1, 14, "ERR");
                Password = 0;
                inputCount = 0;
                LCD_ShowNum(2, 1, Password, 4); //更新显示
            }
        }
        if(KeyNum == 12){ //S12按键的取消逻辑
            Password = 0;
            inputCount = 0;
            LCD_ShowNum(2, 1, Password, 4); //更新显示
        }
    }

}