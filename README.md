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