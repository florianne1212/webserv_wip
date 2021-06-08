#include "gnl.hpp"
#include "parseRequest.hpp"
#include <fcntl.h>
#include <stdio.h>

#include <fcntl.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Message.hpp"

int			main()
{

 
    ParseRequest _parserequest;
	ParseHeaderFields _parseheader;
	Message _message;
	const char *req = ""
		"GET /index.html HTTP/1.1\r\n"
		"Host: localhost:8080\r\n"
		"User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:89.0) Gecko/20100101 Firefox/89.0\r\n"
		"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\n"
		"Accept-Language: fr,fr-FR;q=0.8,en-US;q=0.5,en;q=0.3\r\n"
		"Accept-Encoding: gzip, deflate\r\n\r\n";

	std::string line = req;


	for (size_t i = 0; i < line.length(); i++)
	{
		char c = line[i];
		_parserequest.parse(c);

     
	}   
	// std::cout << "method = -" << _parserequest.get_method() << "-\npath = ";
	// std::cout << _parserequest.get_path() << "-\nmajor = ";
	// std::cout << _parserequest.get_major() << "-\nminor = ";
	// std::cout << _parserequest.get_minor();
	// std::cout << _parseheader.get_field();
	_parseheader = _parserequest.get_parserfields();
	std::map<std::string, std::string>  mymap = _parseheader.get_headers_map();

	for (std::map<std::string, std::string>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    	std::cout << it->first << " => " << it->second << '\n';

	
}