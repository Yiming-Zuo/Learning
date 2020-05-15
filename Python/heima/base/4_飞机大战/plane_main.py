"""
plane_main
1. 封装主游戏类 PlaneGame
  1> 游戏初始化 __init__
    1>> 创建游戏窗口
    2>> 创建游戏时钟
    3>> 调用（私有）方法，创建精灵和精灵组
  2> 游戏循环
    1>> 设置帧率
    2>> 事件监听（私有）
    3>> 碰撞检测（私有）
    4>> 更新精灵组（私有）
    5>> 更新显示
2. 创建游戏对象
3. 启动游戏
plane_sprites
1. 常量
  1> 窗口大小常量
  2> 帧率常量
2. 游戏精灵子类
"""

import pygame
from plane_sprites import *


class PlaneGame(object):
    """主游戏"""

    def __init__(self):
        print('游戏初始化...')

        # 1. 创建游戏窗口
        self.sceen = pygame.display.set_mode(SCEEN_RECT.size)

        # 2. 创建游戏时钟
        self.clock = pygame.time.Clock()

        # 3. 调用私有方法，创建精灵和精灵组
        self.__create_sprites()

        # 4. 设置定时器事件（创建敌机）
        pygame.time.set_timer(CREATE_ENEMY_EVENT, 1000)

        # 5. 设置定时器事件（发射子弹）
        pygame.time.set_timer(HERO_FIRE_EVENT, 500)

    def __create_sprites(self):
        """创建精灵和精灵组
        根据职责封装私有方法
        """

        # 创建英雄精灵
        # 定义单独英雄对象，后续做碰撞检测以及发射子弹
        self.hero = Hero()
        self.hero_group = pygame.sprite.Group(self.hero)

        # 创建背景精灵
        bg1 = Backgroud()
        bg2 = Backgroud(is_alt=True)

        # 创建背景精灵组
        self.backgroud = pygame.sprite.Group(bg1, bg2)

        # 创建敌机精灵组(定时创建，初始化时不需要创建敌机)
        self.enemy = pygame.sprite.Group()



    def __event_handler(self):
        """事件监听"""

        for event in pygame.event.get():
            # 判断是否退出游戏
            if event.type == pygame.QUIT:
                # ! 调用静态方法
                PlaneGame.__game_over()

            # 监听敌机出现事件
            elif event.type == CREATE_ENEMY_EVENT:
                # 创建敌机精灵
                enemy = Enemy()

                # 将精灵添加到精灵组
                self.enemy.add(enemy)

            # 监听发射子弹事件
            elif event.type == HERO_FIRE_EVENT:
                self.hero.fire()

            # 向右走
            elif event.type == pygame.KEYDOWN and event.key == pygame.K_RIGHT:
                self.hero.update()

            # 向左走
            elif event.type == pygame.KEYDOWN and event.key == pygame.K_LEFT:
                self.hero.update(a=2)

            # 向上飞
            elif event.type == pygame.KEYDOWN and event.key == pygame.K_UP:
                self.hero.update(a=3)

            # 向下飞
            elif event.type == pygame.KEYDOWN and event.key == pygame.K_DOWN:
                self.hero.update(a=4)

    def __check_collide(self):
        """碰撞检测"""
        pygame.sprite.groupcollide(self.hero.bullets, self.enemy, True, True)
        enemis = pygame.sprite.spritecollide(self.hero, self.enemy, True)

        if len(enemis) > 0:
            PlaneGame.__game_over()

    def __update_sprites(self):
        """更新精灵组"""

        # 在sceen上绘制组内所有精灵
        self.backgroud.draw(self.sceen)
        # 让组内所有精灵调用update方法
        self.backgroud.update()

        # self.hero_group.update()
        self.hero_group.draw(self.sceen)

        self.enemy.draw(self.sceen)
        self.enemy.update()

        self.hero.bullets.draw(self.sceen)
        self.hero.bullets.update()


    @staticmethod
    def __game_over():
        """结束游戏"""
        print('游戏结束...')

        pygame.quit()
        exit()

    def start_game(self):
        """开始游戏"""
        print('游戏开始...')

        while True:
            # 1. 设置帧率
            self.clock.tick(FRAME_PER_SEC)

            # 2. 事件监听
            self.__event_handler()

            # 3. 碰撞检测
            self.__check_collide()

            # 4. 更新精灵组
            self.__update_sprites()

            # 5. 更新屏幕显示
            pygame.display.update()


if __name__ == '__main__':
    # 创建游戏对象
    game = PlaneGame()
    # 启动游戏
    game.start_game()
