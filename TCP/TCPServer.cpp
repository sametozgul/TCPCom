#include "TCPServer.hpp"


using namespace std;
TCPServer::TCPServer(const char *hostName, const int &port):m_hostName{hostName},m_port{port}
{
    cout<<"TCP server is configuring..."<<endl;
    struct addrinfo serverInfo;

    // serverInfo is set to zero
    memset(&serverInfo,0,sizeof(serverInfo));
    serverInfo.ai_family = AF_INET;
    serverInfo.ai_socktype = SOCK_STREAM;
    serverInfo.ai_flags = AI_PASSIVE;

    // server_addr get address information from server_Info
    struct addrinfo *server_addr;
    getaddrinfo(m_hostName,to_string(m_port).c_str(),&serverInfo,&server_addr);

    // creating socket
    SOCKET server_socket = socket(server_addr->ai_family, server_addr->ai_socktype, server_addr->ai_protocol);

    if(!ISVALIDSOCKET(server_socket))
        throw std::invalid_argument{"The TCP socket was not created..."};

    // server is binding
    cout<<"TCP server is trying to binding to: "<<server_addr->ai_addr<<endl;
    if(bind(server_socket,server_addr->ai_addr,server_addr->ai_addrlen)){
        throw std::invalid_argument{"The server cannot bind...!..."};
    }

    if(listen(server_socket,10) < 0){
        throw std::invalid_argument{"The server cannot listen..."};
    }else
    {
        cout<<"TCP server is listening"<<endl;
    }

    delete server_addr;

    m_serverSocket = server_socket;
}

int TCPServer::accept_socket()
{
    struct sockaddr_storage client_addr;
    socklen_t client_len = sizeof(client_addr);
    cout<<"TCP server is ready to accept"<<endl;
    int socket_client = accept(m_serverSocket,(struct sockaddr*)&client_addr,&client_len);
    if(!ISVALIDSOCKET(socket_client)){
        cout<<stderr<<" accept is failed..."<<endl;
    }
    cout<<"TCP server accept..."<<endl;
    return socket_client;
}

TCPServer::~TCPServer()
{
    delete m_hostName;
    m_hostName = nullptr;
}
