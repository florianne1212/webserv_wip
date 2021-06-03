#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <string>

class Response
{
public:
	int _status;
	std::string _headers;
	std::string _body;

public:
	Response(/* args */);
	Response (Response const & copy);
	~Response();
	Response& operator=(Response const & ope);

	std::string getBody();
	int getStatus();

	void setBody(std::string str);
	void setStatus(int status);



	
};


#endif
