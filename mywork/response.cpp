#include "response.hpp"

Response::Response(/* args */)
{
}

Response::~Response()
{
}

std::string Response::getBody()
{
    return(this->_body);
}

int Response::getStatus()
{
    return(this->_status);
}

void Response::setBody(std::string str)
{
    this->_body=str;
}

void Response::setStatus(int status)
{
    this->_status=status;
}