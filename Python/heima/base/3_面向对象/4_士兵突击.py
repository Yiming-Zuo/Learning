class Solder(object):
    """士兵类"""
    def __init__(self, name):
        """

        :param name: 名字
        """
        self.name = name
        # 武器列表，初试为空
        self.gun_list = []

    def get_gun(self, gun):
        """获取武器

        :param gun: 武器对象
        """
        # self.gun = gun
        # 将武器添加到武器列表
        self.gun_list.append(gun)

        print('成功装备%s' % gun.model)

    def change_gun(self):
        """切换武器"""
        # 判断武器是否只有1个
        if len(self.gun_list) == 1:
            print('只有一个武器')

            return
        # 交换两把武器在列表中的位置
        self.gun_list[0], self.gun_list[-1] = self.gun_list[-1], self.gun_list[0]

        print('成功将%s切换为%s' % (self.gun_list[0].model, self.gun_list[-1].model))

    def add_bullet(self):
        """换弹匣"""
        # 更换当前武器的弹匣
        self.gun_list[-1].add_bullet()

    def fire(self):
        """开火"""
        # 判断是否有装备（if True:/if False:）
        if not self.gun_list:
            print('打扰了~')

            return
        # 射击
        print('冲冲冲！！！')
        self.gun_list[-1].shoot()


class Gun(object):
    """枪类"""
    def __init__(self, model):
        """

        :param model:型号
        """
        self.model = model
        # 剩余子弹数量，初始为0
        self.bullet_count = 0

    def add_bullet(self):
        """更换弹匣"""
        # 更换弹匣后子弹数量为20
        self.bullet_count = 20

        print('%s换弹成功' % self.model)

    def shoot(self):
        """射击"""
        # 判断是否还有子弹
        if self.bullet_count <= 0:
            print('%s没有子弹了囧' % self.model)
            return
        # biubiubiu，子弹数量-1
        self.bullet_count -= 1
        print('biubiubiu~ 【%s剩余子弹:%d】' % (self.model, self.bullet_count))


# 创建武器
AK47 = Gun('ak47')
M4A1 = Gun('m4a1')
# 创建士兵
xsd = Solder('许三多')
# 装备武器
xsd.get_gun(AK47)
xsd.get_gun(M4A1)
# 装备弹匣
xsd.add_bullet()
# 哒哒哒
xsd.fire()
xsd.fire()
xsd.fire()
xsd.fire()
# 更换武器
xsd.change_gun()
# 装备弹匣
xsd.add_bullet()
# 哒哒哒
xsd.fire()
xsd.fire()
xsd.fire()
# 更换武器
xsd.change_gun()
# 哒哒哒
xsd.fire()
xsd.fire()
xsd.fire()
# 更换弹夹
xsd.add_bullet()
# 哒哒哒
xsd.fire()
