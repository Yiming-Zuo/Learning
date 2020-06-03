# 快速排序 O(n*logn)
# 归纳证明：
# 1.基线条件
# 2.归纳条件

def quickSort(array):
	if len(array) < 2:  # 基线条件
		return array
	pivot = array[0]  # 基准值
	less = [i for i in array[1:] if i <= pivot]  # 分区
	greater = [i for i in array[1:] if i > pivot]  # 分区
	return quickSort(less) + [pivot] + quickSort(greater)

my_list = quickSort([4, 7, 1, 9, 3, 2])
print(my_list)