/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-24 23:06:56
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-08-25 00:07:31
 * @FilePath: \jkdzhx-51SingleChip\Keil Project\4-1_静态数码管显示\src\main.c
 * @Description: 调用封装的函数实现选择数码管点亮想要的数字
 * 
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
#include "REG52.H"


// 存放着所有数码管的段数数组，由从上到下数（高位到低位）出的二进制转化为十进制，最后的0x00是什么都不显示
unsigned char NixieTable[] = {
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x00
};

/**
 * @description: 控制数码管显示封装的函数
 * @param {unsigned char} lotationSelect 左上角位选端，选中从左到右第几个数码管
 * @param {unsigned char} displayNum 点亮的段数
 * @return {*}
 */
void NixieControl(unsigned char lotationSelect, unsigned char displayNum){
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
    }
    P0 = NixieTable[displayNum];
    

}


void main(){



    // 直接调用函数点亮
    NixieControl(6, 1);
    
    //这个死循环需要写上，不然就会重复执行函数，造成灯暗、无法正确显示的现象
    while (1)
    {
        /* code */
    }
    
        
}


