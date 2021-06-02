#include "request.hpp"
#include <string>

std::vector<std::string> Request::createMethods()
{
	std::vector<std::string> authorized_methods;
	
	authorized_methods.push_back("GET");
	authorized_methods.push_back("POST");
	authorized_methods.push_back("DELETE");

	return(authorized_methods)
}


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

void Request::log()
{}

const std::string	Request::getMethods()
{
	return(this->_methods);
}

void	Request::setMethods(std::string str)
{
	this->_methods = str;
}