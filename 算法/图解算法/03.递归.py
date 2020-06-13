# 倒计时
def countdown(i):
	if i < 0:  # 基线条件
		return
	print(i)
	countdown(i-1)  # 递归条件
	
countdown(10)


# 阶乘
def factorial(num):
	if num == 1:
		return 1
	return num * factorial(num-1)
	
print(factorial(5))
# 调用栈如果很长，会占用大量的内存空间，造成栈溢出