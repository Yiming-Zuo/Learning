import socket

if __name__ == '__main__':
    # 1. 编写TCP服务端程序
    # 创建服务端套接字
    tcp_server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # 设置端口号服用
    tcp_server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)
    # 绑定端口号
    tcp_server_socket.bind(('', 8080))
    # 设置监听
    tcp_server_socket.listen(128)

    while True:
        # 等待接收客户端连接
        new_socket, ip = tcp_server_socket.accept()
        print('[服务端]已建立连接', ip)

        # 2. 获取浏览器发送的http请求报文信息
        # 接收数据
        recv_client_date = new_socket.recv(4096)
        # 解码
        recv_client_content = recv_client_date.decode('utf-8')
        print(recv_client_content)

        # 3. 读取固定页面，把页面数据组装成HTTP响应报文数据发送给浏览器
        with open('../static/index.html', 'rb') as file:
            # 读取文件数据
            file_date = file.read()

        # 组装HTTP响应报文数据
        # 响应行
        response_line = 'HTTP/1.1 200 OK\r\n'
        # 响应头
        response_header = 'Server:ZYM1.0\r\n'
        # 响应体
        response_body = file_date
        # 拼接响应报文
        response_date = (response_line + response_header + '\r\n').encode('utf-8') + response_body
        # 发送数据
        new_socket.send(response_date)

        # 4. 关闭通信套接字
        new_socket.close()
