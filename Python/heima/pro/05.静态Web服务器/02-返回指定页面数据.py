import socket
import urllib.parse


def main():
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

        # 1. 获取用户请求资源的路径
        # 接收数据
        recv_client_date = new_socket.recv(4096)

        # 判断浏览器是否已关闭
        if len(recv_client_date) == 0:
            print('浏览器已关闭')
            new_socket.close()
            # 只有函数中可用return
            return

        # 解码
        recv_client_content = recv_client_date.decode('utf-8')
        print(recv_client_content)

        # 分割指定字符串,最大分割数为2
        request_list = recv_client_content.split(' ', maxsplit=2)
        # 获取请求资源路径
        request_path_url = request_list[1]
        # URL解码
        request_path = urllib.parse.unquote(request_path_url, 'utf-8')
        print(request_path)

        # 判断请求路径是否是根目录,如果是制定返回首页数据
        if request_path == '/':
            request_path = '/index.html'

        # 2. 根据请求资源的路径，读取指定文件的数据
        try:
            with open('static' + request_path, 'rb') as file:
                # 读取文件数据
                file_date = file.read()
        except Exception as e:
            # 3. 请求资源不存在，组装404状态的响应报文，发送给浏览器
            # 相应行
            response_line = 'HTTP/1.1 404 Not Found\r\n'
            # 响应头
            response_header = 'Server:ZYM1.0\r\n'
            with open('static/error.html', 'rb') as file:
                file_date = file.read()
            # 响应体
            response_body = file_date
            # 拼接响应报文
            response_date = (response_line + response_header + '\r\n').encode('utf-8') + response_body
            # 发送数据
            new_socket.send(response_date)
        else:
            # 4. 组装指定文件数据的响应报文，发送给浏览器
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
        finally:
            # 关闭通信套接字
            new_socket.close()


if __name__ == '__main__':
    main()
