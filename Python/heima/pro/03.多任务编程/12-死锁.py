import threading

lock = threading.Lock()


# 保证同一时刻只有一个进程根据下标取值
def get_value(index):
    """根据下标取值任务"""
    lock.acquire()

    my_list = [3, 6, 8, 1]

    # 判断下标是否越界
    if index >= len(my_list):
        print('下标越界', index)
        # 下标越界后也需要释放锁，保证后面线程可以再次取值
        # lock.release()
        return

    value = my_list[index]
    print(value)

    lock.release()


if __name__ == '__main__':
    # 模拟大量线程去执行取值操作
    for i in range(30):
        sub_thread = threading.Thread(target=get_value, args=(i,))
        sub_thread.start()
        # 主线程创建子线程后，不会等待子线程执行完后再继续执行，而是接着创建下一个子线程

"""
小结：
    使用互斥锁时应注意在合适的地方要释放锁
"""