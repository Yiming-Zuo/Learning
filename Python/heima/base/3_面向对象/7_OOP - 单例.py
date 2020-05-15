# 1 __new__方法
# 2 单例
# 3 只执行一次初始化工作


class MusicPlayer(object):

    # 记录单例对象引用
    instance = None
    # 标记是否执行过初始化动作
    init_flag = False

    def __new__(cls, *args, **kwargs):
        """重写__new__方法
        0 创建对象时，自动引用
        1 为对象分配空间
        2 返回对象引用
        """
        # 扩展方法
        print('创建对象，记录结果')

        # 判断类属性是否已经被赋值
        if cls.instance is None:
            # 调用父类__new__方法，使用类属性instance记录单例对象的引用,为第一个对象分配空间
            # __new__是一个静态方法，调用时需主动传递cls参数
            cls.instance = super().__new__(cls)

        # 2 将记录的类属性的对象引用返回解释器
        return cls.instance

    def __init__(self):

        # 判断是否执行过初始化动作
        if not MusicPlayer.init_flag:
            print('音乐播放器初始化')

            # 记录已经执行过初始化动作
            MusicPlayer.init_flag = True


# 创建实例1
player_1 = MusicPlayer()
# 查看实例1被分配的空间
print(player_1)

# 创建实例2
player_1 = MusicPlayer()
# 查看实例2被分配的空间
print(player_1)
