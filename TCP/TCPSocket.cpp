#include "TCPSocket.hpp"

TCPSocket::TCPSocket(int socket):m_socket{socket}
{

}

string TCPSocket::read()
{
    vector<char> buffer(MAX_BUF_LENGTH);
    string received_data;
    int bytes = recv(m_socket, &buffer[0], buffer.size(), 0);
    if(bytes < 0){
        cout<<"Received is failed..."<<endl;
    }
    auto newlinePos = std::find(buffer.begin(), buffer.end(), '\n');
    received_data.append(buffer.begin(),newlinePos);
    return received_data;
}

void TCPSocket::send_msg(const string &msg, SOCKET socket)
{
    send(socket, msg.c_str(), msg.length(), 0);
    cout<<"message is sent...\n";
    cout.flush();
}

bool TCPSocket::detect(int socket)
{
    char buffer[80];
    if(recv(socket,buffer,sizeof(buffer),0)==0){
        printf(" Connection closed\n");
        return true;
    }
    return false;
}

int TCPSocket::getSocket()
{
    return m_socket;
}
