### UNIX笔记
```
> 追加信息
>> 重定向
bc 计算器
lpr 打印机
ps 查看进程
man ps 查看手册
2 + 3 逆波兰表达式 23+p5 p是为了将栈顶元素打印出来
command more filename 分页显示文件内容
who | more 对用户查看进行分页查看
cc -o more02 more01.c 编译文件
/bin /usr/bin /usr/local/bin 这些目录任意一个都可以全局调用
who 1.用户名 2.终端 3.登陆时间 4.用户登陆地址
man who 查看who手册
utmp文件是用户登陆信息文件
man -k utmp 搜索联机手册
man -k utmp | grep 搜索的信息 搜索联机手册
man 5 utmp 第五节utmp信息
/usr/include .h文件目录
/dev 设备文件目录 lp*打印机 fd*软驱 sd* SCSI设备的分区 /dev/tape磁带备份驱动程序 tty* 终端 dsp 声卡 /dev/mouse鼠标
Unix打印文件  cat filename >/dev/lpl 或者cp filename /dev/lpr    /dev/lpr是设备文件名
异步IO 通过信号来操作
```

## chapter 5
```
ls -li /dev/pts/2	5 crw--w---- 1 root tty 136, 2 Apr 27 12:22 /dev/pts/2	5节点 c文件类型权限 1链接 所有者 用户组 136,2表示文件大小的地方
stty 读取和修改终端驱动程序的设置
stty -echo 取消回显
stty erase X 把删除键设置为X
```

## chapter 6
```
/usr/include/signal.h 信号编号及名字
man 7 signal 查看信号联机手册
SIGINT Ctrl-C
SIGQUIT Ctrl-\
SIGSTOP\SIGKILL 不能被忽略的两个信号
```

## chapter 14 线程机制：并发函数的使用
```
单线程 10页1人计数
多线程 10页10人计数
创建线程 释放线程
sudo gcc -o hello_multi hello_multi.c  -lpthread
互斥量变量 对变量加锁
进程独立空间 线程共享空间
线程间通信 挂起线程等待信号

POSIX 效率和调度问题
线程是否可以处理所有信号量
```

## chapter 15 进程间通信
```
挂起等待多个源的输入
命名管道
共享内存
文件锁
信号量
InterProcess Communication 总览
talk从键盘和socket接收数据
poll 或 select 允许程序挂起等待输入直至有数据到达
talk的文件描述符对应了键盘、屏幕和socket,但它们仍可连接到其它进程或设备上
通信的选择 文件、管道、共享内存
文件锁  读文件锁和写文件锁 flock lock fcntl 可以只锁文件一部分
进程间的分工合作  信号和文件锁
```