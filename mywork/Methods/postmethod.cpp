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

	File filePost(request.getUrl());

	if (filePost.isPresent()) {
		response.setStatus(200);
	}
	else {
		filePost.fileCreate();
	}
		
}