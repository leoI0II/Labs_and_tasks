#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<vector>
#include<string>
#include<cstring>
#include<unistd.h>

int main(){

    int _socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    sockaddr_in _sock_addr = {.sin_family = AF_INET, .sin_port = htons(12345),
                                .sin_addr{.s_addr = htonl(INADDR_LOOPBACK)}};

    // std::vector<char> buf(20);
    // std::string buf = "PING";
    char buf[] = "PING";
    char _buf[5];
    connect(_socket, (sockaddr*)&_sock_addr, sizeof(_sock_addr));
    send(_socket, buf, 5, MSG_NOSIGNAL);
    recv(_socket, _buf, 5, MSG_NOSIGNAL);
    shutdown(_socket, SHUT_RDWR);
    close(_socket);
    std::cout << _buf << std::endl;

    return 0;
}