#include <iostream>
#include "MethodMiddleware.hpp"
#include "../request.hpp"
#include "../response.hpp"
#include "MiddlewareChain.hpp"
#include "File.hpp"

MethodMiddleware::~MethodMiddleware() {
}

void MethodMiddleware::handle(Client &client, Request &request, Response &response, MiddlewareChain &next) {
	
	File fileGet(request.getUrl());

	if (fileGet.isPresent()) {
		if (fileGet.isFile()) {
			response.setBody(open(file));
		} 
		else if (fileGet.isDirectory()) {
			response.setBody(listFiles(file));
		}	
	}
	else
		response.setStatus(404);

	std::cout << request.getUrl() << std::endl;

	next();
}