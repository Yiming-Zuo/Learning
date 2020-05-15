import multiprocessing
import time

# 定义全局变量
# 相当于g_list = []
g_list = list()


def add_list():
    """往全局变量中添加数据"""
    for i in range(5):
        g_list.append(i)
        print('add:', g_list)
        time.sleep(1)


def read_list():
    """读取全局变量"""
    print('read:', g_list)


if __name__ == '__main__':

    add_list_process = multiprocessing.Process(target=add_list)
    read_list_process = multiprocessing.Process(target=read_list)

    add_list_process.start()
    # 进程等待
    add_list_process.join()
    read_list_process.start()

    print('main:', g_list)


"""
小结：
    进程之间不共享全局变量
    创建子进程会将主进程资源拷贝给各子进程，各子进程独立操作自己的全局变量
"""