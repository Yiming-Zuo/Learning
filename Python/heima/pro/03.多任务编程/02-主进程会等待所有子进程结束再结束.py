import multiprocessing
import time


def show_num():
    for i in range(5):
        print(i)
        time.sleep(1)


if __name__ == '__main__':
    show_num_process = multiprocessing.Process(target=show_num)
    show_num_process.start()

    # 主线程结束
    time.sleep(2)
    print('over')


'''
小结：
    主进程会等待所有的子线程执行结束后再结束
'''