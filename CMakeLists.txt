cmake_minimum_required(VERSION 3.5)

project(TCPComApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TCPComApp main.cpp
    TCP/TCPServer.hpp
    TCP/TCPServer.cpp
    TCP/TCPSocket.hpp
    TCP/TCPSocket.cpp

    File/File.hpp
    File/File.cpp
)

install(TARGETS TCPComApp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
