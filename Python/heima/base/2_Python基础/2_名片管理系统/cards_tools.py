# -*- coding: utf-8 -*-

# 所有名片记录的列表
cards_list = []


def show_menu():
    """显示菜单"""
    print('*' * 50)
    print('欢迎使用【名片管理系统】V1.0')
    print('')
    print('1.新建名片\n'
          '2.显示全部\n'
          '3.查询名片\n'
          '\n'
          '0.退出系统')
    print('*' * 50)


def new_card():
    """新建名片"""
    print('-' * 50)
    print('功能：新建名片')

    # 提示用户输入名片信息
    name_card = input('请输入姓名：')
    phone_card = input('请输入电话：')
    qq_card = input('请输入QQ号码：')
    email_card = input('请输入邮箱地址：')

    # 将用户信息保存到一个字典
    card_dict = {'name': name_card,
                 'phone': phone_card,
                 'qq': qq_card,
                 'email': email_card}

    # 将用户字典添加到名片列表
    cards_list.append(card_dict)

    print(card_dict)

    # 提示添加成功信息
    # !
    print('成功添加到%s的名片' % card_dict['name'])


def show_all():
    """显示全部"""
    print('-' * 50)
    print('功能：显示全部')

    # 判断是否有名片记录
    if len(cards_list) == 0:
        print('当前暂无名片信息，请选择其他操作')
        # !return之下代码都不执行，返回调用函数的位置
        return

    print('姓名\t\t电话\t\tQQ\t\t邮箱\t\t')
    print('=' * 50)
    for card_dict in cards_list:
        # !
        print('%s\t\t%s\t\t%s\t\t%s\t\t' % (card_dict['name'],
                                            card_dict['phone'],
                                            card_dict['qq'],
                                            card_dict['email']))
        print('-' * 50)


def search_card():
    """搜索名片"""
    print('-' * 50)
    print('功能：搜索名片')

    # 1.输入要搜索的姓名
    find_name = input('请输入您要查找的姓名：')

    # 2.遍历字典
    for card_dict in cards_list:
        if card_dict['name'] == find_name:
            print('姓名：%s 电话：%s QQ:%s 邮箱:%s' % (card_dict['name'],
                                               card_dict['phone'],
                                               card_dict['qq'],
                                               card_dict['email']))
            print('-' * 50)
            # 对搜索到的名片进行下一步操作
            deal_card(card_dict)

            break
    # !
    else:
        # !
        print('木有找到%s' % find_name)


def deal_card(find_dict):
    """
    操作搜索到的名片
    :param find_dict:名片字典
    """

    action_deal = int(input('请输入对名片的操作：1.修改 2.删除 0.返回上级菜单'))

    if action_deal == 1:
        find_dict['name'] = card_input(find_dict['name'], '请输入新的姓名（回车不修改）')
        find_dict['phone'] = card_input(find_dict['phone'], '请输入新的电话号码（回车不修改）')
        find_dict['qq'] = card_input(find_dict['name'], '请输入新的qq号码（回车不修改）')
        find_dict['email'] = card_input(find_dict['name'], '请输入新的邮箱地址（回车不修改）')

        print('%s名片修改成功！' % find_dict['name'])

    elif action_deal == 2:
        cards_list.remove(find_dict)

        print('删除名片成功！')

    else:
        pass


def card_input(dict_value, tip_message):
    """修改名片信息
    1　提示用户输入内容
    2　针对用户的输入进行判断：
        1.1　如果用户输入了内容，直接返回结果
        1.2　如果用户没有输入内容，返回字典中原有的值
    """

    # 输入要修改的信息
    user_input = input(tip_message)

    if len(user_input) > 0:
        return user_input
    else:
        return dict_value
