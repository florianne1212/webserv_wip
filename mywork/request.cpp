#include "request.hpp"
#include <string>

// std::vector<std::string> Request::createMethods()
// {
// 	std::vector<std::string> authorized_methods;
	
// 	authorized_methods.push_back("GET");
// 	authorized_methods.push_back("POST");
// 	authorized_methods.push_back("DELETE");

// 	return(authorized_methods)
// }


Request::Request(/* args */)
{
}

Request::Request(Request const & copy)
{

}

Request::~Request()
{
}

Request& Request::operator=(Request const & ope)
{
    
}

std::string	Request::getMethods()
{
	return(this->_methods);
}


std::string	Request::getUrl()
{
	return(this->_url);
}

std::string	Request::getVersion()
{
	return(this->_version);
}

void	Request::setMethods(std::string str)
{
	this->_methods = str;
}

void	Request::setUrl(std::string str)
{
	this->_url = str;
}

void	Request::setVersion(std::string str)
{
	this->_version = str;
}