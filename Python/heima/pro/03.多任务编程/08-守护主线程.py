import threading
import time


def show_num():

    for i in range(5):
        print(i)
        time.sleep(1)


if __name__ == '__main__':

    # 守护主进程1
    show_num_thread = threading.Thread(target=show_num, daemon=True)
    # 守护主进程2
    # show_num_thread.setDaemon(True)
    show_num_thread.start()

    time.sleep(2)
    print('over')
    # 主线程结束

'''
守护主进程:主进程退出后子进程销毁
1> (,daemon=True)
2> Thread.setDaemon
'''