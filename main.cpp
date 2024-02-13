#include <iostream>
#include "TCP/TCPServer.hpp"
#include "TCP/TCPSocket.hpp"
#include <iostream>
#include <thread>
#include <mutex>
#include <poll.h>

using namespace std;
int MAX_CLIENTS = 10;
vector<std::pair<thread,int>> client_p;

void clientCreate(TCPSocket *socket){
    for(;;)
    {
        if(socket->detect(socket->getSocket())){
            break;
        }else{
            for(const auto& el:client_p){
                if(el.second != socket->getSocket()) socket->send_msg(string{"The message is send from client"+ to_string(el.second) + " .\n"},el.second);
            }
        }
    }
    cout<<socket->getSocket()<<"th client is done\n";
    cout.flush();
}

int main()
{
    TCPServer *tcp_server = new TCPServer("127.0.0.1",8080);

    for(int i{0};i<2;++i){
        TCPSocket *tcp_socket = new TCPSocket(tcp_server->accept_socket());
        client_p.push_back(std::make_pair(thread(clientCreate,tcp_socket),tcp_socket->getSocket()));
    }
    cout<<"Halooo\n";
    for (auto &t : client_p) {
        t.first.join();
    }
    return 0;
}
