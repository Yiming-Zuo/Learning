class Game(object):
    """游戏类"""

    # 类属性：游戏历史最高记录分，初始为０
    top_score = 0

    @classmethod
    def show_top_score(cls):
        """类方法：显示历史最高分"""
        print('历史最高分:%s' % cls.top_score)

    @staticmethod
    def show_help():
        """静态方法：显示游戏帮助信息"""
        print('游戏帮助手册')

    def __init__(self, play_name):
        """

        :param play_name:玩家姓名
        """
        self.player_name = play_name

    def start_game(self):
        """开始游戏"""
        print('%s开始游戏' % self.player_name)
        # 更新历史最高分（调用类属性）
        Game.top_score = 999


# 1 查看游戏帮助(静态方法)
Game.show_help()

# 2 查看历史最高分(类方法)
Game.show_top_score()
# 3 创建实例，开始游戏
game = Game('小明')

# 4 开始游戏(实例方法)
game.start_game()

# 5 再次查看游戏最高分
Game.show_top_score()
