# 图算法--广度优先搜索算法，解决最短路径问题的算法
# 步骤：
# 1.使用图建立问题模型(散列表->实现图)，散列表时无序的，因此添加键值对的顺序无关紧要
# 2.使用广度优先搜索解决问题

# 按队列中的添加顺序进行检查
# 一度关系入列 --> 二度关系入列...

# 无向图(双向关系)和有向图

# 避免重复检查和无限循环，要建立一个列表来记录检查过的元素

# 运行时间：O(V+E)
# V:顶点数，将每个人添加到队列 O(V)
# E:边数，沿每条边前行 O(E)

# 拓扑排序
# 用于在特殊的图--树的依赖关系上创建一个有序的列表
from collections import deque

def person_is_seller(name):
	return name[-1] == 'y'

def search(name):
	searched = [name]  # 数组记录检查过的人
	search_queque = deque()  # 创建一个双端队列
	search_queque += graph[name]  # 将name和邻居都加入到队列中
	while search_queque:  # 当队列不为空时
		person = search_queque.popleft()  # 出列
		if person not in searched:  # 如果此人没被检查过，如果检查就进入下一循环，继续出列
			if person_is_seller(person):  # 检查此人
				print(person + " is a seller!")
				return True
			else:
				search_queque += graph[person]  # 如果此人不是，将此人邻居入列
				searched.append(person)  # 将此人标记以检查过
	return False	

graph = {}
graph["you"] = ["bob", "claire", "alice"]
graph["bob"] = ["anuj", "peggy"]
graph["claire"] = ["thom", "jonny", "you"]
graph["alice"] = ["peggy"]
graph["anuj"] = []
graph["peggy"] = []
graph["thom"] = []
graph["jonny"] = []

search("you")