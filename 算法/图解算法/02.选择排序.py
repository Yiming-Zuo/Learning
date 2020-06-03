# O(n2)
# 返回最小值的索引
def findSmallest(arr):
	smallest_index = 0
	for i in range(1, len(arr)):
		if arr[i] < arr[smallest_index]:
			smallest_index = i
	return smallest_index

# 每次循环找出最小值添加到新数组中
def selectionSort(arr):
	newArr = []
	for i in range(len(arr)):
		smallest_index = findSmallest(arr)
		newArr.append(arr.pop(smallest_index))
	return newArr

# 每次循环找出最小值，与前面的大值交换
def selectionSort2(arr):
	for i in range(len(arr)):
		smallest_index = i
		for j in range(i+1, len(arr)):
			if arr[smallest_index] > arr[j]:
				smallest_index = j
		if (smallest_index != i):
			temp = arr[i];
			arr[i] = arr[smallest_index];
			arr[smallest_index] = temp;
	return arr;
	
my_list = [5, 3, 6, 2, 10]
print(selectionSort(my_list))
my_list = [5, 3, 6, 2, 10]
print(selectionSort2(my_list))
