#include <iostream>
#include <WinSock2.h>
#include <windows.h>
#include <string.h>
using namespace std;
#pragma  comment(lib, "ws2_32.lib")	/*链接ws2_32.lib动态链接库*/
const int MAXSIZE = 1024;
 
int srvPort = 25;
char srvDomain[256] = "smtp.163.com";
char userName[256] = "18952976105@163.com"; //自己的邮箱名称
char password[256] = "19930714lyh"; //自己邮箱的密码
char targetEmail[256] = "it_is_just_a_test@126.com"; //要发送的邮件地址
char emailTitle[256] = "你好！我是李树花开！"; //邮件主题
char content[256] = "这是一封测试邮件！很高兴我的第一个邮件客户端制作成功了！";//邮件正文
 
SOCKET CreateConn(char* pWebsite,int port)
{
	//为建立socket对象做准备，初始化环境
	SOCKET sockClient = socket(AF_INET,SOCK_STREAM,0);     //建立socket对象
	SOCKADDR_IN addrSrv;   
	HOSTENT* pHostent;
    pHostent = gethostbyname(pWebsite);  //得到有关于域名的信息
    
	addrSrv.sin_addr.S_un.S_addr = *((DWORD *)pHostent->h_addr_list[0]);	//得到smtp服务器的网络字节序的ip地址   
	addrSrv.sin_family=AF_INET;   
	addrSrv.sin_port=htons(port);   
	int tf = connect(sockClient,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));   //向服务器发送请求  
	if(tf!=0)
	{
		return 0;
		//printf("链接失败\n");
	}
	return sockClient;
}
 
//int DoWhat是否接受数据
void SendAndRecvMsg(
					SOCKET sockClient,		//客户端的套接字
					char* pMessage,			//要发送的消息
					int Messagelen,			//消息的长度
					int DoWhat,				//造作的类型
					char* recvBuf,			//接收的缓冲区
					int recvBufLen			//缓冲区长度
					)
{
	char lpMessage[256] = {0};
	memcpy(lpMessage, pMessage, Messagelen);
	printf("\n\n%s \n", lpMessage);
	if (DoWhat == 0)
	{
		send(sockClient, lpMessage, Messagelen, 0);
		memset(recvBuf , 0, recvBufLen);
		DWORD num = recv(sockClient, recvBuf, recvBufLen, 0);     //接收数据
		printf("%s \n", recvBuf); 
		int i = 0;
		while(i != num)
		{
			printf("%02X ", recvBuf[i++]); 
			if((i)%16 == 0)
			{
				printf("\n"); 
			}
		}
		printf("\n");
		
	}
	else if (DoWhat == 1)
	{
		send(sockClient, lpMessage, Messagelen, 0);
		
	}
	else if (DoWhat == 2) //仅仅是接收数据
	{
		memset(recvBuf, 0, recvBufLen);
		DWORD num=recv(sockClient,recvBuf,recvBufLen,0);     //接收数据
		cout << recvBuf << endl;
		int i = 0;
		while(i < num)
		{
			printf("%02X ", (byte)recvBuf[i++]); 
			if((i)%16 == 0)
			{
				printf("\n"); 
			}
		}
		printf("\n");
	}
	
}
 
int GetStrLen(char* pString) //得到字符串的长度
{
	int i = 0;
	while(pString[i++] != 0);
	return i-1;
}
 
 
void StringToBase64(const char *src,char *dst)
{/*将字符串变为base64编码*/
    int i = 0;
    char *p = dst;
    int d= strlen(src) - 3;
	static const char Base64[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    //for(i=0;i<strlen(src)-3;i+=3) ;if (strlen(src)-3)<0 there is a buf
	
    for(i=0;i<=d;i+=3)
    {
        *p++ = Base64[((*(src + i)) >> 2) & 0x3f];
        *p++ = Base64[(((*(src + i)) & 0x3) << 4) + ((*(src + i + 1)) >> 4)];
        *p++ = Base64[((*(src + i + 1) & 0xf) << 2) + ((*(src + i + 2)) >> 6)];
        *p++ = Base64[(*(src + i + 2)) & 0x3f];
    }
    if((strlen(src) - i) == 1)
    {
        *p++ = Base64[((*(src + i)) >> 2) & 0x3f];
        *p++ = Base64[((*(src + i)) & 0x3) << 4];
        *p++ = '=';
        *p++ = '=';
    }
    if((strlen(src) - i) == 2)
    {
        *p++ = Base64[((*(src + i)) >> 2) & 0x3f];
        *p++ = Base64[(((*(src + i)) & 0x3) << 4) + ((*(src + i + 1)) >> 4)];
        *p++ = Base64[((*(src + i + 1) & 0xf) << 2)];
        *p++ = '=';
    }
    *p = '\0';
}
 
 
bool FormatEmail(char* pFrom, char* pTo, char* pSubject, char* pMessage, char* Email)
{/*格式化要发送的内容*/
	lstrcat(Email, "From: ");
	lstrcat(Email, pFrom);
	lstrcat(Email, "\r\n");
	
	lstrcat(Email, "To: ");
	lstrcat(Email, pTo);
	lstrcat(Email, "\r\n");
	
	lstrcat(Email, "Subject: ");
	lstrcat(Email, pSubject);
	lstrcat(Email, "\r\n");
	
	lstrcat(Email, "MIME-Version: 1.0");
	lstrcat(Email, "\r\n");
	lstrcat(Email, "\r\n");
	
	lstrcat(Email, pMessage);
	
	lstrcat(Email, "\r\n.\r\n");
	return TRUE;
}
 
void main()
{
	
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	
	wVersionRequested = MAKEWORD(2, 1);
	err = WSAStartup(wVersionRequested, &wsaData);
	SOCKET sockClient = CreateConn(srvDomain, srvPort); //网易smtp邮箱，25号端口
 
	char buff[MAXSIZE];
    memset(buff, 0, sizeof(char) * MAXSIZE);  //清零
 
	SendAndRecvMsg(sockClient, 0, 0, 2, buff, MAXSIZE);  //接收数据
	
	char UserNameToSendEmail[256] = {0};
	sprintf(UserNameToSendEmail, "EHLO %s", "it_is_just_a_test@163.com");
	lstrcat(UserNameToSendEmail, "\r\n\0");
	SendAndRecvMsg(sockClient, UserNameToSendEmail, GetStrLen(UserNameToSendEmail), 0, buff, MAXSIZE); //既接收也发送
 
    SendAndRecvMsg(sockClient, "AUTH LOGIN\r\n", strlen("AUTH LOGIN\r\n"), 0, buff, MAXSIZE); //请求登陆
    char pUerName[256] = {0};
	//strstr函数搜索一个字符串在另一个字符串中的第一次出现，并返回第一次出现位置的指针
 
	DWORD p = strstr(userName,"@") - userName; 
	memcpy(pUerName, userName, p); //得到用户名,如从"13203200199@163.com"得到"13203200199"
    char base[256];
    StringToBase64(pUerName, base); //得到用户名的base64编码
 
	char str[MAXSIZE];
	memset(str, 0, MAXSIZE);
	sprintf(str, "%s\r\n", base/*"MTMyMDMyMDAxOTk="*/);
	SendAndRecvMsg(sockClient, str, lstrlen(str), 0, buff, MAXSIZE); //发送用户名，并接收服务器的返回
 
	StringToBase64(password, base);
	memset(str, 0, 1024);
	sprintf(str, "%s\r\n", base);
	SendAndRecvMsg(sockClient, str, lstrlen(str),0, buff, MAXSIZE); //发送用户密码，并接收服务器的返回
 
	char MailFrom[256] = {0};
	sprintf(MailFrom, "MAIL FROM: <%s>\r\n", userName);
	
	SendAndRecvMsg(sockClient, MailFrom, lstrlen(MailFrom), 0, buff, MAXSIZE);
	
	char RcptTo[256] = {0};
	sprintf(RcptTo, "RCPT TO: <%s>\r\n", targetEmail);
	SendAndRecvMsg(sockClient, RcptTo, lstrlen(RcptTo), 0, buff, MAXSIZE);
 
	SendAndRecvMsg(sockClient, "DATA\r\n", lstrlen("DATA\r\n"), 0, buff, MAXSIZE);
 
	char Email[1024] = {0};
	FormatEmail(userName, targetEmail, emailTitle, content, Email);
	
	SendAndRecvMsg(sockClient,Email,lstrlen(Email), 0, buff, MAXSIZE);
	
	SendAndRecvMsg(sockClient,"QUIT\r\n", lstrlen("QUIT\r\n"), 0, buff, MAXSIZE);
 
    closesocket(sockClient);   
	WSACleanup();
}