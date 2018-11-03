#include "IO.h"

IO::_console& IO::_console::operator<< (const std::string& text)
{
    std::cout<<text;
    return *this;
};

IO::_console& IO::_console::operator>> (std::string& text)
{
    std::cin>>text;
    return *this;
};

IO::_basicOut& IO::_basicOut::operator<< (const std::string& text)
{
    std::cout<<text<<std::endl;
    return *this;
};

IO::_basicOut& IO::_basicOut::operator<< (const int& number)
{
    std::cout<<number<<std::endl;
    return *this;
};

IO::_basicOut& IO::_basicOut::operator<< (const double& number)
{
    std::cout<<number<<std::endl;
    return *this;
};

IO::_console IO::console;
IO::_basicOut IO::basicOut;
