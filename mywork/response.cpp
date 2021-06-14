#include "response.hpp"

Response::Response(/* args */)
{
}

Response::Response (Response const & copy)
{
	*this = copy;
}

Response::~Response()
{
}

Response& Response::operator=(Response const & ope)
{
	if (this != &ope)
    {
        this->_status = ope._status;
		this->_body = ope._body;
        this->_headers = ope._headers;
    }
    return (*this);
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