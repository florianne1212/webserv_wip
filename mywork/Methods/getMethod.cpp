#include "getMethod.hpp"

GetMethod::GetMethod(/* args */)
{
}

GetMethod::GetMethod(GetMethod const & copy)
{
	(void)copy;
}

GetMethod::~GetMethod()
{
}

GetMethod& GetMethod::operator=(GetMethod const & ope)
{
	(void)ope;
	return(*this);
}

void GetMethod::handleGet(Client &client, Request &request, Response &response)
{
	
    (void)client;
	// (void)response;
	(void)request;
	std::cout << "GET\n";

	File fileGet(request.getUrl());

	if (fileGet.isPresent()) {
		if (fileGet.isFile()) {
			std::cout << "it's a file\n";
			setHeader(response, fileGet);


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

void GetMethod::setHeader(Response &response, File &fileGet)
{
	std::string file_content(fileGet.find_content());
	response.setBody(file_content);

	std::string content_type = fileGet.find_content_type();
	if(!content_type.empty())
		response.setHeaders("Content-Type", fileGet.find_content_type());

	std::stringstream my_stream;
	my_stream << fileGet.fileLength();
	response.setHeaders("Content-Length", my_stream.str());

	
}