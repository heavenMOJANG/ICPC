#include <iostream>
#include <string>
#include <WinSock2.h> //适用平台 Windows
using namespace std;
#pragma comment(lib, "ws2_32.lib") /*链接ws2_32.lib动态链接库*/

using namespace std;

// base64 加密函数
string base64(string str)   //base64加密算法
{
    string base64_table="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int str_len = str.length();
    string res="";
    for (int strp=0; strp<str_len/3*3; strp+=3)
    {
        res+=base64_table[str[strp]>>2];
        res+=base64_table[(str[strp]&0x3)<<4 | (str[strp+1])>>4];
        res+=base64_table[(str[strp+1]&0xf)<<2 | (str[strp+2])>>6];
        res+=base64_table[(str[strp+2])&0x3f];
        //cout<<res<<endl;
    }
    if (str_len%3==1)
    {
        int pos=str_len/3 * 3;
        res += base64_table[str[pos]>>2];
        res += base64_table[(str[pos]&0x3)<<4];
        res += "=";
        res += "=";
    }
    else if (str_len%3==2)
    {
        int pos=str_len/3 * 3;
        res += base64_table[str[pos]>>2];
        res += base64_table[(str[pos]&0x3)<<4 | (str[pos+1])>>4];
        res += base64_table[(str[pos+1]&0xf)<<2];
        res += "=";
    }
    return res;
}

int main()
{
    char buff[500]; //recv函数返回的结果
    string message;
    string info;
    string subject;
    // telnet smtp.qq.com
    WSADATA wsaData;
    WORD wVersionRequested = MAKEWORD(2, 1); //版本2.1
    int err = WSAStartup(wVersionRequested, &wsaData);
    // cout << "WSAStartup:" << err << endl;
    SOCKET sockClient;
    sockClient = socket(AF_INET, SOCK_STREAM, 0);
    HOSTENT* pHostent;//主机的名称，地址信息等
    while(1)
    {
        pHostent = gethostbyname("smtp.163.com"); //得到有关于域名的信息,链接到qq邮箱服务器
        SOCKADDR_IN addrServer; //服务端地址
        addrServer.sin_addr.S_un.S_addr = *((DWORD *)pHostent->h_addr_list[0]); //得到smtp服务器的网络字节序的ip地址
        addrServer.sin_family = AF_INET;
        addrServer.sin_port = htons(25); //连接端口25
        err = connect(sockClient, (SOCKADDR*)&addrServer, sizeof(SOCKADDR)); //向服务器发送请求
        //cout << "connect:" << err << endl;
        buff[recv(sockClient, buff, 500, 0)] = '\0';
        // cout << "connect:" << buff << endl;
        // message = "ehlo qq.com\r\n";
        message = "ehlo hello\r\n";  // 先打个招呼
        send(sockClient, message.c_str(), message.length(), 0); //发送ehlo命令
        buff[recv(sockClient, buff, 500, 0)] = '\0';   //接收返回值
        // cout << "helo:" << buff << endl;     //输出返回值
        message = "auth login\r\n";
        send(sockClient, message.c_str(), message.length(), 0);
        buff[recv(sockClient, buff, 500, 0)] = '\0';
        //cout << "auth login:" << buff << endl;
        /*
        发送base64加密的用户名、密码
        */
        string Smail = “18952976105@163.com”;
        string name = Smail.substr(0,Smail.find("@"));
        //  cout<<name<<endl;
        message = base64(name) + "\r\n"; //base64 编码的用户名
        send(sockClient, message.c_str(), message.length(), 0);
        buff[recv(sockClient, buff, 500, 0)] = '\0';
        //cout << "usrname:" << buff << endl;
        string Swd;
        cout << "请输入您的授权码：";
        cin>>Swd;
        message = base64(Swd) + "\r\n";//base64 编码的密码
        send(sockClient, message.c_str(), message.length(), 0);
        buff[recv(sockClient, buff, 500, 0)] = '\0';
        cout << "password:" << buff << endl;

        string Rmail;
        cout << "输入收件人邮箱：";
        cin >> Rmail;
        message = "mail from:<"+Smail+">\r\n";
        // message = "MAIL FROM:<XXX@qq.com> \r\nRCPT TO:<XXX@163.com> \r\n";


        send(sockClient, message.c_str(), message.length(), 0);
        buff[recv(sockClient, buff, 500, 0)] = '\0';

        message = "rcpt to:<";

        message.append(Rmail);
        message.append(">\r\n");
        //cout << "message=" << message;

        send(sockClient, message.c_str(), message.length(), 0);

        buff[recv(sockClient, buff, 500, 0)] = '\0';

        message = "DATA\r\n";
        send(sockClient, message.c_str(), message.length(), 0);
        buff[recv(sockClient, buff, 500, 0)] = '\0';
        message = "From: "+Smail+"\r\nTo: "+Rmail+"\r\nsubject:";
        cout<<"主题：";
        cin>>subject;
        message.append(subject);
        message.append("\r\n\r\n");
        cout<<"内容：";
        cin>>info;
        message.append(info);
        message.append("\r\n.\r\n");

        send(sockClient, message.c_str(), message.length(), 0);
        buff[recv(sockClient, buff, 500, 0)] = '\0';
        cout<<" 发送成功!"<<endl;
        cout<<buff;
        message = "QUIT\r\n";
        send(sockClient, message.c_str(), message.length(), 0);
        buff[recv(sockClient, buff, 500, 0)] = '\0';
        break;
    }
    // cout << "QUIT:" << buff << endl;
    system("pause");
}
