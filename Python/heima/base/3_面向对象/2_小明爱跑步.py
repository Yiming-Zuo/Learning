class Peron(object):
    """人类"""

    def __init__(self, name, weight):
        """

        :param name:名字
        :param weight: 体重
        """
        self.name = name
        self.weight = weight

    def __str__(self):
        """输出对象时显示的信息"""
        return '大家好，我叫%s，%.2f公斤' % (self.name, self.weight)

    def run(self):
        """跑步"""
        # 跑步使体重减少
        self.weight -= 0.5

    def eat(self):
        """吃东西"""
        # 吃东西使体重增加
        self.weight += 1


xm = Peron('小明', 75)

print(xm)

xm.run()
xm.eat()

print(xm)
