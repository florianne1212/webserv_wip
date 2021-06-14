#include "deleteMethod.hpp"

DeleteMethod::DeleteMethod(/* args */)
{
}

DeleteMethod::~DeleteMethod()
{
}

void DeleteMethod::handleDelete(Client client, Request request, Response response)
{
	
    (void)client;
	// (void)response;
	(void)request;
	std::cout << "DELETE\n";

	File fileDelete(request.getUrl());
	

	if (fileDelete.isPresent()) {
		if(fileDelete.fileDelete())
			response.setStatus(200);
		else
			response.setStatus(204);
		
	}
	else
	{
		response.setStatus(204);
	}
	
	// 	if (fileGet.isFile()) {
	// 		response.setBody(open(file));
	// 	} 
	// 	else if (fileGet.isDirectory()) {
	// 		response.setBody(listFiles(file));
	// 	}	
	// }
	// else
	// 	
}