print('-------模块被导入时没有缩进的代码会被执行--------')

demo_11 = "模块1全局变量"


def demo_12():
    print('模块1函数')


class Dog(object):
    pass


# 直接执行=__main_
# 被导入=模块名
print(__name__)


# 测试代码
def main():
    print('测试代码')


# 根据__name__判断是否执行下方代码
if __name__ == '__main__':
    main()