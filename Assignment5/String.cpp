#include <iostream>
#include <iomanip>
#include <cstring>
#include "String.h"

namespace StringNS{

String::String(const char * word)
{
    int length = 0;
    while(word[length] != '\n')
    {
        length++;
    }
    ptrChars = new (std::nothrow) char[length+1];
    for(i=1; i<=length; i++)
    {
        ptrChars[i] = word[i-1];
    }
    ptrChars[0] = (char)length;
}

String::String(const String & copiedString)
{
    int length = (int)copiedString.ptrChars[0];
    ptrChars = new (std::nothrow) char[length+1];
    for(i=0; i<=length; i++)
    {
        ptrChars[i] = copiedString.ptrChars[0];
    }
    ptrChars[0] = (char)length;
}

String::~String()
{

}

void String::getLength()
{

}

String & String::operator=(const String & right)
{

}

String String::operator+(const String & right)
{

}

String & String::operator++()
{

}

String String::operator++(const int)
{

}

String & String::operator!()
{

}

String & operator--()
{

}

String operator--(const int)
{

}

std::ostream & operator<<( std::ostream & sout, const String & right)
{

}

std::istream & operator>>( std::istream & sin, String & right)
{

}

String & operator<(const String & right)
{

}

String & operator>(const String & right)
{

}

String & operator==(const String & right)
{

}

} //namespace
