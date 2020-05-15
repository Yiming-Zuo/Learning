import threading
import time


def task():
    """任务"""
    # 获取当前线程名称
    time.sleep(1)
    print(threading.current_thread().name)


if __name__ == '__main__':
    # 创建线程列表
    list_thread = []
    for i in range(10):
        task_thread = threading.Thread(target=task)
        list_thread.append(task_thread)

    # 近似于同时执行start
    for value in list_thread:
        value.start()

''''
小结：
1> 线程之间执行是无序的，它是由cpu调度决定的 ，cpu调度哪个线程，哪个线程就先执行，没有调度的线程不能执行。
2> 进程之间执行也是无序的，它是由操作系统调度决定的，操作系统调度哪个进程，哪个进程就先执行，没有调度的进程不能执行。
'''