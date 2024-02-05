#include <iostream>
#include "TCP/TCPServer.hpp"
#include "TCP/TCPSocket.hpp"
#include "File/File.hpp"
#include <iostream>
using namespace std;
int main()
{
        TCPServer *tcp_server = new TCPServer("127.0.0.1",8080);
        TCPSocket *tcp_socket = new TCPSocket(tcp_server->accept_socket());

        for(;;){

            string file_address = tcp_socket->read();
            try{
                if(file_address.size() > 0){
                    File *f = new File(file_address.c_str(),"r");
                    vector<char> data(30);
                    f->read(data);
                    delete f;
                    f = nullptr;
                    tcp_socket->send_msg(string{}.append(data.begin(),data.end()));
                }
            }catch(...){
                tcp_socket->send_msg(string{"The file format is invalid..."});
            }
        }
    return 0;
}

