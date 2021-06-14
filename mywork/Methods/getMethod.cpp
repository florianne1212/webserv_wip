#include "getMethod.hpp"

GetMethod::GetMethod(/* args */)
{
}

// GetMethod::GetMethod(GetMethod const & copy)
// {

// }

GetMethod::~GetMethod()
{
}

// GetMethod& GetMethod::operator=(GetMethod const & ope)
// {

// }

void GetMethod::handleGet(Client client, Request request, Response response)
{
	
    (void)client;
	// (void)response;
	(void)request;
	std::cout << "GET\n";

	File fileGet(request.getUrl());

	if (fileGet.isPresent()) {
		if (fileGet.isFile()) {
			std::cout << "it's a file\n";
			// response.setBody(open(file));
		} 
		else if (fileGet.isDirectory()) {
			std::cout << "it's a directory\n";
			// response.setBody(listFiles(file));
		}	
	}
	else
	{
		std::cout << "404 not found\n";
		response.setStatus(404);
	}
}