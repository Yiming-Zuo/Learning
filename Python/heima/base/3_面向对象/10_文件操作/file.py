# *-* coding:utf8 *-*


# 文件读取

# 1. 打开文件（只读）,返回文件操作对象
#  1> open()/'r'-只读
#  2> 'w'-只写
#  3> 'a'-追加
file = open('README')

# 2. 读取文件，返回文件内容
text = file.read()
print(text)

print('-' * 50)

# 文件指针在文件读取一次后移动到文件末尾
text = file.read()
print(text)

# 3. 关闭文件
file.close()


# 文件写入

# 1. 打开文件（追加）
file = open('README', 'a')

# 2. 写入文件
file.write('886')

# 3. 关闭文件
file.close()


# 大文件读取

# 1. 打开文件
file = open('README')

# 2. 一行一行读取内容
while True:
    # 读取一行内容
    text = file.readline()

    # 判断是否读到内容
    if not text:
        break

    # 输出一行内容，末尾本来已经有了一个'\n'
    print(text, end='')

# 3. 关闭文件
file.close()


# 小文件复制

# 1. 打开旧文件，创建新文件
file_read = open('README')
file_write = open('README[new]', 'w')

# 2. 从原文件读出，写到新文件
text = file_read.read()
file_write.write(text)

# 3. 关闭原、新文件
file_read.close()
file_write.close()


# 大文件复制

# 1. 打开旧文件，创建新文件
file_read = open('README')
file_write = open('README[big]', 'w')

# 2. 从原文件读出，写到新文件
while True:
    text = file_read.readline()

    if not text:
        break

    file_write.write(text)

# 3. 关闭原、新文件
file_read.close()
file_write.close()


# 文件/目录的常用管理操作（os模块）
