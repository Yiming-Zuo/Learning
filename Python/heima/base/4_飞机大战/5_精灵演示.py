"""精灵组
包含多个精灵对象，统一调用update()和draw(screen)方法
from ... import *
0. 创建精灵对象和精灵组的对象 pygame.sprite.Group()
1. update()-精灵组内所有精灵更新位置
2. draw(screen)-将所有精灵绘制到screen上
"""


import pygame
from plane_sprites import *

# 初始化pygame所有模块
pygame.init()

# 创建游戏主窗口
sceen = pygame.display.set_mode((480, 700))

# 加载背景和英雄图像
bg = pygame.image.load('./images/background.png')
hero = pygame.image.load('./images/me1.png')
hero_1 = pygame.image.load('./images/me1.png')

# 定义英雄初始位置
hero_rect = pygame.Rect(200, 500, 102, 126)
# 当英雄移出上屏幕时，定义移出屏幕部分的另一个英雄位置
hero1_rect = pygame.Rect(200, 700, 102, 126)

# 创建精灵对象
enemy_0 = GameSprite('./images/enemy1.png')
enemy_1 = GameSprite('./images/enemy1.png', 5)
enemy_1.rect.x = 200

# 创建精灵组对象
enemy_group = pygame.sprite.Group(enemy_0, enemy_1)


# 游戏时钟
# 创建游戏时钟对象
clock = pygame.time.Clock()

# 游戏循环
while True:
    # 设置屏幕刷新帧率
    clock.tick(144)

    # 事件监听(列表)
    # event = pygame.event.get()
    #
    # # 判断是否有事件
    # if len(event) > 0:
    #     print(event)
    for event in pygame.event.get():
        # 判断用户是否点击了退出按钮
        if event.type == pygame.QUIT:
            print('退出游戏...')

            # 卸载所有pygame模块
            pygame.quit()

            # 直接退出系统
            exit()

    # 绘制背景和英雄图像
    sceen.blit(bg, (0, 0))
    sceen.blit(hero, hero_rect)

    # 更新英雄位置
    hero_rect.y -= 1

    # 创建敌机
    # 精灵组内所有精灵更新位置
    enemy_group.update()

    # 在sceen上绘制组内所有精灵
    enemy_group.draw(sceen)

# 判断英雄位置是否移出上屏幕
    if -126 < hero_rect.y <= 0:
        # 更新移出屏幕部分的另一个英雄位置
        hero1_rect.y = 700 + hero_rect.y
        # 绘制另一个英雄图像
        sceen.blit(hero_1, hero1_rect)

    # 判断英雄是否完全移出上屏幕
    elif hero_rect.y <= -126:
        hero_rect.y = 574

    # 更新显示
    pygame.display.update()
