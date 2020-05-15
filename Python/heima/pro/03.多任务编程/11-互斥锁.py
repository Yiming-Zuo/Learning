import threading

g_num = 0

# 创建锁
lock = threading.Lock()


def sum_num1():
    # 上锁
    lock.acquire()

    global g_num

    for i in range(1000000):
        g_num += 1
        # time.sleep(0.001)

    print(1, g_num)

    # 释放锁
    lock.release()


def sum_num2():

    lock.acquire()

    global g_num

    for i in range(1000000):
        g_num += 1

    print(2, g_num)

    lock.release()


if __name__ == '__main__':

    sum_num1_thread = threading.Thread(target=sum_num1)
    sum_num2_thread = threading.Thread(target=sum_num2)

    sum_num1_thread.start()
    # 线程同步1
    # sum_num1_thread.join()
    sum_num2_thread.start()

"""
小结：
互斥锁acquire和release方法之间的代码同一时间只有一个线程可以操作，并锁定其中的全局变量。
执行代码的效率会下降，但能保证数据的安全性。
互斥锁使用不当会出现死锁的情况
"""