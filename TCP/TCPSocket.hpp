#ifndef TCPSOCKET_HPP
#define TCPSOCKET_HPP

#include <time.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <string>

#include <vector>
#define ISVALIDSOCKET(s) ((s) >= 0)
#define CLOSESOCKET(s) close(s)
#define SOCKET int
#define GETSOCKETEXCEPTION() (errno)

const unsigned int MAX_BUF_LENGTH = 4096;

using namespace std;
class TCPSocket
{
public:
    explicit TCPSocket(SOCKET socket);
    string read();
    void send_msg(const string &msg);
private:
    SOCKET m_socket;

};

#endif // TCPSOCKET_HPP
