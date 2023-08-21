/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-21 22:24:36
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-08-22 00:22:09
 * @FilePath: \jkdzhx-51SingleChip\Keil Project\3-4_独立按键控制LED灯移位\src\main.c
 * @Description: 独立按键控制LED灯移位，这边右移是减少左移位数来实现的
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
            while (--j);
        } while (--i);
        time--;
    }
}

unsigned char ledNum = 0;
void main(){
    
    // 避免在第一次按的时候出现D1灯不亮的情况
    P2 = ~0x01;
    // 通过while循环将程序控制在循环体内，而不是main的循环体，不然就会一直初始化变量
    while(1){
        
        // 按K1按键
        if (TXD == 0)
        
        {
            Delay(20);
            while(TXD == 0);
            Delay(20);
            
            // P2 = ~0x01;
            // 越界判断
            ledNum++;
            if (ledNum == 8)
            {
                ledNum = 0;
            }


            P2 = ~(0x01 << ledNum); // 这是一个反向逻辑 给1是灭，0是亮，所以应该取反
            
            
        }

        // 按K2按键的情况 这边我们的逻辑是减少左移ledNum的位数 实现相对右移
        if (RXD == 0)
        {
            Delay(20);
            while (RXD == 0);
            Delay(20);

            if (ledNum == 0) // 也需要越界判断，之前定义的是无符号char型，减到0再往下会有越界
            {
                ledNum = 7; // 先判断，才操作，如果已经为0，那么赋给最大值7
            }else{
                ledNum--; // 不是真正的往右移，而是相对于前面的少往右移一位，相当于左移
            }

            P2 = ~(0x01 << ledNum); 
            
            
        }
        
        
    }
        

}
    