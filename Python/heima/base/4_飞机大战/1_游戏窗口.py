"""
1. 游戏的初始化和退出
  1> pygame.init()
  2> 游戏代码
  3> pygame.quit()
2. 描绘矩形区域 pygame.Rect(x,y,size)
3. 创建游戏主窗口 sceen = pygame.display.set_mode((x,y))
4. 游戏循环
5. 绘制图像
  1> 加载图像 bg = pygame.image.load('')
  2> 绘制图像 sceen.blit(x,y)
  3> 更新屏幕 pygame.display.update()
"""

import pygame

# 初始化所有pygame模块
pygame.init()

# 创建游戏主窗口 480*700
sceen = pygame.display.set_mode((480, 700))


# 绘制背景图像
# 加载图像
bg = pygame.image.load('./images/background.png')

# ! 绘制图像
sceen.blit(bg, (0, 0))

# 更新屏幕
# pygame.display.update()


# 绘制英雄图像
hero = pygame.image.load('./images/me1.png')
sceen.blit(hero, (200, 500))

# 统一更新屏幕
pygame.display.update()


# 游戏循环
while True:
    pass

# 卸载所有pygame模块
pygame.quit()


# 描述矩形区域 pygame.Rect

hero_rect = pygame.Rect(100, 500, 120, 126)

# 输出英雄尺寸
print('英雄的尺寸：%d %d' % hero_rect.size)
