/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-24 23:06:56
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-08-24 23:48:23
 * @FilePath: \jkdzhx-51SingleChip\Keil Project\4-1_静态数码管显示\src\main.c
 * @Description: 让从左到右第三个数码管显示“6”,调用封装的函数实现
 * 
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
#include "REG52.H"


// 存放着所有数码管的段数数组
unsigned char NixieTable[] = {
    0x3F, 0x06, 0x5B
}

/**
 * @description: 控制数码管显示封装的函数
 * @param {unsigned char} lotationSelect 位选端，选中从左到右第几个数码管
 * @param {unsigned char} displayNum 点亮的段数
 * @return {*}
 */
void NixieControl(unsigned char lotationSelect, displayNum){
    switch (lotationSelect)
    {
    case 1:
        // 对应的是Y7：
        P2_4 = 1; P2_3 = 1; P2_2 = 1;
        break;
    case 2:
        // 对应的是Y6
        P2_4 = 1; P2_3 = 1; P2_2 = 0;
        break;
    case 3:
        // Y5
        P2_4 = 1; P2_3 = 0; P2_2 = 1;
        break;
    case 4:
        // Y4
        P2_4 = 1; P2_3 = 0; P2_2 = 0;
        break;
    case 5:
        // Y3
        P2_4 = 0; P2_3 = 1; P2_2 = 1;
        break;
    case 6:
        // Y2
        P2_4 = 0; P2_3 = 1; P2_2 = 0;
        break;
    case 7:
        // Y1
        P2_4 = 0; P2_3 = 0; P2_2 = 1;
        break;
    case 8:
        // Y0
        P2_4 = 0; P2_3 = 0; P2_2 = 0;
        break;

    default:
        break;
    }
    

}


void main(){

    // 左上角的位选端 遵循CBA读法 我们这边选择Y5
   

    // 选完第三个二极管，我们现在点亮一个一个发光管
    // 从高位到低位，由于是共阴极，所以1是亮


    NixieControl(6, 1);
    P0 = 0X7D;
        
}


