# 单元格中的优化值：两个字符串都包含的最长子串的长度
# 子问题：比较两个字符串的子串
# 坐标轴：两个单词
# 答案：网格中最大的数字

import numpy as np

def dynamic(str1, str2):
	str_index = (0, 0)
	num = 0
	cell = np.zeros((len(str1), len(str2)), dtype=int);
	for i in range(len(str1)):
		for j in range(len(str2)):
			if str1[i] == str2[j]:  # 两个字母相同
				if i==0 or j==0:
					cell[i][j] = 1
				else:
					cell[i][j] = cell[i-1][j-1] + 1
			else:
				cell[i][j] = 0
			if cell[i][j] > num:
				num = cell[i][j]
				str_index = i
	return num 
	
print(dynamic("hish", "fish"))
	

