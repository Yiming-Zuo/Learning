class HouseItem(object):
    """家具类"""

    def __init__(self, name, area):
        # 家具名称
        self.name = name
        # 家具占的面积
        self.area = area

    def __str__(self):
        """输出对象时显示的信息"""
        return '家具名称:%s 占用面积:%s平米' % (self.name, self.area)


class House(object):
    """房类"""

    def __init__(self, house_type, area):
        """

        :param house_type: 房型
        :param area: 总面积
        """
        self.house_type = house_type
        self.area = area

        # 剩余面积，默认为总面积
        self.free_area = area
        # 家具列表，默认为空
        self.item_list = []

    def __str__(self):
        """输出对象时显示的信息"""
        return '户型:%s 总面积:%.2f平米 剩余面积:%.2f平米 家具列表:%s' % \
               (self.house_type,
                self.area,
                self.free_area,
                self.item_list)

    def add_item(self, item):
        """添加家具

        :param item:对象（一个对象的属性可以使另一个类创建的对象）
        """
        print('开始添加%s家具' % item.name)
        # 判断家具面积是否大于剩余面积
        if item.area > self.free_area:
            print('空间不足')

            return
        # 家具名称追加到家具列表
        self.item_list.append(item.name)
        # 计算剩余面积
        self.free_area -= item.area

        print('添加成功')


# 创建家具
bed = HouseItem('席梦思', 4)
chest = HouseItem('衣柜', 2)
table = HouseItem('餐桌', 1.5)

# 创建户型
home_1 = House('两室一厅', 100)

print(home_1)

home_1.add_item(bed)
home_1.add_item(chest)
home_1.add_item(table)

print(home_1.item_list)
print(home_1)
