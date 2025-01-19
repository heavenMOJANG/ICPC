#include <iostream>
#include <fstream>
#include <sstream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <vector>
#pragma comment(lib, "ws2_32.lib")
constexpr int PORT_NUMBER = 16384;
void init() {
    WORD w_req = MAKEWORD(2, 2);
    WSADATA wsadata;
    int err = WSAStartup(w_req, &wsadata);
    if (err != 0) {
        std::cerr << "初始化失败。\r\n" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2) {
        std::cerr << "套接字版本不匹配。\r\n" << std::endl;
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    std::cout << "初始化成功。\r\n套接字版本匹配成功。\r\n" << std::endl;
}

std::string read_file(const std::string & filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    return buffer.str();
}

std::string get_request_target(const std::string & request) {
    std::istringstream iss(request);
    std::string method, target, version;
    iss >> method >> target >> version;
    return target;
}

int main() {
    SOCKET s_server, s_accept;
    SOCKADDR_IN server_addr, accept_addr;
    int len = sizeof(SOCKADDR);

    init();

    // 创建服务器端套接字
    s_server = socket(AF_INET, SOCK_STREAM, 0);
    if (s_server == INVALID_SOCKET) {
        std::cerr << "套接字创建失败。\r\n" << std::endl;
        WSACleanup();
        return -1;
    }

    // 绑定套接字
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); 
    server_addr.sin_port = htons(16384);
    if (bind(s_server, (SOCKADDR *) & server_addr, sizeof(SOCKADDR)) == SOCKET_ERROR) {
        std::cerr << "套接字绑定失败。\r\n" << std::endl;
        closesocket(s_server);
        WSACleanup();
        return -1;
    }

    // 监听
    if (listen(s_server, SOMAXCONN) < 0) {
        std::cerr << "监听状态设置失败。\r\n" << std::endl;
        closesocket(s_server);
        WSACleanup();
        return -1;
    }

    std::cout << "服务端正在监听端口" << PORT_NUMBER << "..." << std::endl;

    // 接受连接
    s_accept = accept(s_server, (SOCKADDR * ) &accept_addr, &len);
    if (s_accept == SOCKET_ERROR) {
        std::cerr << "接受连接失败。\r\n" << std::endl;
        closesocket(s_server);
        WSACleanup();
        return -1;
    }

    std::cout << "连接成功。\r\n" << std::endl;

    // 接收请求
    char request_buffer[4096];
    int bytes_received = recv(s_accept, request_buffer, sizeof(request_buffer), 0);
    if (bytes_received < 0) {
        std::cerr << "Receiving request failed!" << std::endl;
        closesocket(s_accept);
        closesocket(s_server);
        WSACleanup();
        return -1;
    }
    request_buffer[bytes_received] = '\0';
    std::string request(request_buffer);

    std::cout << "Received request:\n" << request << std::endl;

    // 解析请求目标
    std::string target = get_request_target(request);
    if (target.empty()) {
        target = "/index.html";
    }

    // 读取文件内容
    std::string file_content = read_file("." + target);
    if (file_content.empty()) {
        const char* response = "HTTP/1.1 200 OK\r\nContent-Type: text/html;charset=UTF-8\r\n\r\n<html><body>404 Not Found</body></html>";
        if (send(s_accept, response, strlen(response), 0) < 0) {
            std::cerr << "Sending 404 response failed!" << std::endl;
        } else {
            std::cout << "404 response sent successfully." << std::endl;
        }
    } else {
        std::string response = "HTTP/1.1 200 OK\r\nContent-Type: text/html;charset=UTF-8\r\nContent-Length: " + std::to_string(file_content.length()) + "\r\n\r\n" + file_content;
        if (send(s_accept, response.c_str(), response.length(), 0) < 0) {
            std::cerr << "Sending data failed!" << std::endl;
        } else {
            std::cout << "Data sent successfully." << std::endl;
        }
    }

    // 清理资源
    closesocket(s_accept);
    closesocket(s_server);
    WSACleanup();
    return 0;
}