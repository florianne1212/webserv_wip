#ifndef RESPONSE_HPP
#define RESPONSE_HPP

class Response
{
public:
	int _status;
	Headers _headers;
	std::string _body;

public:
	Response(/* args */);
	~Response();

	
};


#endif
