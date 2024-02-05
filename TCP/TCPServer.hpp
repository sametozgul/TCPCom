/*----------------------------------------------------------------------
    FILE        : TCPServer.hpp
    AUTHOR      : Samet ÖZGÜL, Tubitak
    LAST UPDATE : 05.02.2024

    Header file of TCPServer class for socket operations

    This file is responsible create a socket on specific hostname and port.
    All Rights Free
-----------------------------------------------------------------------*/

#ifndef TCPSERVER_HPP
#define TCPSERVER_HPP

#include <time.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <iostream>

#define ISVALIDSOCKET(s) ((s) >= 0)
#define CLOSESOCKET(s) close(s)
#define SOCKET int
#define GETSOCKETEXCEPTION() (errno)

class TCPServer
{
public:
    explicit TCPServer(const char* hostName, const int& port);
    SOCKET accept_socket();
    ~TCPServer();
private:
    const char *m_hostName;
    const int& m_port;
    SOCKET m_serverSocket;
};

#endif // TCPSERVER_HPP
