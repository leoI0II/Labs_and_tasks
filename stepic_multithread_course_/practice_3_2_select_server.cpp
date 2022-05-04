#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<fcntl.h>
#include<set>
#include<algorithm>

int set_nonblock_socket(int file_decriptor){
    int flags;
#ifdef O_NONBLOCK
    if (-1 == (flags = fcntl(file_decriptor, F_GETFL, 0)))
        flags = 0;
    return fcntl(file_decriptor, F_SETFL, flags | O_NONBLOCK);
#else
    flags = 1;
    return ioctl(file_decriptor, F_IOBIO, &flags);
#endif
}

int main(int argc, char** argv){

    int master_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    std::set<int> slave_sockets;
    sockaddr_in sock_addr = {.sin_family = AF_INET, .sin_port = htons(12345), .sin_addr{.s_addr = htonl(INADDR_ANY)}};
    bind(master_socket, (sockaddr*)&sock_addr, sizeof(sock_addr));

    set_nonblock_socket(master_socket);

    listen(master_socket, SOMAXCONN);
    while(true){
        // 1024 bytes
        fd_set set;
        
        // zero bytes set
        FD_ZERO(&set);

        // add master socket in set
        FD_SET(master_socket, &set);
        for (auto iter = slave_sockets.begin(); iter != slave_sockets.end(); ++iter){
            // add all sockets in set
            FD_SET(*iter, &set);
        }

        // have to find max index in set
        int max_ind = std::max(master_socket, *std::max_element(slave_sockets.begin(), slave_sockets.end()));

        // listening set
        select(max_ind + 1, &set, NULL, NULL, NULL);

        for (auto iter = slave_sockets.begin(); iter != slave_sockets.end(); ++iter){
            
            // check if slave socket worked... (1)
            if (FD_ISSET(*iter, &set)){
                static char buffer[1024];
                int recv_size = recv(*iter, buffer, 1024, MSG_NOSIGNAL);

                // if recv_size == 0 -> error or close connection
                if (recv_size == 0 && errno != EAGAIN){
                    shutdown(*iter, SHUT_RDWR);
                    close(*iter);
                    iter = slave_sockets.erase(iter);
                    --iter;                             // edit: check if the last elem in set
                                                        // SIGSEGV problen
                }
                else if (recv_size != 0){
                    send(*iter, buffer, recv_size, MSG_NOSIGNAL);
                }
            }
        }
        if (FD_ISSET(master_socket, &set)){
            int slave_socket = accept(master_socket, 0, 0);
            set_nonblock_socket(slave_socket);
            slave_sockets.insert(slave_socket);
        }
    }

    return 0;
}