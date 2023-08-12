/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-12 16:56:53
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-08-12 22:20:21
 * @FilePath: \2-4_LED流水灯Plus\src\main.c
 * @Description: 自己封装延时函数
 *
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
#include <REG52.H>
#include <INTRINS.H> //定义nop函数的头文件

/**
 * @description: 初始延时1ms函数由stc工具生成，最后自己封装的延时函数，可以传参
 * @param {unsigned int} time 延时的时间 单位为ms，最后的延时应该为1*time毫秒
 * @return {*}
 */
// 在C语言中，int类型表示0~2^16-1个数 其中次方是单片机所支持的16位 换算成二进制，最高表示位应该是 1111 1111 1111 1111
// unsigned表示不需要考虑数字前面的正负号 所以unsigned表示的是非负数
void Delay(unsigned int time) //@11.0592MHz
{
    unsigned char i, j;

    while (time) {
        _nop_();
        i = 2;
        j = 199;
        do {
            while (--j)
                ;
        } while (--i);

        // 这里如果不减一的话就会一直执行while，也就意味着下一个灯不会亮
        // 这里执行1*time毫秒结束循环 就可以实现控制形参来控制循环了
        time--;
    }
}

void main()
{

    while (1) {
        P2 = 0xFE; // 1111 1110
        Delay(200);
        P2 = 0xFD; // 1111 1101
        Delay(200);
        P2 = 0xFB; // 1111 1011
        Delay(200);
        P2 = 0xF7; // 1111 0111
        Delay(200);
        P2 = 0xEF; // 1110 1111
        Delay(200);
        P2 = 0xDF; // 1101 1111
        Delay(200);
        P2 = 0xBF; // 1011 1111
        Delay(2000);
        P2 = 0x7F; // 0111 1111
        Delay(1000);
    }
}