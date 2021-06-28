#include "parseBody.hpp"


ParseBody::ParseBody()
{
}

ParseBody::ParseBody(std::string Body):
_Body(Body)
{
}

ParseBody::ParseBody(ParseBody const & copy)
{
	*this = copy;
}

ParseBody::~ParseBody()
{
}

ParseBody& ParseBody::operator=(ParseBody const & ope)
{
	if (this != &ope)
    {
        this->_Body = ope._Body;
        this->_state = ope._state;
    }
    return (*this);
    
}

void ParseBody::parse_chunked(char c)
{
	std::cout << "\n TUU \n";
	while (_Body.find("\r\n") == std::string::npos)
	{
		_Body.push_back(c); 
	}
	std::cout << _Body;
	if (_Body.find("\r\n") != std::string::npos)
		_state = S_END;
}

void ParseBody::parse_identity(char c)
{
	std::cout << "\n TOO \n";
	while (_Body.find("\r\n") == std::string::npos)
	{
		_Body.push_back(c);
		std::cout << _Body; 
	}
	
	if (_Body.find("\r\n") != std::string::npos)
		_state = S_END;
}

void ParseBody::parse(char c, std::map<std::string, std::string> _headers)
{
	std::cout << "\n COUCOU \n";
	if(_headers.find("Transfer-Encoding") != _headers.end() && _headers.find("Transfer-Encoding")->second == "chunked")
		parse_chunked(c);
	else if(_headers.find("Transfer-Encoding") != _headers.end() && _headers.find("Transfer-Encoding")->second == "identity")
		parse_identity(c);
	else if(_headers.find("Content-Length") == _headers.end()) 
		parse_identity(c);
	else if(_headers.find("Content-Length") != _headers.end()) 
		parse_identity(c);
	else
		_state = S_END;
	// std::cout << _headers.find("Content-Length")->first;
}
