#ifndefine STRING_H
#define STRING_H

namespace StringNS{

#include <iostream>

class String{
    friend String & operator--();
    friend String operator--(const int);
    friend std::ostream & operator<<( std::ostream &, const String & );
    friend std::istream & operator>>( std::istream &, String & );
    friend String & operator<( const String & );
    friend String & operator>( const String & );
    friend String & operator==( const String & );
public:
    explicit String(const char * = "");
    String(const String &);
    ~String();
    void getLength();
    String & operator=( const String & );
    String operator+( const String & );
    String & operator++();
    String operator++( const int );
    String & operator!();
private:
    void destroy();
    char * ptrChars;
};
}
#endif // STRING_H
