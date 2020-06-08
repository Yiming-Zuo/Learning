# 用法一：将lambda函数赋值给一个变量，通过这个变量间接调用该lambda函数
my_add = lambda x,y : x+y
print(my_add(4, 6))

# 用法二：将lambda函数赋值给其他函数，从而将其他函数用该lambda函数替换。
#sum = lambda x,y:None
#print(sum(1, 3))

# 用法三：将lambda函数作为其他函数的返回值，返回给函数调用者
def my_sub():
	return lambda x,y : x-y
print(my_sub()(4, 1))

# 用法四：将lambda函数作为参数传递给其他函数
# 1 filter(function, iterable):过滤序列
my_list = list(filter(lambda x : x>3, [1,2,3,4,5]))
print(my_list)

# 2 sorted(iterable, key=None, reverse=False):排序函数
my_list = [ [4,2], [1,5], [2,6]]
new_list = sorted(my_list, key=lambda x:x[-1]*-1)  # x:列表中的每个元素
print(new_list)

# 3 map(function, iterable, ...):映射函数
my_list = [ [4,2], [1,5], [2,6]]
new_list = list(map(lambda x : sum(x), my_list))
print(new_list)

# 4 reduce(function, iterable[, initializer]):对序列中的元素进行累计
from functools import reduce
my_list = [3, 4, 5, 6]
value = reduce(lambda x,y:x+y, my_list)
print(value)

https://blog.csdn.net/zjuxsl/article/details/79437563