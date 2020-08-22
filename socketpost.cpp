#include<iostream>
#include<WinSock2.h>
#include<cstring>

using namespace std;
int main() {
    WORD wVersionRequest = MAKEWORD(2, 2);
    WSADATA wsa;
    if (WSAStartup(wVersionRequest, &wsa) != 0) {
        cout << "初始化套接字库失败" << endl;
        return 0;
    }
    SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);
    SOCKADDR_IN addrsrv;
    addrsrv.sin_addr.S_un.S_addr = inet_addr("111.202.114.53");
    addrsrv.sin_family = AF_INET;
    addrsrv.sin_port = htons(80);
    char httpPostRequest[1024] = "POST http://api.fanyi.baidu.com/api/trans/vip/translate HTTP/1.1\r\n"
                                "Host: api.fanyi.baidu.com\r\n"
                                "Accept: */*\r\n"
                                "Connection: Keep-Alive\r\n"
                                "Content-Type: application/x-www-form-urlencoded;\r\n"
                                "Content-Length: 98\r\n"
                                "\r\n"
                                "q=apple&from=en&to=zh&appid=2015063000000001&salt=1435660288&sign=f89f9594663708c1605f3d736d01d2d4\r\n";
    if (connect(sockClient, (sockaddr*)&addrsrv, sizeof(sockaddr)) < 0) {
        cout << "Connect failed" << endl;
        return 0;
    }
    send(sockClient, httpPostRequest, strlen(httpPostRequest), 0);
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    int recvLen = recv(sockClient, buf, 1024, 0);
    if (recvLen > 0) cout << buf << endl;
    else cout << "No data recived" << endl;
    closesocket(sockClient);
    WSACleanup();
}
