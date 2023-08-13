# 江科大自化协——51单片机笔记

## 2-1 点亮第一个LED

首先我们创建工程

双击Keil5软件进入，我们需要编写代码让单片机去识别，在写代码之前我们需要**新建一个项目**，相当于提供一个办公桌（类似于Visual studio）

![image-20220804161203467](https://img-blog.csdnimg.cn/img_convert/821383028e7f5328ea34c55055743d02.png)

最好是在桌面创建文件夹后，再创建项目子文件夹并命名位Project![image-20220804164435813](https://img-blog.csdnimg.cn/img_convert/1c24c3ddfb33a873e5c3bd668bd1212d.png)

虽然没有STC89C52，我们可以选择AT89C52代替

![image-20220804164517372](https://img-blog.csdnimg.cn/img_convert/8aa7abc3660b905fc8654f8baa179a19.png)

添加c语言文件

![image-20220804165645088](https://img-blog.csdnimg.cn/img_convert/4987171fa9306affdaf726724252fbdd.png)

命名与建立![image-20220804165738586](https://img-blog.csdnimg.cn/img_convert/94fd3c7f590c49ff9c541b6a44dcfc39.png)

在硬件中，高电平代表未接通，低电平代表正负极接通，我们通过控制每个线路的高低电平来控制这个LED模块的亮灭，而在单片机的世界中，我们单片机的cpu可以控制与LED模块相连的寄存器中的二进制数（0代表低电平，正负极接通；1代表高电平，正负极未接通）来控制高低电平的 所以我们如果需要写每个电路的二进制数来控制高低电平（参照产品手册）

![test](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/C/Users/chenzhengqing/AppData/Roaming/Typora/typora-user-images/image-20230809214103379.png?raw=true)

点亮第一个LED灯的语句： 对照二进制转十六进制表格：

![test](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/C/Users/chenzhengqing/AppData/Roaming/Typora/typora-user-images/image-20230809214355187.png?raw=true)

`main.c`

```c
/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-08 23:03:05
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-08-09 21:30:20
 * @FilePath: \2-1_点亮一个LED\main.c
 * @Description: 点亮第一个LED代码，需要F7编译，然后下载到单片机里
 * 
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
#include <REGX52.H> //里面包含引脚信息的头文件
void main(){
    P2 = 0xFE; //1111 1110  转化为16进制

    // 避免一直对P2口进行操作
    while (1){
        
    }
    
}
```

![微信图片_20230809214530.jpg](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/C/Users/chenzhengqing/AppData/Roaming/Typora/typora-user-images/%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20230809214530.jpg?raw=true)

成功点亮第一个灯

附间隔点亮灯代码：

`main.c`

```c
/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-08 23:03:05
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-08-09 21:46:28
 * @FilePath: \2-1_点亮一个LED\main.c
 * @Description: 点亮第一个LED代码，需要F7编译，然后下载到单片机里
 * 
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
#include <REGX52.H> //里面包含引脚信息的头文件
void main(){
    P2 = 0x55; //0101 0101  转化为16进制

    // 避免一直对P2口进行操作
    while (1){
        
    }
    
}
```

![微信图片_20230809214530.jpg](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/C/Users/chenzhengqing/AppData/Roaming/Typora/typora-user-images/%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20230809214708.jpg?raw=true)

## 2-2 LED闪烁

和前面的操作一样，新建一个工程，在c文件下写入以下代码

`main.c`

```c
/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-09 22:15:17
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-08-09 22:30:15
 * @FilePath: \2-2_LED闪烁\src\main.c
 * @Description: 周期性的让LED灯闪烁
 * 
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
#include <REGX52.H>

void main()
{
	
	while(1)
	{
		P2=0xFE;
		P2=0xFF;
	}
}

```

这个代码的原理是把第一个灯先点亮后熄灭，由于单片机执行代码速度特别快，看不出来在闪，所以**我们可以设置亮和灭的时间间隔为500ms**，可以通过stc-isp这个软件生成代码

![QQ图片20230809224506.png](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/QQ%E5%9B%BE%E7%89%8720230809224506.png?raw=true)

通过stc生成的代码：（需要添加一个头文件，下面将会说出来）

```c
void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_(); //
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
```

关于NOP函数的说明：https://blog.csdn.net/weixin_44643510/article/details/111401346

完整代码文件：

```c
/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-09 22:15:17
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-08-09 22:30:15
 * @FilePath: \2-2_LED闪烁\src\main.c
 * @Description: 周期性的让LED灯闪烁
 * 
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
#include <REG52.H>
#include <INTRINS.H> //定义nop函数的头文件

/**
 * @description: 延时为500ms的子函数，计数以达到延时的目的
 * @return {*}
 */
void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_(); //
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


 void main(){


    while (1){
        P2 = 0xFE; // 点亮1号LED灯
        Delay500ms();
        P2 = 0xFF; // 熄灭所有灯
        Delay500ms();
    }
    
 }
```

写入后实现效果（由于是动态的 这里就不拍照了）

## 2-3 LED流水灯

我们利用代码执行顺序，逐个来控制8个LED灯的亮灭，就可以实现跑马灯、流水灯的效果

`main.c`

```c
/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-12 16:04:30
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-08-12 16:18:19
 * @FilePath: \2-3_LED流水灯\src\main.c
 * @Description: 8个LED灯逐个点亮实现流水灯的效果
 * 
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */

#include <REG52.H>
#include <INTRINS.H> //定义nop函数的头文件


void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_(); //
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


 void main(){


    while (1){
        P2 = 0xFE; // 1111 1110
        Delay500ms();
        P2 = 0xFD; // 1111 1101
        Delay500ms();
        P2 = 0xFB; // 1111 1011
        Delay500ms();
        P2 = 0xF7; // 1111 0111
        Delay500ms();
        P2 = 0xEF; // 1110 1111
        Delay500ms();
        P2 = 0xDF; // 1101 1111
        Delay500ms();
        P2 = 0xBF; // 1011 1111
        Delay500ms();
        P2 = 0x7F; // 0111 1111
        Delay500ms();
    }
    
 }
```

实现效果：

![](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20230812164432.jpg?raw=true)

## 2-4 LED流水灯Plus

我们前面的延迟是500ms，那如果我们想要200ms延迟、1000ms、2000ms等其他自定义延迟呢？——**我们可以通过对Delay函数入手，通过控制形参实现**

stc软件生成的延时1ms函数：

```c
void Delay1ms()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}
```

我们定义形参，选定的修饰符为 unsigned int 、

> // 在C语言中，int类型表示0~2^16-1个数 其中次方是单片机所支持的16位 换算成二进制，最高表示位应该是 1111 1111 1111 1111
>
> // unsigned表示不需要考虑数字前面的正负号 所以unsigned表示的是非负数

这里使用了循环，传入的是我们的形参，每执行一次循环就会将形参-1 也就是意味着延时1*time毫秒会退出循环

```c
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
```

完整的代码：

`main.c`

```c
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
```

这样就可以独立实现我们自定义切换到下一个灯的延迟时间了

## 3-1 独立按键控制LED亮灭

首先我们要知道：

	* 单片机通电的时候，所有IO口默认都是高电平的1状态
	* 寄存器每写一个值，就会送到IO口上，这也同样会检测IO口的电平返回值读出来
	* 我们这里要实现的是，按下按键，寄存器应该读出低电平的0，松开时返回的值应该是高电平的1，这样就可以实现按键控制我们的LED灯电平了

我们在前面`P2 = 0xFE`语句其实是控制一整个寄存器实现的，寄存器8位为一组，如果我们控制一整个P2寄存器，则需要同时给8个位复制，但是我们这里只想操作具体位的LED灯，有什么办法实现呢？

这个时候我们可以打开头文件，找到对应寄存器的声明了，我这里的REG52.H头文件没有对P2寄存器和具体的位进行声明，我们这里可以使用sbit关键字来模仿其他寄存器进行位声明：

![](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/QQ%E6%88%AA%E5%9B%BE20230813154814.png?raw=true)

`REG52.H`

这里对应P2_0是第一个灯，以此类推

```H
/*  bit of P2Register_declare_by_czqzzzzzz 2023.8.13  */
sbit P2_0 = P2^0; // 0xA0;
sbit P2_1 = P2^1; // 0xA1;
sbit P2_2 = P2^2; // 0xA2;
sbit P2_3 = P2^3; // 0xA3;
sbit P2_4 = P2^4; // 0xA4;
sbit P2_5 = P2^5; // 0xA5;
sbit P2_6 = P2^6; // 0xA6;
sbit P2_7 = P2^7; // 0xA7;
```

然后我们就是需要实现P2下的0位，按下实现低电平（0），松开实现高电（1）

`main.c`

```c
/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-13 13:45:12
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-08-13 15:53:12
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
```

通过查阅开发板原理图，发现K1这个按键对应的位数是头文件定义的TXD位，所以我们可以直接操作这个按键对应的位

![](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/QQ%E6%88%AA%E5%9B%BE20230813155824.png?raw=true)

实现效果：

![](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20230813155958.jpg?raw=true)

> 由于单片机自身工作方式就是循环扫描，不是执行一次就结束，而是反复循环执行，所以这里我就没有直接写while循环也可以实现随时监听我们的按钮 ，如果写while(1)死循环的时候，此时程序会一直在循环里，无法重复执行第二次的代码（类似于外面包了个单片机大循环，里面有一个while的死循环感觉）

如果在别的地方写死循环，则我们对按键的操作则会无效了

`main.c`

```c
#include <REG52.H>

void main(){


    while (1)
    {
        /* code */
    }
        // 控制D2灯亮
    P2_1 = 0;
    // 通过查阅开发板原理图，发现K1这个按键对应的位数是头文件定义的TXD位，所以我们可以直接操作这个按键对应的位
    // 按键接通则亮灯
    if(TXD == 0){
        P2_0 = 0;
    }else{
        // 按键断开则灭灯
        P2_0 = 1;
    }

           
}
```

这里我们写了一个死循环，里面什么也没做，表明程序会在这个死循环里一直执行，循环之外的操作我们无法生效了

![](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20230813160608.jpg?raw=true)

这里可以发现我们后续对LED灯的操作无法生效了