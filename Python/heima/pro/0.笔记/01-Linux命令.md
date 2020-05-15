# Linux基础命令

## 操作系统

### Ubuntu

bin - 二进制文件、常用命令

etc - 配置文件

root - 超级用户家目录

## Linux基础命令

### 切换目录 

`cd -` 

### 创建目录

`mkdir -p [嵌套目录]`

  ### 删除文件/目录

`rm -i`

`rm -r [目录]`

`rm -d [空目录]`

`rmdir [空目录]`

### 复制文件/目录

`cp -r [目录]`

`cp -i`　防止覆盖

`cp -f`

`cp -v`  提示移动路径，显示进度

`cp -a` 文件权限不丢失

### 移动文件/目录

`mv [文件夹]`　不需-r

`mv -i`

`mv -f`

`mv -v`

### 查看帮助信息

* `[命令] --help`

* `man [命令]`
* b - 后
  * f - 前
  
* / str 查找 　n 下一个匹配项

### 重命名命令

`alias ll = ls -alF`

`alias rm = rm -rf`

### 清屏

`clear` = `ctrl + L``

### 历史命令

`history`  - `!序号!`

### 修改命令

ctrl a 开头

ctrl e 结尾

ctrl d

## 单词

Virtual

kernel

Terminal

command

options

parameter

manual

change

calendar

front

back

stream

extract

# Linux 高级命令

## 1 重定向（保存终端执行命令）

`>` 覆盖

`>`追加

## 2 查看文件内容

`more 文件`　分屏查看大屏文件

`ls -lh | more`　集合管道分屏查看终端内容

## 3 软链接（快捷方式）

` ln -s 源文件/目录路径(绝对路径)　快捷方式` 

## 4 硬链接（备份文件数据）

`ln 源文件路径(相对目录/绝对路径) 新文件名` 文件别名，指向同一文件数据

不能对目录进行操作

硬连接数：到达文件的路径数量(`.`,`..`)

硬链接数为0时，文件数据被删除

## 5 文本搜索命令

`grep str 文件`

- -i 忽略大小写
- -n 显示行号
- -v 显示不包含文本的所有行

### 5.1 结合正则表达式

`^[str,str]` 开头

`str$` 结尾

`str.str`匹配一个非换行符的字符

### 5.2 结合管道命令

`ls / | grep str`

## 6 查找文件命令 

`find . -name str`

### 结合通配符

`*` 0个或任意个字符

`?` 1个字符

## 7 压缩与解压缩命令

### 7.1 压缩格式

- .gz/.bz2 -- tar
- .zip -- zip/unzip

## 7.2 tar命令

### ７.2.1 压缩

`tar -zcvf test.tar.gz *.txt`

`tar -jcvf test.bz2 *.txt`

### 7.2.2 解压缩

`tar -zxvf test.tar.gz -C AA`

`tar -jxvf test.bz2`

### 7.2.3 命令选项

-c 打包

-x 解包

-z 压缩/解压缩(.gz)

-j 压缩/解压缩(.bz2)

-v 显示打包/解包信息

-f 指定文件名称

-C 制定解压缩目录

## 7.3 zip/unzip命令

`zip text.zip *txt`

`unzip text.zip -d AA`

-d 解压到指定目录

### 7.4 小结

.gz 占用空间少

.zip 操作简单

## 8 文件权限命令

### 8.1 字母法

`chmod u/g/o/a +/- r/w/x 1.txt`

`chmod u/g/o/a = -/rwx 1.txt`

`chmod u=r,g=-,o=rw 1.txt`



u:user 文件所有者

g:group 用户组

o:other 其他用户

a: all 所有用户



r:可读

w:可写

x:可执行

-：无权限



-:撤销权限

+:增加权限

=:设置权限

### 8.2 数字法

`chmod 777 1.txt`

r:4

w:2

x:1

## 9 获取管理员权限

### 9.1 sudo

`sudo -s` 切换到root用户

`exit` 退出登录用户

### 9.2 whoami

`whoami`

### 9.3 who

`who` 查看所有登录的用户

### 9.4 passwd

`passwd [用户]` 修改用户密码

### 9.5 which

`which 命令` 查看命令位置

### 9.6 关机重启

`shutdown -h now`

`reboot`

