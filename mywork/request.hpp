#ifndef REQUEST_HPP
#define REQUEST_HPP
#include <string>

class request
{
private:
    std::string methods;
    std::string url;

public:
    request(/* args */);
    request (request const & copy);
    ~request();
    request& operator=(request const & ope);
};

//methods
//url
//headers
//page

#endif