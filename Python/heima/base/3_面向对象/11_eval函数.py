# 将字符串当成有效的表达式来求值

# 案例：计算器
input_str = input('请输入一个算术题：')

print(eval(input_str))


# 不能滥用（权限太高）
# 输入命令
__import__('os').system('ls')
# 等价于
'''
import os
os.system('终端命令')
'''