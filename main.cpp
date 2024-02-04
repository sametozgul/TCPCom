#include <iostream>

using namespace std;
#include "TCP/TCPServer.hpp"
#include "TCP/TCPSocket.hpp"
int main()
{

    TCPServer *server = new TCPServer{"127.0.0.1",8080};
    for(;;){
        TCPSocket *socket = new TCPSocket{server->accept_socket()};
        socket->read();
        string msg{"Message is OK..."};
        socket->send_msg(msg);
        delete socket;
        socket = nullptr;
    }

    delete server;
    server = nullptr;

    return 0;
}
