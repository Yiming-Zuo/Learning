---
title: python_数字列表转字符串列表
date: 2020-06-08
categories: Python
---

* 方法一：x for x in x

```python
my_list = [1, 2, 3, 4, 5]
new_list = [str(i) for i in my_list]
print(new_list)
```

* 方法二:map函数

```python
my_list = [1, 2, 3, 4, 5]
new_list = list(map(str, my_list))  # map函数返回一个迭代器
print(new_list)
```