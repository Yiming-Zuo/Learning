# 1. 捕获异常
#  1> try...except...else...finally语法
#  2> 捕获错误类型
#   1>> except:
#   2>> except ():
#   3>> except Exception as result:
# 2. 异常传递
# 3. 抛出异常
#  1> 判断
#  2> False抛出异常
#   1>> 创建异常对象
#   2>> 抛出异常


def input_password():
    """输入密码"""
    # 1. 用户输入密码
    pwd = input('请输入密码')

    # 2. 判断密码长度，>=8返回用户输入的密码
    if len(pwd) >= 8:
        return pwd

    # 3. 长度不够，抛出异常
    # 1> 常见异常对象，参数为异常的错误字符串
    ex = Exception('密码长度错误')
    # 2> 抛出异常
    raise ex


def demo():
    """调用input_password"""
    return input_password()


# 捕获异常
try:
    # 不能确定是否能够正常运行的代码
    demo()
# except ValueError:
#     print('请输入正确的数字')
# except ZeroDivisionError:
#     print("除零错误")
# 捕获位置错误
# except (错误类型1，错误类型2):
#     pass
except Exception as result:
    print('发现错误:%s' % result)
# 没有异常时执行代码
else:
    print('正常执行')
# 有无异常都执行代码
finally:
    print('-' * 50)




