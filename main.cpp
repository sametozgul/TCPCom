#include <iostream>
#include "TCP/TCPServer.hpp"
#include "TCP/TCPSocket.hpp"
#include <iostream>
#include <thread>
#include <mutex>
#include <poll.h>
using namespace std;
int MAX_CLIENTS = 10;

void clientCreate(TCPSocket *socket){
    for(;;)
    {
        if(socket->detect(socket->getSocket())){
            break;
        }else{
            socket->send_msg("Hello from server \n",socket->getSocket());
        }
    }
    cout<<socket->getSocket()<<"th client is done\n";
    cout.flush();
}

int main()
{
    TCPServer *tcp_server = new TCPServer("127.0.0.1",8080);
    vector<thread> thread_vector(2);
    for(int i{0};i<2;++i){
        TCPSocket *tcp_socket = new TCPSocket(tcp_server->accept_socket());
        thread_vector[i] = thread(clientCreate,tcp_socket);
    }
    for (auto &t : thread_vector) {
        t.join();
    }
    return 0;
}
