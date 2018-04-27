### UNIX笔记
```
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
man -k utmp 搜索联机手册
man -k utmp | grep 搜索的信息 搜索联机手册
man 5 utmp 第五节utmp信息
/usr/include .h文件目录
/dev 设备文件目录 lp*打印机 fd*软驱 sd* SCSI设备的分区 /dev/tape磁带备份驱动程序 tty* 终端 dsp 声卡 /dev/mouse鼠标

## chapter 5
ls -li /dev/pts/2	5 crw--w---- 1 root tty 136, 2 Apr 27 12:22 /dev/pts/2	5节点 c文件类型权限 1链接 所有者 用户组 136,2表示文件大小的地方
stty 读取和修改终端驱动程序的设置
```