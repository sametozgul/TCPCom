#include "TCPSocket.hpp"

TCPSocket::TCPSocket(int socket):m_socket{socket}
{

}

void TCPSocket::read()
{
    char buffer[1024];
    int bytes = recv(m_socket,buffer,1024,0);
    if(bytes < 0){
        cout<<"Received is failed..."<<endl;
    }
    cout<<"Received message is :";
    for(int i{0};i<bytes;++i){
        cout<<buffer[i];
    }
}

void TCPSocket::send_msg(string &msg)
{
    send(m_socket, msg.c_str(), msg.length(), 0);
}
