import socket
import os
PORT_NUMBER = 16384
def read_file(filename):
    try:
        with open(filename, 'r', encoding='utf-8') as file:
            return file.read()
    except FileNotFoundError:
        return ""
def get_request_target(request):
    try:
        lines = request.split("\r\n")
        first_line = lines[0]  # GET /path HTTP/1.1
        method, target, version = first_line.split()
        return target
    except ValueError:
        return "/"
def main():
    # 创建服务器套接字
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server_address = ('127.0.0.1', PORT_NUMBER)
    server_socket.bind(server_address)
    server_socket.listen(5)
    print(f"Server is listening on port {PORT_NUMBER}...")
    while True:
        try:
            # 接受连接
            client_socket, client_address = server_socket.accept()
            print(f"Connection accepted from {client_address}.")
            # 接收请求
            request = client_socket.recv(4096).decode('utf-8')
            if not request:
                client_socket.close()
                continue
            print(f"Received request:\n{request}")
            # 解析请求目标
            target = get_request_target(request)
            if target == "/":
                target = "/index.html"
            # 读取文件内容
            file_content = read_file("." + target)
            if not file_content:
                response = (
                    "HTTP/1.1 404 Not Found\r\n"
                    "Content-Type: text/html;charset=UTF-8\r\n\r\n"
                    "<html><body>404 Not Found</body></html>"
                )
                client_socket.sendall(response.encode('utf-8'))
                print("404 response sent successfully.")
            else:
                response = (
                    f"HTTP/1.1 200 OK\r\n"
                    f"Content-Type: text/html;charset=UTF-8\r\n"
                    f"Content-Length: {len(file_content)}\r\n\r\n"
                    f"{file_content}"
                )
                client_socket.sendall(response.encode('utf-8'))
                print("Data sent successfully.")
            client_socket.close()
        except KeyboardInterrupt:
            print("Server is shutting down...")
            break
        except Exception as e:
            print(f"Error occurred: {e}")
            client_socket.close()
    server_socket.close()
if __name__ == "__main__":
    main()