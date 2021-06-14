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
	(void)response;
	(void)request;
	std::cout << "GET\n";

		// if (fileGet.isPresent()) {
	// 	if (fileGet.isFile()) {
	// 		response.setBody(open(file));
	// 	} 
	// 	else if (fileGet.isDirectory()) {
	// 		response.setBody(listFiles(file));
	// 	}	
	// }
	// else
	// 	response.setStatus(404);
}