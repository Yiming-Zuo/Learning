# HTTP请求报文
## HTTP GET 请求原始报文

```python
----请求行----
GET / HTTP/1.1\r\n  # GET请求方式 请求资源路径 HTTP协议版本
----请求头----
Host: www.baidu.com\r\n  # 请求服务器的主机地址和端口，端口默认80
Connection: keep-alive\r\n  # 和服务器保持长连接
Cache-Control: max-age=0\r\n  # 不缓存
Upgrade-Insecure-Requests: 1\r\n  # 让浏览器升级不安全请求，使用https请求
User-Agent: Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/76.0.3809.132 Mobile Safari/537.36\r\n  # 用户代理：客户端名称
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3/r/n  # 可接受的数据类型
Accept-Encoding: gzip, deflate, br\r\n  # 支持的压缩算法
Accept-Language: zh-CN,zh;q=0.9\r\n  # 支持的语言
Cookie: BAIDUID=0DBD2CAB28A98697FB38048ECCF68BEE:FG=1; PSTM=1568482404;\r\n  # 用户的登陆标识
----空行----
\r\n
```

## HTTP POST 请求原始报文

```python
----请求行----
POST /xmweb?host=mail.itcast.cn&_t=1542884567319 HTTP/1.1\r\n  # 请求方式 请求资源路径 HTTP协议版本
----请求头----
Host: mail.itcast.cn\r\n
Connection: keep-alive\r\n
Content-Type: application/x-www-form-urlencoded\r\n  # 请求的数据类型
User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3497.100 Safari/537.36\r\n
----空行----
\r\n
----请求体----
username=hello&pass=hello
```

# HTTP响应报文
## 原始报文

```python
----响应行----
HTTP/1.1 200 OK\r\n  # HTTP协议版本 状态码 状态描述
----响应头----
Server: Tengine\r\n  # 服务器名称 
Content-Type: text/html; charset=UTF-8\r\n  # 内容类型和编码格式
Transfer-Encoding: chunked\r\n  # 发送给客户端的数据不确定长度，结束的标记是0\r\n
# 或者Content-Length: 100字节  # 发送给客户端的数据的大小
Connection: keep-alive\r\n  
Date: Fri, 23 Nov 2018 02:01:05 GMT\r\n  # 服务器的响应时间
Content-Language: zh-CN  # 内容语言
Content-Encoding: gzio # 内容压缩算法
----空行----
\r\n
----响应体----
<!DOCTYPE html><html lang=“en”> …</html>  # 响应给客户端的数据
```

## HTTP状态码
| 状态码| 说明 |
| --- | --- |
| 200 | 请求成功 |
| 307 | 重定向 |
| 400 | 错误请求，请求地址或参数有误 |
| 404 | 请求资源在服务器不存在 |
| 500 | 服务器内部源代码出现错误 |


