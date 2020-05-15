import socket


if __name__ == '__main__':
    # 1. 创建服务端套接字对象
    tcp_server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # 设置端口号服用：程序退出时立即释放端口号
    # SOL_SOCKET:当前套接字
    # SO_REUSEADDR:复用选项
    tcp_server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)

    # 2. 绑定端口号 socket.bind((host,port))
    tcp_server_socket.bind(('', 9090))

    # 3. 设置监听:知道客户端想要连接 socket.listen(backlog)
    # backlog:最大等待建立连接的个数
    # listen后的这个套接字是被动套接字：只负责接收客户端连接请求，不能收发消息，收发消息使用返回的新套接字来完成
    tcp_server_socket.listen(128)

    # 4. 等待接受客户端连接请求 socket.accept()
    # 只有客户端和服务端建立连接成功代码才会解阻塞，代码才能继续往下执行
    # 返回(socket object, address info)
    # socket object:专门和客户端通信的套接字,返回一个新的套接字目的是用于服务端程序可以服务于多个客户端
    # address info:(客户端IP,端口号)
    new_socket, ip = tcp_server_socket.accept()

    print('[服务端]已接受连接：', ip)

    # 5. 接受数据 socket.recv(buffersize)
    recv_data = new_socket.recv(1024)

    # 获取数据长度
    # 当客户端的套接字调用close后，服务器端的recv会解阻塞，返回的数据长度为0，服务端可以通过返回数据的长度来判断客户端是否已经下线，反之服务端关闭套接字，客户端的recv也会解阻塞，返回的数据长度也为0。
    # = 客户端close后，服务端接收到数据长度为0
    recv_date_len = len(recv_data)

    if recv_date_len == 0:

        print('[服务端]接受到的数据长度', recv_date_len)

        new_socket.close()

    else:
        recv_content = recv_data.decode('utf-8')
        print('[服务端端]接受到内容：', recv_content)

        # 6. 发送数据
        send_content = input('[服务端]请输入要发送的内容：')
        send_date = send_content.encode('utf-8')

        new_socket.send(send_date)

        # 7. 关闭套接字
        # 关闭服务于客户端的套接字，终止与客户端通信的服务
        new_socket.close()

    # 关闭服务端的套接字，终止和客户端提供建立连接请求的服务
    tcp_server_socket.close()

'''
小结:
    1. 创建服务端套接字
      （设置端口号复用）
    2. 绑定端口号
    3. 设置监听
    4. 等待客户端建立连接（服务器套接字变为被动套接字，只负责建立连接，返回专门和客户端通信的新套接字）
    5. 接收数据
    6. 发送数据
    7. 关闭通信套接字
    8. 关闭服务器套接字
'''