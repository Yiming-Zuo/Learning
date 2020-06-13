# 两个单词中都有的序列包含的字母数

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
				cell[i][j] = max(cell[i-1][j], cell[i][j-1])  # 如果两个字母不同，值选择上方单元格和左方单元格间最大的值
			if cell[i][j] > num:
				num = cell[i][j]
				str_index = i
	return num 
	
print(dynamic("ahish", "afish"))