import demo_1 as DogModule
from demo_2 import Cat as C
import message

print(DogModule.demo_11)
# print(demo_2.demo_21)

DogModule.demo_12()
# demo_2.demo_22()

dog = DogModule.Dog()
cat = C()
print(dog,cat)

# 输出导入模块的保存路径
print(DogModule.__file__)

# 调用包中的模块
message.send_message.send('您好')
text = message.receive_message.receive()
print(text)
