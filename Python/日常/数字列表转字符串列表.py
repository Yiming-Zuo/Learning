# 将列表中的数字转为字符串

# 方法一
my_list = [1, 2, 3, 4, 5]
new_list = [str(i) for i in my_list]
print(new_list)

# 方法二
my_list = [1, 2, 3, 4, 5]
new_list = list(map(str, my_list))  # map函数返回一个迭代器
print(new_list)