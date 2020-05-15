import multiprocessing
import time


def task():
    for i in range(5):
        print('任务中...')
        time.sleep(1)


if __name__ == '__main__':
    task_process = multiprocessing.Process(target=task, daemon=True)
    # 设置守护主进程,主进程退出子进程直接摧毁，子进程的生命周期依赖于主进程
    # task_process.daemon = True

    task_process.start()

    # 主程序结束
    time.sleep(3)
    # 设置子进程销毁
    # task_process.terminate()
    print('over')

'''
小结：
    默认：主进程会等待所有子进程执行完成后再退出
    主进程不等待子进程操作：
        1> 主进程结束后设置子进程销毁
        2> 设置守护主进程，主进程结束子进程直接销毁，子进程的生命周期依赖于主进程
'''