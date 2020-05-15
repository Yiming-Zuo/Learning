import threading

g_num = 0


def sum_num1():
    """全局变量累加至1000000"""
    global g_num

    for i in range(1000000):
        # 函数内部出现变量赋值，变量会被认为本地变量，需进行全局变量声明
        # 不可变类型的全局变量需要声明，表示要修改变量的内存地址
        g_num += 1
        # time.sleep(0.001)

    print(1, g_num)


def sum_num2():
    """全局变量累加至1000000"""
    global g_num

    for i in range(1000000):
        g_num += 1

    print(2, g_num)


if __name__ == '__main__':

    sum_num1_thread = threading.Thread(target=sum_num1)
    sum_num2_thread = threading.Thread(target=sum_num2)

    sum_num1_thread.start()
    # 线程同步1
    # sum_num1_thread.join()
    sum_num2_thread.start()

'''
小结：
    错误分析：
        两个线程都要对全局变量g_num(默认是0)进行加1运算，但是由于是多线程同时操作，有可能出现下面情况：
            1> 在g_num=0时，sum1取得g_num=0。此时系统把sum1调度为”sleeping”状态，把sum2转换为”running”状态，t2也获得g_num=0
            2> 然后sum1对得到的值进行加1并赋给g_num，使得g_num=1
            3> 然后系统又把sum2调度为”sleeping”，把sum1转为”running”。线程t1又把它之前得到的0加1后赋值给g_num。
            4> 这样导致虽然first_thread和first_thread都对g_num加1，但结果仍然是g_num=1
            
    全局变量数据错误的解决办法:
        线程同步: 保证同一时刻只能有一个线程去操作全局变量 同步: 就是协同步调，按预定的先后次序进行运行。如:你说完，我再说, 好比现实生活中的对讲机
    
    线程同步的方式:
        1> 线程等待(join)
        2> 互斥锁
'''