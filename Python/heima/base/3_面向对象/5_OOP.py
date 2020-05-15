class Animal(object):
    """动物类"""
    def __init__(self, name, age):
        """

        :param name:名字
        :param age: 年龄（私有属性）
        """
        self.name = name
        self.__age = age

    def eat(self):
        """吃饭"""
        print('%s吃吃吃' % self.name)

    def run(self):
        """跑步"""
        print('%s跑跑跑' % self.name)

    def sleep(self):
        """睡觉（内部方法可以访问私有属性）"""
        print('%s%d岁的时候还在睡觉' % (self.name, self.__age))


class Animal_0(object):
    """动物类２"""

    def __init__(self, name, gender, age):
        """

        :param name:姓名
        :param gender: 性别
        :param age: 年龄（私有属性）
        """
        self.name = name
        self.gender = gender
        self.__age = age

    def drink(self):
        """喝水"""
        print('%s喝喝喝' % self.name)


class Dog(Animal):
    """狗类（动物类）"""

    def bark(self):
        """狗叫"""
        print('%s汪汪汪' % self.name)

    def game(self):
        """玩耍"""
        print('%s蹦着玩' % self.name)


class XiaoTianQuan(Animal_0, Dog):
    """哮天犬类（动物类２，动物类）
    继承的顺序，当两个父类的方法名称一样时（避免），子类继承排在前面的父类方法
    """

    def __init__(self, name, gender, age, race):
        """子类方法重写（扩展）"""
        # 使用super(B,self).父类方法(参数)调用父类方法
        super(XiaoTianQuan, self).__init__(name, gender, age)
        self.race = race

    def eat(self):
        """子类方法的重写（覆盖）"""
        print('%s从不吃饭' % self.name)

    def game(self):
        """重写"""
        print('%s飞着玩' % self.name)

    def fly(self):
        print('%s飞飞飞' % self.name)


class Person(object):
    """人类"""

    # 定义类属性(记录类的特征)，记录创建人类对象的总数
    count = 0

    # @classmethod
    # def run():
    #     """不传入参数的类方法不需要cls"""
    #     print('这是一个没有参数的类方法')

    @classmethod
    def show_person_count(cls):
        """类方法"""
        print('这是一个类方法＝＝》一共创建了%d个人类' % cls.count)

    @staticmethod
    def run():
        """静态方法
        不需要访问实例属性也不需要访问类属性的方法"""

        print('这是一个静态方法')

    def __init__(self, name):
        """

        :param name:姓名
        """
        self.name = name

        # 每创建一个实例，类属性+1
        Person.count += 1

    def game_with_dog(self, dog):
        """与狗一起玩耍"""
        print('%s和%s快乐的玩耍' % (self.name, dog.name))
        # 调用传入对象的方法
        dog.game()

    def show(self):
        """实例方法调用类属性"""
        print('%s,%s' % (self.name, Person.count))


# 创建实例（实例化）
xm = Person('小明')
dh = Dog('大黄', 2)
xtq = XiaoTianQuan('哮天犬', '公', 200, '神')

# 类属性(查看使用Person创建了多少对象)
print('使用Person类创建了%d个对象' % Person.count)

# 类方法
# Person.run()nime
Person.show_person_count()
xm.show_person_count()

# 静态方法
Person.run()
xm.run()

# 其中一个父类无法访问另一个父类的私有属性和私有方法
# (Animal中的sleep方法无法调用Animal_0中的__age私有属性)
# xtq.sleep()

# 多态：不同的子类对象调用相同的父类方法产生不同的执行结果（重写）
# dh调用Dog中的game方法，xtq调用XiaoTianQuan中重写的game方法
xm.game_with_dog(dh)
xm.game_with_dog(xtq)

# 搜索类在多继承时方法、属性的调用顺序
print(XiaoTianQuan.__mro__)

# 实例方法调用类属性
xm.show()
