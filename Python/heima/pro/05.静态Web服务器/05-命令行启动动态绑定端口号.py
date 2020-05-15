import sys
import socket
import threading
import urllib.parse


# 把提供服务的Web服务器抽象成一个类
class HTTPWebServer(object):
    # 3. 给Web服务器类的初始化方法添加一个端口号参数，用于绑定端口号
    def __init__(self, port):
        """初始化（创建、设置套接字）"""
        # 创建服务端套接字
        tcp_server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        # 设置端口号服用
        tcp_server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)
        # 绑定端口号
        tcp_server_socket.bind(('', port))
        # 设置监听
        tcp_server_socket.listen(128)
        # 保存创建成功的套接字
        self.tcp_server_socket = tcp_server_socket

    @staticmethod
    def handle_client_request(new_socket0):
        """处理客户端请求"""
        # 接收数据
        recv_client_date = new_socket0.recv(4096)
        # 解码
        recv_client_content = recv_client_date.decode('utf-8')
        print(recv_client_content)

        # -----------------返回指定页面数据-------------------
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
        try:
            with open('static' + request_path, 'rb') as file:
                # 读取文件数据
                file_date = file.read()
        except Exception as e:
            # 请求资源内部存在，返回404数据
            # 相应行
            response_line = 'static/1.1 404 Not Found\r\n'
            # 响应头
            response_header = 'Server:ZYM1.0\r\n'
            with open('static/error.html', 'rb') as file:
                file_date = file.read()
            # 响应体
            response_body = file_date
            # 拼接响应报文
            response_date = (response_line + response_header + '\r\n').encode('utf-8') + response_body
            # 发送数据
            new_socket0.send(response_date)
        else:
            # 响应行
            response_line = 'HTTP/1.1 200 OK\r\n'
            # 响应头
            response_header = 'Server:ZYM1.0\r\n'
            # 响应体
            response_body = file_date
            # 拼接响应报文
            response_date = (response_line + response_header + '\r\n').encode('utf-8') + response_body
            # 发送数据
            new_socket0.send(response_date)
        finally:
            # 关闭通信套接字
            new_socket0.close()

    def start(self):
        """启动Web服务器进行工作，处理客户端请求操作"""
        while True:
            # 等待接收客户端连接
            new_socket, ip = self.tcp_server_socket.accept()
            print('[服务端]已建立连接', ip)

            # 当客户端和服务器建立连接时，创建子线程
            sub_thread = threading.Thread(target=self.handle_client_request, args=(new_socket,))
            # 设置守护主线程
            sub_thread.setDaemon(True)
            # 驱动子线程执行对应的任务
            sub_thread.start()


def main():
    """程序入口函数"""

    # 1. 获取执行Python程序的终端命令行参数
    # 获取程序启动终端命令行参数
    # 返回列表，列表里面就是python解释器执行程序所需要的参数
    # python3 [xxx.py 9090]
    print(sys.argv)
    # 2. 判断参数的类型，设置端口号必须是整型
    # 判断命令行参数是否等于2
    if len(sys.argv) != 2:
        print('爬爬爬')
        return

    # 判断字符串是否都是由数字组成
    if not sys.argv[1].isdigit():
        print('爬爬爬')
        return

    # 获取终端命令行参数
    port = int(sys.argv[1])
    # 创建web服务器对象
    web_server = HTTPWebServer(port)
    # 启动web服务器进行工作
    web_server.start()


if __name__ == '__main__':
    main()
