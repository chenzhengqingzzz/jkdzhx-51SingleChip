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

**扩展：C语言中的一些运算符**：

![](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/QQ%E6%88%AA%E5%9B%BE20230816215751.png?raw=true)

这里我新掌握的是位运算：

我们以1字节（8位）数据举例：

```c
//按位左右移：
0011 1100 << 1 //运算结果：0111 1000
0011 1100 >> 2 //运算结果：0000 1111

按位与或异或取反：
0001 1000 & 0010 1010 		//运算结果：0000 1000
0001 1000 | 0010 1010 		//运算结果：0011 1010
//异或是相同取0 不同取1
0001 1000 ^ 0010 1010 		//运算结果：0011 0010
~0001 1000            		//运算结果：1110 0111
```

## 3-2 独立按键控制LED灯状态（模拟日常开关灯）

我们这一节需要实现完成一个按钮的键程再改变LED灯的亮灭（很像日常开关灯）

首先了解一下**按键的抖动**

	* 对于我们的机械开关，当机械触点断开、闭合时，由于机械触点的弹性作用，一个开关在闭合的时候不会马上稳定地接通，相应的，在断开的时候也不会一下子就断开，所以在开关闭合以及断开的一瞬间会伴随着一连串的抖动

![](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/QQ%E6%88%AA%E5%9B%BE20230816230623.png?raw=true)

比如日常的开关灯，我们肉眼无法观察到这种抖动，但单片机的执行速率是MHz级别的，会有明显影响，我们如何消除这个影响呢？

 * 硬件消抖：通过电=电路过滤掉
 * 软件处理：按键按下的时候延时发生延时，松手的时候也发生延时

```c
/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-16 22:17:02
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-08-16 23:09:25
 * @FilePath: \jkdzhx-51SingleChip\Keil Project\3-2_独立按键控制LED状态\src\main.c
 * @Description: 通过写延迟函数的方式来解决物理按键的抖动问题，并且模拟了键程开关状态
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
            while (--j)
                ;
        } while (--i);
        time--;
    }
}

void main()
{
    while (1) {
		// 当K1按键按下时
		if (TXD == 0)
		{
			// 过滤按下抖动
			Delay(20);
			// 按下代表低电平，让它一直循环，一松手就变为高电平
			// 这里主要是检测你松没松手 0代表按下状态，变为1就代表松手
			while (TXD == 0);
			// 过滤松手抖动
			Delay(20);
			// 这边可以理解成一个完整的键程（按下到松开）
			// --------------------------------------

			// 实现按完一个键程操作灯的亮灭
			P2_0 = ~P2_0;
		}
		
    }
}
```

按下K1按键不亮：

![](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20230816231346.jpg?raw=true)

松开K1按键后才亮：

![](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20230816231351.jpg?raw=true)

## 3-3 独立按键控制LED显示二进制

我们参照上一节代码，中间进行检查：、

```c
/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-16 23:18:50
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-08-16 23:45:39
 * @FilePath: \jkdzhx-51SingleChip\Keil Project\3-3_独立按键控制LED显示二进制\src\main.c
 * @Description: 实现按键控制LED显示二进制，亮代表0，灭代表1
 *
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */
#include "REG52.H"

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

void main()
{
    unsigned char LEDNum = 0;
    while (1)
    {
        if (TXD == 0)
        {
            Delay(20);
            while (TXD == 0);
            Delay(20);

            // P2和P2_1不同，前者是8个位的总线，后者是1个位
            // P2++; // 直接加会导致溢出 0000 0000
        }
        
    }
    
}
```

这个时候会发现LED灯的状态和我们需求刚好相反，**该亮的灭，该灭的亮**

![](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20230816235214.jpg?raw=true)

如果我们在++语句下面加`P2 = ~P2`，则会发现**灯都不亮**

P2上电默认为1111 1111 自加取反后变成1111 1111 每次循环总是会变成1111 1111，所以就会有问题

我们的思路是装一个变量，让这个变量自加后再取反就可以了

调整之后：

`main.c`

```c
void main()
{
    unsigned char LEDNum = 0;  // 无符号字符型为0~255的8位二进制数据，表示一个寄存器
    while (1)
    {
        if (TXD == 0)
        {
            Delay(20);
            while (TXD == 0);
            Delay(20);

            LEDNum++; // 刚开始是0000 0001
            P2 = ~LEDNum; // 取反后就是1111 1110
        }
        
    }
    
}
```

这样就可以实现我们的效果了

![](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20230816235611.jpg?raw=true)

## 3-4 独立按键控制LED灯移位

想象一下我们需要控制LED灯移位的逻辑：

```
0000 0001 -> 0000 0010 -> 0000 00100 -> 0000 1000 -> 0001 0000 -> 0010 0000 -> 0100 0000 -> 1000 0000
```



使用位运算符实现相关：

```
0000 0001 0x01<<0

0000 0010 0x01<<1

0000 0100 0x01<<2

0000 1000 0x01<<3

0001 0000 0x01<<4

0010 0000 0x01<<5

0100 0000 0x01<<6

1000 0000 0x01<<7 （这些都是正逻辑，1为亮，0为灭，一会需要取反）

```

可以让0-7定义为LEDNum，每按一下+1，移到最左边时再回去（if）



`main.c`

```c
/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-21 22:24:36
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-08-21 23:47:14
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
             
    }
        

}
```

发现有一个小问题：按第一下的时候直接是D2亮而不是D1亮，给P2赋初始值`P2=~0x01;`,写入主函数

```c
void main()
{
    P2=~0x01;
	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			
			LEDNum++;
			if(LEDNum>=8)     // if语句如果只有一句，可以不用{}
				LEDNum=0;
			P2=~(0x01<<LEDNum) // P2是一个反向逻辑，给1是灭，给0是亮，所以取反
		}
	}
}

```



另外一个问题：如果有两个按键 一个控制左移灯，另一个控制右移灯呢？

我们要知道：

	* 这个是相对的概念，所谓的右移不是真正的往右移，而是相对于前面少往右一以为，这样子我们看到了就相当于左移了
	* 比如，本来是左移五位，按下K2后变成了左移4位，相当于右移了一位
	* 这里的左移右移是以 `1111 1110 ---> 1111 1101`



K2按键补充：

```c
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
```

实现效果：

![](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20230822002344.jpg?raw=true)

![](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20230822002352.jpg?raw=true)

![](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20230822002358.jpg?raw=true)

## 4-1 静态数码管显示

首先我们来了解一下8位数码管：

	* LED数码管：数码管是一种简单且廉价的显示器，由多个发光二极管封装在一起组成“8”字型器件

![image-20220807162302252](https://img-blog.csdnimg.cn/img_convert/a5a19c8f0c015fe66e36ad8321472e28.png)

1位数码管的连接管脚图：

![image-20220807162541878](https://img-blog.csdnimg.cn/img_convert/c5defdda9b932f6fc81c4c3978c0592c.png)

在这幅图里，A~G和一个字节的八位相对应，这样看虽然有点杂乱，但是每个引脚引出都是遵循“就近原则”的



举例：我们要在数码管显示数字”6“

​	那我们需要把AFEDCG段点亮：

		* 上面的共阴极接法图中，我们规定3,8端接地，所以我们要在A~DP段输入高电平才能连通（产生电势差），数码管段才会亮，所以输入的段码应该是：10111110，这8个数据发送给单片机的IO口，即可显示“6”
		* 在对应共阳极接法图中，我们规定3,8端接VCC电源，然后在A~DP段输入01000001（和共阴极的段码相反）



四位一体数码管（四个大公共端引出，其余字母相同的管子连在一块，比如所有数码管的A段连在一块，B段连在一块：

![image-20220807163717254](https://img-blog.csdnimg.cn/img_convert/8dae135bf0eed5abd7c923655f48105c.png)



接下来我们看一看和数码管组所连接的两个译码器：

![](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/QQ%E6%88%AA%E5%9B%BE20230823231932.png?raw=true)

首先我们看上面的138译码器：

![](https://i0.hdslb.com/bfs/note/95b3ac66b620d7fc55508b6db6a9cce37c9c952b.png@690w_!web-note.avif)

左上角的输入口ABC是从低到高位排下来的，我们正常应该按照CBA来读

左下角是使能端的连接，目的是让它能工作，给100就可以让这个芯片工作了（了解就好，实际开发不用管）

右边的是控制输出的8个口，分别位选口连接着每一个LED灯，它们都是共阴极的连接



通过给CBA三个输入端口二进制数字0和1来选择转换二进制之后的输出端口（转换成数字几久控制Y几），每个Y头上的“—”这一横是代表低电平有效（即给0）：

![](https://i0.hdslb.com/bfs/note/7bd12860d3ff60816bdd4b3768b553d59a97d1f7.png@690w_!web-note.avif)



245这个译码器的作用是双向缓冲，由于低电平驱动就会让电路的驱动效果更好，例如我们在做LED亮灯的时候，使用的是低电平驱动，灯会比高电平驱动更亮一些，所以就会这样来一个缓冲（我们就理解为直接连通就好）（图标记的位置可能和A2开发板不一样，但引脚和原理是一样的）

![](https://i0.hdslb.com/bfs/note/8d717139f9d4cac41e90abde2f51d97b70c29ff7.png@690w_!web-note.avif)

​	CC2是一个滤波电容，它用来过滤干扰，稳定电源，确定电路的稳定性，提高电路工作性能

​	R4是一组排阻，它限流防止电流过大



译码器左上角是位选端，遵循从下到上的CBA读取

* 第三位显示6，74138对应于LED6是Y5，则P24-P22输入101

![](https://i0.hdslb.com/bfs/note/891b3b9e3d08afa2395269455e7000a7e4ccf67c.png@690w_!web-note.avif)

 我们的数码管选择点亮也是从下到上（高位到低位）

* 下面P07-P00对应是0111 1101对应十六进制数为7D

![](https://i0.hdslb.com/bfs/note/c54ce7170dcac9a817014d916755d19196caa6b7.png@690w_!web-note.avif)



下面的代码则会实现点亮“6”的结果：

![](https://i0.hdslb.com/bfs/note/924bc63eba765c234bb1050cb17a50602475f654.png@558w_!web-note.avif)



然后提一下C语言的数组，和之前学的JS大差不差：

![](https://i0.hdslb.com/bfs/note/94e2c8bae6c290f4c5c73b39d8df8ebee23b7765.png@690w_!web-note.avif)

我们如果需要在某一个数码管显示某一个数字，我们最好是直接封装函数，在主函数直接调用就好了 所以有了这个思路：

`main.c`

```c
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
```

这样我们只需在main函数调用：

`main.c`

```c
void main(){



    // 直接调用函数点亮
    NixieControl(6, 1);
    
    //这个死循环需要写上，不然就会重复执行函数，造成灯暗、无法正确显示的现象
    while (1)
    {
        /* code */
    }
    
        
}
```

这里是想在第6个数码管点亮1这个数字，所以我们传了6和1

实现效果：

![](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20230825001303.jpg?raw=true)

附上完整代码：

`main.c`

```c
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



```

## 4-2 动态数码管显示

我们这一节实现多个位置显示不同的数字

1. 动态数码管的原理就是不断的扫描，这就是一个循环的过程，所以我们可以先把`Nixie(2, 3)`放到while循环里，我们这边选择点亮第一个数码管为1，第二个数码管为2，第三个数码管为3

2. 通用延时函数

   ```c
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
   ```

   我们通过延时函数，每一次控制数码管的时候都进行延时，当我们调用间隔为200的时候，则会发现是每隔200ms两下一个数字，如此循环往复

3. 在main函数的循环中进行延时调用，可以消除残影

```c
void main(){



    
    
    // 这个死循环需要写上，不然就会重复执行函数，造成灯暗、无法正确显示的现象
    // 由于动态数码管显示的实现原理是重复扫描过程，骗过人眼，所以我们应该吧点亮数码管放到循环里
    while (1)
    {
        // 直接调用函数点亮
        NixieControl(1, 1);
        // 需要加入延时函数，如果是无延迟的话，数码管会有残影
        // Delay(20);
        NixieControl(2, 2);
        // Delay(20);
        NixieControl(3, 3);
        // Delay(20);
    }
    
        
}
```

如果我们不进行延时，则会发现此时位置显示有点错乱

![](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20230828235055.jpg?raw=true)

这个问题来源于数码管的常见问题，我们需要加一段**消影代码**

> 位选 **段选 位选** 段选 位选 段选，在下一位进行位选，上一位的段选会窜到下一位（二者紧挨着而且下一位的段选还没有到）如何避免这个问题呢？

4. 还有另一种方法，我们可以直接在数码管函数里写入延时逻辑，在段选之后加入清零，形成 位选 段选 清零 位选 段选 清零，即使窜到下一位也是清零窜到下一位，优化子函数

```c
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
    Delay(1);
    // 由于数码管是直接使用单片机扫描，会有串口冲突，所以我们在每次对数码管进行修改之后，将段数全部熄灭
    P0 = 0x00;
    

}
```



如此，数码管就可以正常在我们眼里显示123了 完整代码：

`main.c`

```c
/*
 * @Author: czqczqzzzzzz(czq)
 * @Email: tenchenzhengqing@qq.com
 * @Date: 2023-08-28 22:59:27
 * @LastEditors: 陈正清-win
 * @LastEditTime: 2023-08-28 23:13:09
 * @FilePath: \jkdzhx-51SingleChip\Keil Project\4-2_动态数码管显示\src\main.c
 * @Description: 动态数码管显示
 * 
 * Copyright (c) by czqczqzzzzzz(czq), All Rights Reserved.
 */

#include "REG52.H"


// 存放着所有数码管的段数数组，由从上到下数（高位到低位）出的二进制转化为十进制，最后的0x00是什么都不显示
unsigned char NixieTable[] = {
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x00
};

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
    Delay(1);
    // 由于数码管是直接使用单片机扫描，会有串口冲突，所以我们在每次对数码管进行修改之后，将段数全部熄灭
    P0 = 0x00;
    

}


void main(){



    
    
    // 这个死循环需要写上，不然就会重复执行函数，造成灯暗、无法正确显示的现象
    // 由于动态数码管显示的实现原理是重复扫描过程，骗过人眼，所以我们应该吧点亮数码管放到循环里
    while (1)
    {
        // 直接调用函数点亮
        NixieControl(1, 1);
        // 需要加入延时函数，如果是无延迟的话，数码管会有残影
        // Delay(20);
        NixieControl(2, 2);
        // Delay(20);
        NixieControl(3, 3);
        // Delay(20);
    }
    
        
}



```

实现效果：

![](https://github.com/chenzhengqingzzz/jkdzhx-51SingleChip/blob/Pictures/%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20230828235539.jpg?raw=true)
