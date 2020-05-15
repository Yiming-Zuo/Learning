import threading
import time


def dance(count):
    """跳舞任务"""
    # 获取当前线程
    print('current_thread:', threading.current_thread().name)

    for i in range(count):
        print('跳舞中...%d' % i)
        time.sleep(1)


def sing(count):
    """唱歌任务"""
    print('current_thread:', threading.current_thread().name)

    for i in range(count):
        print('唱歌中...%d' % i)
        time.sleep(1)


if __name__ == '__main__':
    print('main_thread:', threading.current_thread().name)
    print('-' * 50)

    # 创建子线程对象
    dance_thread = threading.Thread(target=dance, name='dance_thread', args=(3,))
    sing_thread = threading.Thread(target=sing, name='sing_thread', kwargs={'count': 3})

    # 输出子线程状态
    print(dance_thread)
    print(sing_thread)

    # 启动子进程
    dance_thread.start()
    sing_thread.start()

'''
小结：
    1. 创建子进程对象
    2. 启动子进程
'''