import threading
import time

# 定义全局变量
g_list = list()


def write_list():
    """向全局变量中添加数据"""
    for i in range(5):
        g_list.append(i)
        print('write:', g_list)
        time.sleep(1)


def read_list():
    """读取全局变量"""
    print('read:', g_list)


if __name__ == '__main__':
    write_list_thread = threading.Thread(target=write_list)
    read_list_thread = threading.Thread(target=read_list)

    write_list_thread.start()
    # 线程等待
    # write_list_thread.join()
    # 延时
    time.sleep(6)
    read_list_thread.start()

'''
小结：
    线程之间共享全局变量
'''