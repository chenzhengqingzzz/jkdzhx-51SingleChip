/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-13 13:45:12
 * @LastEditors: ������-win
 * @LastEditTime: 2023-08-13 16:08:40
 * @FilePath: \3-1_������������LED����\src\main.c
 * @Description: ͨ����������ĸ���������LED���𡪡����º��ɿ��Ľ���
 * 
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
#include <REG52.H>

void main(){
    // ����D2����
    P2_1 = 0;
    // while(1){
        // ������ͨ������
        if(TXD == 0){
            P2_0 = 0;
        }else{
            // �����Ͽ������
            P2_0 = 1;
        }
        
    // }
    
}