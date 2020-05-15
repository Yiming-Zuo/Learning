"""精灵（pygame.sprite.Sprite派生子类）
封装精灵的image、rect和speed，提供update方法
1. 初始化属性 __init__
  0> 调用父类初始化方法 super().__init__()
  1> image-加载图像 pygame.image.load('')
  2> rect-初始化图像位置 image.get_rect()返回pygame.Rect()
  3> speed-图像移动速度
2. 更新位置 update-rect.x/y
"""

import random
import pygame

# 屏幕大小的常量
SCEEN_RECT = pygame.Rect(0, 0, 480, 700)

# 刷新帧率
FRAME_PER_SEC = 144

# 定时器常量（创建敌机）
CREATE_ENEMY_EVENT = pygame.USEREVENT
HERO_FIRE_EVENT = pygame.USEREVENT + 1


class GameSprite(pygame.sprite.Sprite):
    """飞机大战游戏精灵"""

    def __init__(self, image_name, speed=1):

        # 调用父类的初始化方法
        super().__init__()

        # 定义对象属性
        # 加载图像
        self.image = pygame.image.load(image_name)
        # 初始化图像位置
        self.rect = self.image.get_rect()
        # 精灵速度
        self.speed = speed

    def update(self):
        """更新精灵位置"""

        # 精灵向屏幕上方移动
        self.rect.y += self.speed


class Hero(GameSprite):

    def __init__(self):

        # 调用父类方法
        super().__init__('./images/me1.png', 5)

        self.rect.centerx = SCEEN_RECT.centerx
        self.rect.bottom = SCEEN_RECT.bottom - 120

        # 创建子弹精灵组
        self.bullets = pygame.sprite.Group()

    def update(self, a=1):

        # 向右飞
        if a == 1:
            self.rect.x += self.speed
        # 向左飞
        if a == 2:
            self.rect.x -= self.speed
        # 向上飞
        if a == 3:
            self.rect.y -= self.speed
        # 向下飞
        if a == 4:
            self.rect.y += self.speed

        # 判断飞机是否超出屏幕边界
        if self.rect.y < 0:
            self.rect.y = 0

        if self.rect.bottom > SCEEN_RECT.bottom:
            self.rect.bottom = SCEEN_RECT.bottom

        if self.rect.left < 0:
            self.rect.left = 0

        if self.rect.right > SCEEN_RECT.right:
            self.rect.right = SCEEN_RECT.right

    def fire(self):

        for i in (1, 2, 3):
            # 创建子弹精灵
            bullet = Bullet()
            # 设置精灵位置
            bullet.rect.bottom = self.rect.y - i * 20
            bullet.rect.centerx = self.rect.centerx
            # 创建子弹精灵组
            self.bullets.add(bullet)


class Enemy(GameSprite):
    """敌机精灵类"""

    def __init__(self):

        # 调用父类方法
        super().__init__('./images/enemy1.png')

        # 指定敌机初始随机速度
        self.speed = random.randint(2, 4)

        # 指定敌机初始随机位置
        self.rect.bottom = 0

        max_x = SCEEN_RECT.width-self.rect.width
        self.rect.x = random.randint(0, max_x)

    def update(self):

        # 调用父类方法
        super().update()

        # 判断是否飞出屏幕
        if self.rect.y >= SCEEN_RECT.height:
            # 将精灵从所有精灵组中移出，然后被自动销毁
            self.kill()

    def __del__(self):
        """重写__del__方法，在对象被销毁前调用，判断对象是否销毁"""
        print('敌机挂了%s' % self.rect)


class Bullet(GameSprite):

    def __init__(self):

        # 调用父类方法
        super().__init__('./images/bullet1.png', -2)

        self.rect.centerx = SCEEN_RECT.centerx
        self.rect.centery = SCEEN_RECT.centery

    def update(self):

        # 调用父类方法
        super().update()

        # 判断是否飞出屏幕
        if self.rect.bottom < 0:
            # 将精灵从所有精灵组中移出，然后被自动销毁
            self.kill()


class Backgroud(GameSprite):
    """游戏背景精灵
    1. 父类提供的方法不能满足子类的需求 ==》 派生子类，扩展方法
    2. 将对象的职责尽量封装到类的代码内部，尽量简化程序调用一方的代码调用
    """

    def __init__(self, is_alt=False):

        # 调用父类方法创建背景精灵
        super().__init__('./images/background.png')

    # 判断是否是交替图像
        if is_alt:
            self.rect.y = -self.rect.height

    def update(self):

        # 调用父类方法
        super().update()

        # 判断是否移出屏幕
        if self.rect.y >= SCEEN_RECT.height:
            self.rect.y = -SCEEN_RECT.height
