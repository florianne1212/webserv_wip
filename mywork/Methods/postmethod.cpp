#include "postMethod.hpp"

PostMethod::PostMethod(/* args */)
{
}

PostMethod::~PostMethod()
{
}

void PostMethod::handlePost(Client client, Request request, Response response)
{
	
    (void)client;
	(void)response;
	(void)request;
	std::cout << "POST\n";

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