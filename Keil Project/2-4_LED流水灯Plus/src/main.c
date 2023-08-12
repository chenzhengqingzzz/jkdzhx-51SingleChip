/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-12 16:56:53
 * @LastEditors: ������-win
 * @LastEditTime: 2023-08-12 22:20:21
 * @FilePath: \2-4_LED��ˮ��Plus\src\main.c
 * @Description: �Լ���װ��ʱ����
 *
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
#include <REG52.H>
#include <INTRINS.H> //����nop������ͷ�ļ�

/**
 * @description: ��ʼ��ʱ1ms������stc�������ɣ�����Լ���װ����ʱ���������Դ���
 * @param {unsigned int} time ��ʱ��ʱ�� ��λΪms��������ʱӦ��Ϊ1*time����
 * @return {*}
 */
// ��C�����У�int���ͱ�ʾ0~2^16-1���� ���дη��ǵ�Ƭ����֧�ֵ�16λ ����ɶ����ƣ���߱�ʾλӦ���� 1111 1111 1111 1111
// unsigned��ʾ����Ҫ��������ǰ��������� ����unsigned��ʾ���ǷǸ���
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

        // �����������һ�Ļ��ͻ�һֱִ��while��Ҳ����ζ����һ���Ʋ�����
        // ����ִ��1*time�������ѭ�� �Ϳ���ʵ�ֿ����β�������ѭ����
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