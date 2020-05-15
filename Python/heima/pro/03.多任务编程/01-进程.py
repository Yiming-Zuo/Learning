import multiprocessing
import time
import os


def dance(count):
    """跳舞任务"""
    # 获取当前进程
    print('current_process:', multiprocessing.current_process())
    # 获取当前进程编号
    print('current_pid:', os.getpid())
    # 获取当前进程父进程编号
    print('current_ppid:', os.getppid())

    for i in range(count):
        print('跳舞中...')
        # 延时
        time.sleep(2)
        # 杀死进程（根据pid）
        # 9-SIGKILL 信息编号
        os.kill(os.getpid(), 9)


def sing(count):
    """唱歌任务"""
    print('current_process:', multiprocessing.current_process())
    print('current_pid:', os.getpid())
    print('current_ppid:', os.getppid())

    for i in range(count):
        print('唱歌中...')
        time.sleep(2)
    else:
        print('任务结束')


# 判断是否为主模块
if __name__ == '__main__':
    # 获取当前进程(主进程)对象
    print('main_process:', multiprocessing.current_process())
    # 获取主进程编号
    print('main_pid:', os.getpid())
    print('-' * 50)

    # 2. 创建子进程对象
    # Process(group=None,target=目标任务名,name=进程名,arges=以元组形式传参,kwargs=以字典方式传参)
    dance_process = multiprocessing.Process(target=dance, name='dance_process', args=(4,))
    sing_process = multiprocessing.Process(target=sing, name='sing_process2', kwargs={'count': 4})
    # sing_process = multiprocessing.Process(target=sing(2))
    # 相当于在主进程运行song(2),返回值None传入target

    # 获取子进程对象
    print('dance_process:', dance_process)
    print('sing_process:', sing_process)
    print('-' * 50)

    # 3 启动进程执行对应的任务
    dance_process.start()
    sing_process.start()

"""
小结：
    1. 创建子进程对象
    2. 子进程启动
    操作系统调度进程交由CPU去执行
    CPU调度进程中的线程去执行代码
"""