#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<vector>
#include<iterator>
#include<unistd.h>


int main()
{
    int master_socket = socket(
                                AF_INET /* IPv4 */,
                                SOCK_STREAM /* TCP */,
                                IPPROTO_TCP);

    sockaddr_in sock_addr;
                sock_addr.sin_family = AF_INET;
                sock_addr.sin_port = htons(12345);
                sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(master_socket, (sockaddr*)&sock_addr, sizeof(sock_addr));
    listen(master_socket, SOMAXCONN);

    while (true){
        int slave_socket = accept(master_socket, 0, 0);
        // int buffer[5];
        std::vector<char> buf(20);
        int check_how_many_bytes = recv(slave_socket, buf.data(), buf.size(), 0);          // removed MSG_NOSIGNAL
        send(slave_socket, buf.data(), buf.size(), 0);
        shutdown(slave_socket, SHUT_RDWR);
        close(slave_socket);
        //std::string str(std::begin(buffer), std::end(buffer));
        //std::cout << str << std::endl;
	    // printf("%s\n", buffer);
        std::cout << check_how_many_bytes << std::endl << buf.data() << std::endl;
    }



    return 0;
}
