# 分而治之：
# 1.找出简单的基准条件（数组：sizo为0或1）
# 2.确定如果缩小问题的规模，直到其符合基线标准

# 求和函数
def my_sum(list):
	if len(list) == 0:  # 1
		return 0
	sum = list.pop(0) + my_sum(list) # 2
	return sum

my_list = [1, 2, 3, 4, 5]
print(my_sum(my_list))

# 求列表size
def get_list_size(list):
	if list == []:
		return 0
	return 1+get_list_size(list[1:])

my_list = [1, 2, 3, 4, 5]
print(get_list_size(my_list))

# 求列表元素最大值
def get_list_max(list):
	if len(list) == 2:
		return list[0] if list[0]>list[1] else list [1]  # 分解成2个元素比较的规模
	return list[0] if list[0] > get_list_max(list[1:]) else get_list_max(list[1:])
	
my_list = [1, 2, 3, 4, 5]
print(get_list_max(my_list))

# 二分法
def binary_search(list, item):
	low = 0
	high = len(list) - 1
	
	while low <= high:
		mid = (low + high) // 2
		guess = list[mid]
		if guess == item:  # 基线条件
			return mid
		elif guess > item:
			high = mid - 1  # 缩小规模
		else:
			low = mid +1  # 缩小规模
	return None
