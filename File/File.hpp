/*----------------------------------------------------------------------
    FILE        : File.hpp
    AUTHOR      : Samet ÖZGÜL, Tubitak
    LAST UPDATE : 05.02.2024

    Header file of File class for file operations


    All Rights Free
-----------------------------------------------------------------------*/
#ifndef FILE_HPP
#define FILE_HPP


#include <vector>
#include <string>
#include <ostream>
#include <iostream>
#include <functional>
#include <memory>
using namespace std;
class File
{
public:
    File();
    File(const char* path, const char* mode);
    friend ostream &operator<<(ostream &os, const string& data);
    friend istream &operator>>(istream &is, string data);

    void read(vector<char> &buffer);
private:
    std::unique_ptr<FILE, std::function<void(FILE *)>> m_file;
    static function<void(FILE*)> m_delete;

};

#endif // FILE_HPP
