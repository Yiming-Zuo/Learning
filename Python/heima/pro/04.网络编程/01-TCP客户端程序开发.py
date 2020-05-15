import socket


if __name__ == '__main__':
    # 1. 创建tcp客户端套接字对象 socket.socket(AddressFamily,Type)
    # AddressFamilyL:IP地址类型
    # Type:传输协议类型
    tcp_client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # socket对象方法：.connect((host,port)) .send() .recv() .close()
    # 2. 和服务端套接字建立链接 scoket.connect((host,port))
    tcp_client_socket.connect(('192.168.66.101', 8080))

    while True:
        # 准备发送的数据
        send_content = input('[客户端]请输入你要发送的内容：')
        # 将字符串编码为二进制 str.encode(编码格式)
        send_date = send_content.encode('utf-8')

        if send_date:
            # 3. 发送数据 socket.send(date)
            # date：二进制数据
            tcp_client_socket.send(send_date)

            # 4. 接收数据 socker.recv(buffersize)
            # buffersize:每次接受数据的最大字节数
            recv_date = tcp_client_socket.recv(1024)

            # 把接收到的二进制解码成字符串 date.decode(编码格式)
            # 对解码不成功的数据进行忽略，保证程序不崩溃
            recv_content = recv_date.decode('utf-8', errors='ignore')
            print('[客户端]接受到内容：', recv_content)

        else:
            print('[客户端]已断开连接')
            break

    # 5. 关闭客户端套接字
    tcp_client_socket.close()

'''
小结：
    1. 创建客户端套接字
    2. 与服务端建立连接
    3. 发送数据
    4. 接收数据
    5. 关闭套接字
'''