# 狄克斯特拉算法：计算加权图中的最短路径
# 如果有负权边(贝尔曼-福德算法)，则无法使用狄克斯特拉算法，因为结点一旦被处理，就意味着没有前往该结点的更便宜的途径
# 广度优先搜索：计算非加权有向无环图中的最短路径
# 1.找到开销最小的结点
# 2.更新经过该结点前往各个邻居的开销
# 3.重复1、2知道所有结点都被处理
# 4.计算最短路径

# 图的散列表
graph = {}
graph["start"] = {}
graph["start"]["a"] = 6
graph["start"]["b"] = 2

graph["a"] = {"fin" : 1}
graph["b"] = {"a" : 3, "fin" : 5}
graph["fin"] = {}

#print(graph)
# 前往每个结点的开销的散列表
infinity = float("inf")  # 无穷大
costs = {"a" : 6, "b" : 2, "fin" : infinity}
# 存储父节点的散列表
parents = {"a" : "start", "b" : "start", "fin" : None}
# 处理过的结点
processed = []

# 找到当前开销最小的结点
def find_lowest_cost_node(costs):
	lowest_cost = float("inf")
	lowest_cost_node = None
	for key, value in costs.items():  # 遍历所有结点
		if value < lowest_cost and key not in processed:
			lowest_cost = value
			lowest_cost_node = key
	return lowest_cost_node

def search(graph):
	lowest_cost_node = find_lowest_cost_node(costs)  # 找到开销最小的结点
	while lowest_cost_node is not None:  # 在所有结点都被处理后结束
		for key, value in graph[lowest_cost_node].items():  # 遍历结点所有的邻居
			if costs[lowest_cost_node] + value < costs[key]:  # 如果经过此结点前往该邻居更近(当前结点的开销+前往该邻居的开销>此邻居当前的开销)
				costs[key] = costs[lowest_cost_node] + value  # 更新该邻居的开销
				parents[key] = lowest_cost_node  # 将该邻居的父结点设置为当前结点
		processed.append(lowest_cost_node)  # 标记当前结点已经被处理过
		lowest_cost_node = find_lowest_cost_node(costs)  # 处理下一个结点
		
def search2(graph):
	node = find_lowest_cost_node(costs)
	while node is not None:
		cost = costs[node]
		neighbers = graph[node]
		for key, value in neighbers.items():
			new_cost = cost + value
			if new_cost < costs[key]:
				costs[key] = new_cost
				parents[key] = node
		processed.append(node)
		node = find_lowest_cost_node(costs)

search(graph)
print(costs)
print(parents)

search2(graph)
print(costs)
print(parents)

