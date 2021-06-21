
#include "Parser/parseRequest.cpp"
#include "Parser/parseHeaderFields.cpp"
#include "request.hpp"
#include "response.hpp"
#include "Client.hpp"
#include "mime.hpp"
#include <fcntl.h>
#include <stdio.h>

#include <fcntl.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <list>
#include "middleware/IMiddleware.hpp"
#include "middleware/MiddlewareChain.hpp"
#include "middleware/MethodMiddleware.hpp"

int			main()
{

 
    ParseRequest _parserequest;
	ParseHeaderFields _parseheader;
	Request _request;
	const char *req = ""
		"DELETE /mydir.txt HTTP/1.1\r\n"
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
	_request.setMethods(_parserequest.get_method());
	_request.setUrl(_parserequest.get_path());
	_parseheader = _parserequest.get_parserfields();
	std::map<std::string, std::string>  mymap = _parseheader.get_headers_map();
	_request.setHeaders(mymap);

	// std::cout << "method = -" << _request.getMethods() << "-\npath = ";
	// std::cout << _request.getUrl() << "-\nmajor = ";
	// std::cout << _parserequest.get_major() << "-\nminor = ";
	// std::cout << _parserequest.get_minor() << "\n";
	// std::cout << _parseheader.get_field();
	
	std::map<std::string, std::string> reqmap = _request.getHeaders();


	Client client;
	Request &request = _request;
	Response response;

	std::list<IMiddleware *> middlewares;
	middlewares.push_back(new MethodMiddleware());

	MiddlewareChain chain(middlewares, client, request, response);
	chain();

	Mime my_mime;
	std::cout << my_mime.find_mime("mp4");
	

	// for (std::map<std::string, std::string>::iterator it=reqmap.begin(); it!=reqmap.end(); ++it)
    	// std::cout << it->first << " => " << it->second << '\n';

	
}