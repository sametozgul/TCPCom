#include "File.hpp"

std::function<void(FILE *)> File::m_delete = [](auto f) {std::fclose(f);cout<<"File is closed..."<<std::endl;};

File::File()
{

}

File::File(const char *path, const char *mode)
{
    m_file = std::unique_ptr<FILE, decltype(m_delete)>{std::fopen(path, mode), m_delete};
    if (!m_file)
        throw std::invalid_argument{"Can not open file!..."};
}

void File::read(vector<char> &buffer)
{
    std::fread(&buffer[0], 1, buffer.size(), m_file.get());
}

ostream &operator<<(ostream &os, const string& data){
    os << data;
    return os;
}
istream &operator>>(istream &is, string data){
    is >> data;
    return is;
}
