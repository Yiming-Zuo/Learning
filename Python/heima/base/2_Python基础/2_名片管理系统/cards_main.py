#! /home/b406/anaconda3/bin/python
# -*- coding: utf-8 -*-

import cards_tools

# !无限循环保证用户能够重复选择操作
while True:
    cards_tools.show_menu()

    # !不使用int转换：避免用户输入不是数字程序出错
    action = input('请选择操作功能：')

    print('您的操作是：【%s】' % action)

    # 根据用户的输入决定后续的操作
    if action in ['1', '2', '3']:
        if action == '1':
            cards_tools.new_card()
        if action == '2':
            cards_tools.show_all()
        if action == '3':
            cards_tools.search_card()
    elif action == '0':
        print('欢迎再次使用【名片管理系统】')
        break
    else:
        print('输入有误，请重新输入')
