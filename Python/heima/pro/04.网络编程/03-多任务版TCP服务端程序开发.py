import socket
import threading


def handle_client_request(new_socket0, ip0):
    """处理客户端请求函数"""
    # 循环接受客户端发送的数据
    while True:

        recv_data = new_socket0.recv(1024)

        if recv_data:
            recv_content = recv_data.decode('utf-8')
            print('[服务端]接受到内容：', recv_content, '来自:', ip0)

            # send_content = input('[服务端]请输入要发送的内容：')
            send_content = '收到'
            send_date = send_content.encode('utf-8')
            new_socket0.send(send_date)

        else:
            print('[服务端]下线了', ip0)
            break

    new_socket0.close()


if __name__ == '__main__':

    # 1. 创建服务端套接字对象
    tcp_server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # 设置端口号服用
    tcp_server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)
    # 2. 绑定端口号
    tcp_server_socket.bind(('', 9090))
    # 3. 设置监听
    tcp_server_socket.listen(128)

    # 循环等待接受客户端的连接请求
    while True:
        # 4. 等待接受客户端连接请求
        new_socket, ip = tcp_server_socket.accept()
        print('[服务端]已接受连接：', ip)

        # 创建子线程，专门负责处理客户端请求
        sub_thread = threading.Thread(target=handle_client_request, args=(new_socket, ip))
        # 设置守护主线程，否则客户端不断开，服务端无法关闭
        sub_thread.setDaemon(True)
        sub_thread.start()

    # 服务端程序需要一直运行，所以tcp服务端的套接字不用关闭
    # tcp_server_socket.close()

'''
小结:
    1. 设置监听后循环等待接受客户端的连接请求
    2. 接受客户端的连接请求后创建专门处理客户端请求的子线程，并设置守护主线程
    3. 封装一个处理客户请求的函数（设置循环接收用户发送的数据并回复数据），作为子线程的目标任务
    4. 当客服端断开连接时，服务端的recv会解堵塞，返回的数据长度为0，以此判断是否要关闭通信套接字
'''