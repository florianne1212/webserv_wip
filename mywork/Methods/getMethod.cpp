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
			std::string file_content(fileGet.find_content());
			// std::cout << "my content  = \n" << file_content;
			response.setBody(file_content);
			// response.setContent
		} 
		else if (fileGet.isDirectory()) {
			std::list<std::string> files_list = fileGet.listDirFiles();

			for (std::list<std::string>::iterator it=files_list.begin(); it != files_list.end(); ++it)
   				std::cout << "file =" << *it << '\n';
			// response.setBody(listFiles(file));
		}	
	}
	else
	{
		std::cout << "404 not found\n";
		response.setStatus(404);
	}
}